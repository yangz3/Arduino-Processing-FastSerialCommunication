import processing.core.PApplet;
import processing.serial.Serial;

public class Main extends PApplet {

	Serial myPort; // The serial port
	boolean firstContact = false; // Whether we've heard from the
	// microcontroller
	int[] serialInArray = new int[3]; // Where we'll put what we receive
	int serialCount = 0; // A count of how many bytes we receive

	public void setup() {
		strokeWeight(1);
		myPort = new Serial(this, Serial.list()[7], 9600);

	}

	public void draw() {
		background(0);
	}

	public void serialEvent(Serial myPort) {
		// read a byte from the serial port:
		int inByte = myPort.read();
		// if this is the first byte received, and it's an A,
		// clear the serial buffer and note that you've
		// had first contact from the microcontroller.
		// Otherwise, add the incoming byte to the array:
		if (firstContact == false) {
			if (inByte == 'A') {
				myPort.clear(); // clear the serial port buffer
				firstContact = true; // you've had first contact from the
										// microcontroller
				myPort.write('A'); // ask for more
			}
		} else {
			// Add the latest byte from the serial port to array:
			serialInArray[serialCount] = inByte;
			serialCount++;
			// If we have 3 bytes:
			if (serialCount > 2) {
				int a = serialInArray[0];
				int b = serialInArray[1];
				int c = serialInArray[2];
				// print the values (for debugging purposes only):
				println(a + "\t" + b + "\t" + c);
				// Send a capital A to request new sensor readings:
				myPort.write('A');
				// Reset serialCount:
				serialCount = 0;
			}
		}
	}

}
