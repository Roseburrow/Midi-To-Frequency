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

    //This number comes from the fact that to raise something a semitone you
    //must multiply it by this ratio. (I think.)
    semitone_ratio = pow(2, 1/12.0); //Approx 1.0594631.

    /*Find middle C, this is 3 semitones above low A which is 220Hz.
    EDIT: To elaborate this means find the frequency of middle C. The to the
    of 3 part is becuase we are using a starting base of frequency^3.*/
    c5 = 220.0 * pow(semitone_ratio, 3);

    /*MIDI note 0 is C which is 5 octave below middle C. We need this frequency
    as well to know the starting frequency we are multiplying to get the value
    we want. 0.5 is an octave fall in terms of a power. The 5 means 5 octaves
    below the given c5 note which is middle C. Ultimately this gets us the freq
    of C (midi note 0 below middle C.*/
    c0 = c5 * pow(0.5, 5);

    printf("Please enter the MIDI note value you want the frequency of...\n");
    scanf("%d", &midinote);
    
    /*so at the end of it all this calculation equates to:
    The frequency of midi note 0 * semitone_ratio to the power of the midi note
    we want the frequency of.*/

    /*Ultimately:
	eg. 73
	8.1757989 * 1.0594631 ^ 73 = 554.365
    */
    frequency = c0 * pow(semitone_ratio, midinote);

    printf("MIDI note %d has the frequency %f\n", midinote, frequency);

    return 0;
}
