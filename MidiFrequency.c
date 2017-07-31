// calculate the frequency of a given midi note.

#include <stdio.h>
#include <math.h>

int main()
{
    double semitone_ratio;
    double c0; // for frequency of midi note 0.
    double c5; // for frequency of middle C.
    double frequency; //the result of the program.
    int midinote; //the midi note we want the frequency of.

    //CALCULATE REQUIRED VALUES.

    /*To raise something a semitone do the semitone ratio to the power of the
      number of semitones you are raising by.*/
    semitone_ratio = pow(2.0, 1.0/12.0); //Approx 1.0594631.

    /*Find middle C, this is 3 semitones above low A which is 220Hz.
      This is a nice round figure to use to find middle C.*/
    c5 = 220.0 * pow(semitone_ratio, 3.0);

    /*MIDI note 0 is C which is 5 octave below middle C. Since we know Middle C
    this can easily be found. 0.5 is an octave fall in terms of a power. So
    0.5^5 is a fall of 5 octaves.*/
    c0 = c5 * pow(0.5, 5.0);
    
    while(1)
    {
	printf("Please enter the MIDI note you want the frequency of: ");
	scanf("%d", &midinote);
	
	if (midinote > 127 || midinote < 0)
	{
	    printf("\nPlease eneter a value between 0-127.\n\n");
	}
	else break;
    }

    /*so at the end of it all this calculation equates to:
    The frequency of midi note 0 * semitone_ratio^the midi note
    we want the frequency of.*/

    /*Ultimately:
	eg. 73
	8.1757989 * 1.0594631 ^ 73 = 554.365
    */
    frequency = c0 * pow(semitone_ratio, midinote);

    printf("MIDI note %d has the frequency %f\n", midinote, frequency);

    return 0;
}
