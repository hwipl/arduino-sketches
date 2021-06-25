/* pin definitions */
#define SWITCH 2
#define LED_GREEN 3
#define LED_RED1 4
#define LED_RED2 5

// next red to enable and disable
int next_red_on = LED_RED1;
int next_red_off = LED_RED2;

/* setup */
void setup() {
	pinMode(LED_GREEN, OUTPUT);
	pinMode(LED_RED1, OUTPUT);
	pinMode(LED_RED2, OUTPUT);
	pinMode(SWITCH, INPUT);
}

/* main loop */
void loop() {
	/* currently active red */
	int current_red_on = next_red_on;

	if (digitalRead(SWITCH) == LOW) {
		/* enable green, disable others */
		digitalWrite(LED_GREEN, HIGH);
		digitalWrite(LED_RED1, LOW);
		digitalWrite(LED_RED2, LOW);

		/* reset red blinking rotation */
		next_red_on = LED_RED1;
		next_red_off = LED_RED2;
	} else {
		/* disable green */
		digitalWrite(LED_GREEN, LOW);

		/* rotate blinking reds */
		digitalWrite(next_red_on, HIGH);
		digitalWrite(next_red_off, LOW);
		next_red_on = next_red_off;
		next_red_off = current_red_on;
		delay(250);
	}
}
