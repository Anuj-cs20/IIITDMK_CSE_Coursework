# CS20B1100
# K.Anuj

import cv2
import numpy as np


def combine_images(person_image_path, historical_image_path, output_path, scale_factor=0.5):
    person_img = cv2.imread(person_image_path)
    historical_img = cv2.imread(historical_image_path)

    # Resize the historical image to match the size of the person image
    historical_img = cv2.resize(
        historical_img, (person_img.shape[1], person_img.shape[0]))

    # Create a mask of the same size as the person image
    mask = np.zeros(person_img.shape[:2], np.uint8)

    # Create foreground and background models
    bgd_model = np.zeros((1, 65), np.float64)
    fgd_model = np.zeros((1, 65), np.float64)

    # Define a rectangle around the object (person) to help GrabCut segment the image
    rect = (50, 50, person_img.shape[1]-50, person_img.shape[0]-50)

    # Apply GrabCut algorithm
    cv2.grabCut(person_img, mask, rect, bgd_model,
                fgd_model, 5, cv2.GC_INIT_WITH_RECT)

    # Modify mask to create a binary mask for the foreground
    mask2 = np.where((mask == 2) | (mask == 0), 0, 1).astype('uint8')

    # Extract the person from the person image
    person_foreground = person_img * mask2[:, :, np.newaxis]

    # Resize the foreground
    person_foreground = cv2.resize(person_foreground, (int(
        person_img.shape[1] * scale_factor), int(person_img.shape[0] * scale_factor)))
    mask2 = cv2.resize(mask2, (int(
        person_img.shape[1] * scale_factor), int(person_img.shape[0] * scale_factor)))

    # Calculate the starting y-coordinate to place the foreground at the bottom
    start_y = historical_img.shape[0] - person_foreground.shape[0]

    # Place the resized foreground at the bottom of the background
    historical_img[start_y:start_y+person_foreground.shape[0], :person_foreground.shape[1]] = person_foreground * mask2[:, :, np.newaxis] + \
        historical_img[start_y:start_y+person_foreground.shape[0],
                       :person_foreground.shape[1]] * (1 - mask2[:, :, np.newaxis])

    cv2.imwrite(output_path, historical_img)


combine_images('person_image.png', 'historical_place.jpg',
               'combined_image.jpg', 0.5)
