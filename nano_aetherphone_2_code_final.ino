//code for Nano Aetherphone 2 - MIDI controller
//by "Chi ha ucciso Il Conte?" aka Nicolò Merendino
//Released under MIT license

// library needed:
// newping - https://bitbucket.org/teckel12/arduino-new-ping/downloads/
// MIDI - https://github.com/FortySevenEffects/arduino_midi_library
// This machine kills fascists

#include <NewPing.h>
#include <MIDI.h>
#define TRIGGER_PIN  2  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     4  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 60 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.

const int LED_PIN = 10;
const int ldrPin = A0;

int ldrStatus;
int sensorLow = 30;
int sensorHigh = 900;
int distanza = 0;

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.


const int DEFAULT_MIDI_CHANNEL = 1;
MIDI_CREATE_DEFAULT_INSTANCE();

int note1 = 0;
int note2 = 0;
int note3 = 0;
int note4 = 0;
int note5 = 0;
int note6 = 0;
int note7 = 0;
int note8 = 0;
int note9 = 0;
int note10 = 0;
int note11 = 0;
int note12 = 0;

void setup() {

  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, HIGH);

  while (millis() < 5000)
  {
    ldrStatus = analogRead(A0);
    if (ldrStatus > sensorHigh)
    {
      sensorHigh = ldrStatus;
    }
    if (ldrStatus < sensorLow)
    {
      sensorLow = ldrStatus;
    }
  }

  digitalWrite(LED_PIN, LOW);

  pinMode(ldrPin, INPUT);
  MIDI.begin(MIDI_CHANNEL_OMNI);

  Serial.begin(31250);
  pinMode( LED_PIN, OUTPUT );

}

void loop() {
  int distanza = 0;
  int ldrStatus = analogRead(ldrPin);
  distanza = sonar.ping_cm();
  int led_light = map (distanza, 0, MAX_DISTANCE, 0, 255);
  int ldr_value = map(ldrStatus, sensorLow, sensorHigh, 0, 127);
  int mc = 0;

  if (distanza > 1 && distanza < (MAX_DISTANCE / 12) * 1 ) {
    // if note not playing


    if (note1 == 0) {
      // play note (note number, velocity, channel)
      // more info: http://arduinomidilib.sourceforge.net/a00001.html
      // MIDI notes chart http://www.phys.unsw.edu.au/jw/notes.html
      // 55 = G3, 127 = trigger note with max volume

      MIDI.sendNoteOn(43, 127, DEFAULT_MIDI_CHANNEL);
      // note is playing
      note1 = 1;
    }
    // when button released
  } else {


    // if note playing
    if (note1 == 1) {
      // if playing - stop

      MIDI.sendNoteOff(43, 0, DEFAULT_MIDI_CHANNEL);
    }
    // if button released note is off
    note1 = 0;

  }

  if (distanza > (MAX_DISTANCE / 12) * 1 && distanza < (MAX_DISTANCE / 12) * 2) {


    // if note not playing
    if (note2 == 0) {


      MIDI.sendNoteOn(44, 127, DEFAULT_MIDI_CHANNEL);
      // note is playing
      note2 = 1;
    }
    // when button released
  } else {
    // if note playing
    if (note2 == 1) {
      // if playing - stop

      MIDI.sendNoteOff(44, 0, DEFAULT_MIDI_CHANNEL);
    }
    // if button released note is off
    note2 = 0;

  }

  if  (distanza > (MAX_DISTANCE / 12) * 2 && distanza < (MAX_DISTANCE / 12) * 3) {
    // if note not playing
    if (note3 == 0) {

      MIDI.sendNoteOn(45, 127, DEFAULT_MIDI_CHANNEL);
      // note is playing
      note3 = 1;
    }
    // when button released
  } else {
    // if note playing
    if (note3 == 1) {
      // if playing - stop
      MIDI.sendNoteOff(45, 0, DEFAULT_MIDI_CHANNEL);
    }
    // if button released note is off
    note3 = 0;
  }

  if (distanza > (MAX_DISTANCE / 12) * 3 && distanza < (MAX_DISTANCE / 12) * 4) {
    // if note not playing
    if (note4 == 0) {

      MIDI.sendNoteOn(46, 127, DEFAULT_MIDI_CHANNEL);
      // note is playing
      note4 = 1;
    }
    // when button released
  } else {
    // if note playing
    if (note4 == 1) {
      // if playing - stop
      MIDI.sendNoteOff(46, 0, DEFAULT_MIDI_CHANNEL);
    }
    // if button released note is off
    note4 = 0;
  }

  if (distanza > (MAX_DISTANCE / 12) * 4 && distanza < (MAX_DISTANCE / 12) * 5) {
    // if note not playing
    if (note5 == 0) {

      MIDI.sendNoteOn(47, 127, DEFAULT_MIDI_CHANNEL);
      // note is playing
      note5 = 1;
    }
    // when button released
  } else {
    // if note playing
    if (note5 == 1) {
      // if playing - stop
      MIDI.sendNoteOff(47, 0, DEFAULT_MIDI_CHANNEL);
    }
    // if button released note is off
    note5 = 0;
  }

  if (distanza > (MAX_DISTANCE / 12) * 5 && distanza < (MAX_DISTANCE / 12) * 6) {
    // if note not playing
    if (note6 == 0) {

      MIDI.sendNoteOn(48, 127, DEFAULT_MIDI_CHANNEL);
      // note is playing
      note6 = 1;
    }
    // when button released
  } else {
    // if note playing
    if (note6 == 1) {
      // if playing - stop
      MIDI.sendNoteOff(48, 0, DEFAULT_MIDI_CHANNEL);
    }
    // if button released note is off
    note6 = 0;
  }

  if (distanza > (MAX_DISTANCE / 12) * 6 && distanza < (MAX_DISTANCE / 12) * 7) {
    // if note not playing
    if (note7 == 0) {

      MIDI.sendNoteOn(49, 127, DEFAULT_MIDI_CHANNEL);
      // note is playing
      note7 = 1;
    }
    // when button released
  } else {
    // if note playing
    if (note7 == 1) {
      // if playing - stop
      MIDI.sendNoteOff(49, 0, DEFAULT_MIDI_CHANNEL);
    }
    // if button released note is off
    note7 = 0;
  }


  if (distanza > (MAX_DISTANCE / 12) * 7 && distanza < (MAX_DISTANCE / 12) * 8) {
    // if note not playing
    if (note8 == 0) {

      MIDI.sendNoteOn(50, 127, DEFAULT_MIDI_CHANNEL);
      // note is playing
      note8 = 1;
    }
    // when button released
  } else {
    // if note playing
    if (note8 == 1) {
      // if playing - stop
      MIDI.sendNoteOff(50, 0, DEFAULT_MIDI_CHANNEL);
    }
    // if button released note is off
    note8 = 0;
  }


  if (distanza > (MAX_DISTANCE / 12) * 8 && distanza < (MAX_DISTANCE / 12) * 9) {
    // if note not playing
    if (note9 == 0) {

      MIDI.sendNoteOn(51, 127, DEFAULT_MIDI_CHANNEL);
      // note is playing
      note9 = 1;
    }
    // when button released
  } else {
    // if note playing
    if (note9 == 1) {
      // if playing - stop
      MIDI.sendNoteOff(51, 0, DEFAULT_MIDI_CHANNEL);
    }
    // if button released note is off
    note9 = 0;
  }

  if (distanza > (MAX_DISTANCE / 12) * 9 && distanza < (MAX_DISTANCE / 12) * 10) {
    // if note not playing
    if (note10 == 0) {

      MIDI.sendNoteOn(52, 127, DEFAULT_MIDI_CHANNEL);
      // note is playing
      note10 = 1;
    }
    // when button released
  } else {
    // if note playing
    if (note10 == 1) {
      // if playing - stop
      MIDI.sendNoteOff(52, 0, DEFAULT_MIDI_CHANNEL);
    }
    // if button released note is off
    note10 = 0;
  }

  if (distanza > (MAX_DISTANCE / 12) * 10 && distanza < (MAX_DISTANCE / 12) * 11) {
    // if note not playing
    if (note11 == 0) {

      MIDI.sendNoteOn(53, 127, DEFAULT_MIDI_CHANNEL);
      // note is playing
      note11 = 1;
    }
    // when button released
  } else {
    // if note playing
    if (note11 == 1) {
      // if playing - stop
      MIDI.sendNoteOff(53, 0, DEFAULT_MIDI_CHANNEL);
    }
    // if button released note is off
    note11 = 0;
  }

  if (distanza > (MAX_DISTANCE / 12) * 11 && distanza < (MAX_DISTANCE / 12) * 12) {
    // if note not playing
    if (note12 == 0) {

      MIDI.sendNoteOn(54, 127, DEFAULT_MIDI_CHANNEL);
      // note is playing
      note12 = 1;
    }
    // when button released
  } else {
    // if note playing
    if (note12 == 1) {
      // if playing - stop
      MIDI.sendNoteOff(54, 0, DEFAULT_MIDI_CHANNEL);
    }
    // if button release100d note is off
    note12 = 0;
  }




  if (ldr_value > 60) {

    mc = ldr_value;

    if (mc < 80)
    {
      mc = 0;
    }

    MIDI.sendControlChange(3, mc, DEFAULT_MIDI_CHANNEL);
  }


  analogWrite( LED_PIN, led_light );

  delay (5);
}
