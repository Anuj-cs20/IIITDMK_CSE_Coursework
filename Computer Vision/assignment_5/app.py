from flask import render_template, Flask, request
import cv2
import numpy as np
import os

app = Flask(__name__)

# Set up the base directory for image uploads
BASE_DIR = os.path.dirname(os.path.abspath(__file__))
IMAGE_DIR = os.path.join(BASE_DIR, "images")

@app.route('/', methods=['GET'])
def home():
    return render_template('basic.html')

@app.route('/', methods=['POST'])
def prediction():
    image_file = request.files['image_file']
    image_path = os.path.join(IMAGE_DIR, image_file.filename)
    image_file.save(image_path)
    
    # Ensure the output directory exists
    if not os.path.exists(IMAGE_DIR):
        os.makedirs(IMAGE_DIR)

    output_path = os.path.join(IMAGE_DIR, 'bokeh_effect_image.jpg')
    apply_bokeh_effect(image_path, output_path)
    
    # Generate the relative path for HTML to use
    image_url = os.path.join('images', 'bokeh_effect_image.jpg')
    return render_template('basic.html', image=image_url)


def apply_bokeh_effect(person_image_path, output_path):
    person_img = cv2.imread(person_image_path)

    # Create a mask of the same size as the person image
    mask = np.zeros(person_img.shape[:2], np.uint8)

    # Create foreground and background models
    bgd_model = np.zeros((1, 65), np.float64)
    fgd_model = np.zeros((1, 65), np.float64)

    # Define a rectangle around the object (person) to help GrabCut segment the image
    rect = (50, 50, person_img.shape[1]-50, person_img.shape[0]-50)

    # Apply GrabCut algorithm
    cv2.grabCut(person_img, mask, rect, bgd_model, fgd_model, 5, cv2.GC_INIT_WITH_RECT)

    # Modify mask to create a binary mask for the foreground
    mask2 = np.where((mask == 2) | (mask == 0), 0, 1).astype('uint8')

    # Extract the foreground (subject) from the person image
    person_foreground = person_img * mask2[:, :, np.newaxis]

    # Blur the entire image
    blurred_image = cv2.GaussianBlur(person_img, (21, 21), 0)

    # Set the foreground part of the blurred image to zeros
    blurred_background = blurred_image * (1 - mask2[:, :, np.newaxis])

    # Add the original, unblurred foreground to the blurred background
    combined_img = blurred_background + person_foreground

    # Write the output image
    cv2.imwrite(output_path, combined_img)

if __name__=='__main__':
    app.run(debug=True)