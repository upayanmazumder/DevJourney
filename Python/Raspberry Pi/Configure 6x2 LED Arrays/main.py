import RPi.GPIO as GPIO
import time
import os

# Define GPIO pins in rows
PIN_CONFIG = {
    1: {'left': 11, 'right': 12},  # GPIO17, GPIO18
    2: {'left': 13, 'right': 16},  # GPIO27, GPIO23
    3: {'left': 15, 'right': 18},  # GPIO22, GPIO24
    4: {'left': 19, 'right': 22},  # GPIO10, GPIO25
    5: {'left': 21, 'right': 24},  # GPIO9, GPIO8
    6: {'left': 23, 'right': 26}   # GPIO11, GPIO7
}

# Setup
GPIO.setmode(GPIO.BOARD)
for row in PIN_CONFIG.values():
    GPIO.setup(row['left'], GPIO.OUT)
    GPIO.setup(row['right'], GPIO.OUT)

# Initialize states
row_states = {row: 'left' for row in PIN_CONFIG}

def clear_screen():
    os.system('cls' if os.name == 'nt' else 'clear')

def display_grid():
    clear_screen()
    print("  Left Right")
    for row in range(1, 7):
        left_symbol = 'O' if row_states[row] == 'left' else ' '
        right_symbol = 'O' if row_states[row] == 'right' else ' '
        print(f"{row}: [{left_symbol}]  [{right_symbol}]")
    print("\nEnter row number to toggle (1-6), or 'q' to quit:")

def toggle_row(row):
    if row_states[row] == 'left':
        row_states[row] = 'right'
        GPIO.output(PIN_CONFIG[row]['left'], GPIO.LOW)
        GPIO.output(PIN_CONFIG[row]['right'], GPIO.HIGH)
    else:
        row_states[row] = 'left'
        GPIO.output(PIN_CONFIG[row]['left'], GPIO.HIGH)
        GPIO.output(PIN_CONFIG[row]['right'], GPIO.LOW)

def main():
    while True:
        display_grid()
        user_input = input().lower()
        
        if user_input == 'q':
            break
        
        try:
            row = int(user_input)
            if 1 <= row <= 6:
                toggle_row(row)
            else:
                print("Invalid row number. Please enter a number between 1 and 6.")
                time.sleep(1)
        except ValueError:
            print("Invalid input. Please enter a number between 1 and 6 or 'q' to quit.")
            time.sleep(1)

    print("Exiting program...")
    GPIO.cleanup()

if __name__ == "__main__":
    try:
        main()
    except KeyboardInterrupt:
        print("\nProgram interrupted.")
    finally:
        GPIO.cleanup()
        print("GPIO cleaned up. Goodbye!")
