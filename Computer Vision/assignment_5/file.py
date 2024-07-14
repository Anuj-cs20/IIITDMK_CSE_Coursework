import cv2
import mediapipe as mp

# Initialize mediapipe hands module
mp_hands = mp.solutions.hands
hands = mp_hands.Hands()

# Open a connection to the webcam (change 0 to the appropriate camera index if needed)
cap = cv2.VideoCapture(0)

# Define key regions based on a standard QWERTY keyboard layout (adjust these based on your specific needs)
key_regions = {
    "1": (0, 0, 80, 80),
    "2": (80, 0, 160, 80),
    "3": (160, 0, 240, 80),
    "4": (240, 0, 320, 80),
    "5": (320, 0, 400, 80),
    "6": (400, 0, 480, 80),
    "7": (480, 0, 560, 80),
    "8": (560, 0, 640, 80),
    "9": (640, 0, 720, 80),
    "0": (720, 0, 800, 80),
    "Q": (0, 80, 80, 160),
    "W": (80, 80, 160, 160),
    "E": (160, 80, 240, 160),
    "R": (240, 80, 320, 160),
    "T": (320, 80, 400, 160),
    "Y": (400, 80, 480, 160),
    "U": (480, 80, 560, 160),
    "I": (560, 80, 640, 160),
    "O": (640, 80, 720, 160),
    "P": (720, 80, 800, 160),
    "A": (0, 160, 80, 240),
    "S": (80, 160, 160, 240),
    "D": (160, 160, 240, 240),
    "F": (240, 160, 320, 240),
    "G": (320, 160, 400, 240),
    "H": (400, 160, 480, 240),
    "J": (480, 160, 560, 240),
    "K": (560, 160, 640, 240),
    "L": (640, 160, 720, 240),
    "Z": (80, 240, 160, 320),
    "X": (160, 240, 240, 320),
    "C": (240, 240, 320, 320),
    "V": (320, 240, 400, 320),
    "B": (400, 240, 480, 320),
    "N": (480, 240, 560, 320),
    "M": (560, 240, 640, 320),
    "Space": (240, 320, 560, 400),  # Example for the space bar
}

while cap.isOpened():
    # Read a frame from the webcam
    ret, frame = cap.read()
    if not ret:
        break

    # Convert the frame to RGB
    frame_rgb = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)

    # Use mediapipe to process the frame and detect hands
    results = hands.process(frame_rgb)

    # Check if hands are detected
    if results.multi_hand_landmarks:
        for hand_landmarks in results.multi_hand_landmarks:
            # Get the landmark coordinates for the index finger
            index_finger_landmarks = hand_landmarks.landmark[mp_hands.HandLandmark.INDEX_FINGER_TIP]

            # Convert normalized coordinates to image coordinates
            height, width, _ = frame.shape
            cx, cy = int(index_finger_landmarks.x * width), int(index_finger_landmarks.y * height)

            # Draw a circle at the tip of the index finger
            cv2.circle(frame, (cx, cy), 10, (0, 255, 0), cv2.FILLED)

            # Determine the key based on finger position
            pressed_key = None
            for key, region in key_regions.items():
                x1, y1, x2, y2 = region
                if x1 <= cx <= x2 and y1 <= cy <= y2:
                    pressed_key = key
                    break

            # Display the pressed key on the frame
            cv2.putText(frame, f"Pressed Key: {pressed_key}", (10, 30), cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 255, 0), 2)

    # Display the frame
    cv2.imshow('Hand Tracking', frame)

    # Break the loop when the 'q' key is pressed
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

# Release the webcam and close all windows
cap.release()
cv2.destroyAllWindows()
