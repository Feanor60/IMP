/* PROJEKT -- Světelná Tabule (FITkit3) */
/* Autor: Vojtěch Bůbela (xbubel08) */

/* Tento program je založen na ukázkovém programu 'IMP_projekt - had_tabule_test' */
/* Dále tento program vychází z demonstračního cvičení k FITkitu3 */

/* Header file with all the essential definitions for a given type of MCU */
#include "MK60D10.h"

/* Macros for bit-level registers manipulation */
#define GPIO_PIN_MASK	0x1Fu
#define GPIO_PIN(x)		(((1)<<(x & GPIO_PIN_MASK)))

/* Buttons - from FITkit3 demo */
#define BTN_SW2 0x400     // Port E, bit 10
#define BTN_SW3 0x1000    // Port E, bit 12
#define BTN_SW4 0x8000000 // Port E, bit 27
#define BTN_SW5 0x4000000 // Port E, bit 26
#define BTN_SW6 0x800     // Port E, bit 11

/* Constants specifying delay loop duration */
#define	tdelay1			10000
#define tdelay2 		20
#define tdelay3			70

/* define length (in columns) of every letter */
#define len_A 4
#define len_B 3
#define len_C 4
#define len_D 4
#define len_E 4
#define len_F 4
#define len_G 4
#define len_H 3
#define len_I 1
#define len_J 3
#define len_K 4
#define len_L 4
#define len_M 5
#define len_N 5
#define len_O 5
#define len_P 4
#define len_Q 5
#define len_R 4
#define len_S 4
#define len_T 5
#define len_U 5
#define len_V 5
#define len_W 8
#define len_Y 5
#define len_Z 5

/* define row and column selections for every letter */
#define A(x)    row_select(255, x); \
				column_select(x); \
    			delay(tdelay3, tdelay2); \
    			row_select(17, x + 1); \
    			column_select(x + 1); \
    			delay(tdelay3, tdelay2); \
    			row_select(17, x + 2); \
    			column_select(x + 2); \
    			delay(tdelay3, tdelay2); \
    			row_select(255, x + 3); \
    			column_select(x + 3); \
    			delay(tdelay3, tdelay2);

#define B(x)	row_select(255, x); \
			 	column_select(x); \
			 	delay(tdelay3, tdelay2); \
			 	row_select(153, x + 1); \
			 	column_select(x + 1); \
			 	delay(tdelay3, tdelay2); \
			 	row_select(102, x + 2); \
			 	column_select(x + 2); \
			 	delay(tdelay3, tdelay2);

#define C(x)	row_select(60, x); \
				column_select(x); \
			 	delay(tdelay3, tdelay2); \
			 	row_select(66, x + 1); \
    			column_select(x + 1); \
    			delay(tdelay3, tdelay2); \
    			row_select(129, x + 2); \
    			column_select(x + 2); \
    			delay(tdelay3, tdelay2); \
    			row_select(66, x + 3); \
    			column_select(x + 3); \
    			delay(tdelay3, tdelay2);

#define D(x)	row_select(255, x); \
				column_select(x); \
			 	delay(tdelay3, tdelay2); \
			 	row_select(129, x + 1); \
    			column_select(x + 1); \
    			delay(tdelay3, tdelay2); \
    			row_select(66, x + 2); \
    			column_select(x + 2); \
    			delay(tdelay3, tdelay2); \
    			row_select(60, x + 3); \
    			column_select(x + 3); \
    			delay(tdelay3, tdelay2);

#define E(x)	row_select(255, x); \
				column_select(x); \
			 	delay(tdelay3, tdelay2); \
			 	row_select(137, x + 1); \
    			column_select(x + 1); \
    			delay(tdelay3, tdelay2); \
    			row_select(137, x + 2); \
    			column_select(x + 2); \
    			delay(tdelay3, tdelay2); \
    			row_select(137, x + 3); \
    			column_select(x + 3); \
    			delay(tdelay3, tdelay2);

#define F(x)	row_select(255, x); \
				column_select(x); \
			 	delay(tdelay3, tdelay2); \
			 	row_select(17, x + 1); \
    			column_select(x + 1); \
    			delay(tdelay3, tdelay2); \
    			row_select(17, x + 2); \
    			column_select(x + 2); \
    			delay(tdelay3, tdelay2); \
    			row_select(17, x + 3); \
    			column_select(x + 3); \
    			delay(tdelay3, tdelay2);

#define G(x)	row_select(60, x); \
				column_select(x); \
			 	delay(tdelay3, tdelay2); \
			 	row_select(66, x + 1); \
    			column_select(x + 1); \
    			delay(tdelay3, tdelay2); \
    			row_select(145, x + 2); \
    			column_select(x + 2); \
    			delay(tdelay3, tdelay2); \
    			row_select(118, x + 3); \
    			column_select(x + 3); \
    			delay(tdelay3, tdelay2);

#define H(x)	row_select(255, x); \
				column_select(x); \
			 	delay(tdelay3, tdelay2); \
			 	row_select(16, x + 1); \
    			column_select(x + 1); \
    			delay(tdelay3, tdelay2); \
    			row_select(255, x + 2); \
    			column_select(x + 2); \
    			delay(tdelay3, tdelay2);

#define I(x)	row_select(255, x); \
				column_select(x); \
			 	delay(tdelay3, tdelay2);

#define J(x)	row_select(65, x); \
				column_select(x); \
			 	delay(tdelay3, tdelay2); \
			 	row_select(129, x + 1); \
    			column_select(x + 1); \
    			delay(tdelay3, tdelay2); \
    			row_select(127, x + 2); \
    			column_select(x + 2); \
    			delay(tdelay3, tdelay2);

#define K(x)	row_select(255, x); \
				column_select(x); \
			 	delay(tdelay3, tdelay2); \
			 	row_select(24, x + 1); \
				column_select(x + 1); \
			 	delay(tdelay3, tdelay2); \
				row_select(36, x + 2); \
				column_select(x + 2); \
			 	delay(tdelay3, tdelay2); \
			 	row_select(195, x + 3); \
			 	column_select(x + 3); \
			 	delay(tdelay3, tdelay2);

#define L(x)	row_select(255, x); \
				column_select(x); \
			 	delay(tdelay3, tdelay2); \
			 	row_select(128, x + 1); \
				column_select(x + 1); \
			 	delay(tdelay3, tdelay2); \
			 	row_select(128, x + 2); \
				column_select(x + 2); \
			 	delay(tdelay3, tdelay2); \
			 	row_select(128, x + 3); \
				column_select(x + 3); \
			 	delay(tdelay3, tdelay2);

#define M(x)	row_select(255, x); \
				column_select(x); \
			 	delay(tdelay3, tdelay2); \
			 	row_select(2, x + 1); \
				column_select(x + 1); \
			 	delay(tdelay3, tdelay2); \
			 	row_select(4, x + 2); \
				column_select(x + 2); \
			 	delay(tdelay3, tdelay2); \
			 	row_select(2, x + 3); \
				column_select(x + 3); \
			 	delay(tdelay3, tdelay2); \
			 	row_select(255, x + 4); \
				column_select(x + 4); \
			 	delay(tdelay3, tdelay2);

#define N(x)	row_select(255, x); \
				column_select(x); \
			 	delay(tdelay3, tdelay2); \
			 	row_select(2, x + 1); \
				column_select(x + 1); \
			 	delay(tdelay3, tdelay2); \
			 	row_select(60, x + 2); \
				column_select(x + 2); \
			 	delay(tdelay3, tdelay2); \
			 	row_select(64, x + 3); \
				column_select(x + 3); \
			 	delay(tdelay3, tdelay2); \
			 	row_select(255, x + 4); \
				column_select(x + 4); \
			 	delay(tdelay3, tdelay2);

#define O(x)	row_select(60, x); \
				column_select(x); \
			 	delay(tdelay3, tdelay2); \
			 	row_select(66, x + 1); \
    			column_select(x + 1); \
    			delay(tdelay3, tdelay2); \
    			row_select(129, x + 2); \
    			column_select(x + 2); \
    			delay(tdelay3, tdelay2); \
    			row_select(66, x + 3); \
    			column_select(x + 3); \
    			delay(tdelay3, tdelay2); \
			 	row_select(60, x + 4); \
				column_select(x + 4); \
			 	delay(tdelay3, tdelay2);

#define P(x)	row_select(255, x); \
				column_select(x); \
			 	delay(tdelay3, tdelay2); \
			 	row_select(17, x + 1); \
    			column_select(x + 1); \
    			delay(tdelay3, tdelay2); \
    			row_select(17, x + 2); \
    			column_select(x + 2); \
    			delay(tdelay3, tdelay2); \
    			row_select(14, x + 3); \
    			column_select(x + 3); \
    			delay(tdelay3, tdelay2);

#define Q(x)	row_select(60, x); \
				column_select(x); \
			 	delay(tdelay3, tdelay2); \
			 	row_select(66, x + 1); \
    			column_select(x + 1); \
    			delay(tdelay3, tdelay2); \
    			row_select(161, x + 2); \
    			column_select(x + 2); \
    			delay(tdelay3, tdelay2); \
    			row_select(66, x + 3); \
    			column_select(x + 3); \
    			delay(tdelay3, tdelay2); \
			 	row_select(188, x + 4); \
				column_select(x + 4); \
			 	delay(tdelay3, tdelay2);

#define R(x)	row_select(255, x); \
				column_select(x); \
			 	delay(tdelay3, tdelay2); \
			 	row_select(49, x + 1); \
    			column_select(x + 1); \
    			delay(tdelay3, tdelay2); \
    			row_select(81, x + 2); \
    			column_select(x + 2); \
    			delay(tdelay3, tdelay2); \
    			row_select(142, x + 3); \
    			column_select(x + 3); \
    			delay(tdelay3, tdelay2);

#define S(x)	row_select(102, x); \
				column_select(x); \
			 	delay(tdelay3, tdelay2); \
			 	row_select(137, x + 1); \
    			column_select(x + 1); \
    			delay(tdelay3, tdelay2); \
    			row_select(145, x + 2); \
    			column_select(x + 2); \
    			delay(tdelay3, tdelay2); \
    			row_select(98, x + 3); \
    			column_select(x + 3); \
    			delay(tdelay3, tdelay2);

#define T(x)	row_select(1, x); \
				column_select(x); \
			 	delay(tdelay3, tdelay2); \
			 	row_select(1, x + 1); \
    			column_select(x + 1); \
    			delay(tdelay3, tdelay2); \
    			row_select(255, x + 2); \
    			column_select(x + 2); \
    			delay(tdelay3, tdelay2); \
    			row_select(1, x + 3); \
    			column_select(x + 3); \
    			delay(tdelay3, tdelay2); \
    			row_select(1, x + 4); \
    			column_select(x + 4); \
    			delay(tdelay3, tdelay2);

#define U(x)	row_select(127, x); \
				column_select(x); \
			 	delay(tdelay3, tdelay2); \
			 	row_select(128, x + 1); \
    			column_select(x + 1); \
    			delay(tdelay3, tdelay2); \
    			row_select(128, x + 2); \
    			column_select(x + 2); \
    			delay(tdelay3, tdelay2); \
    			row_select(128, x + 3); \
    			column_select(x + 3); \
    			delay(tdelay3, tdelay2); \
			 	row_select(127, x + 4); \
				column_select(x + 4); \
			 	delay(tdelay3, tdelay2);

#define V(x)	row_select(15, x); \
				column_select(x); \
			 	delay(tdelay3, tdelay2); \
			 	row_select(120, x + 1); \
    			column_select(x + 1); \
    			delay(tdelay3, tdelay2); \
    			row_select(128, x + 2); \
    			column_select(x + 2); \
    			delay(tdelay3, tdelay2); \
    			row_select(120, x + 3); \
    			column_select(x + 3); \
    			delay(tdelay3, tdelay2); \
			 	row_select(15, x + 4); \
				column_select(x + 4); \
			 	delay(tdelay3, tdelay2);

#define W(x)	row_select(15, x); \
				column_select(x); \
			 	delay(tdelay3, tdelay2); \
			 	row_select(120, x + 1); \
    			column_select(x + 1); \
    			delay(tdelay3, tdelay2); \
    			row_select(128, x + 2); \
    			column_select(x + 2); \
    			delay(tdelay3, tdelay2); \
    			row_select(124, x + 3); \
    			column_select(x + 3); \
    			delay(tdelay3, tdelay2); \
    			row_select(124, x + 4); \
    			column_select(x + 4); \
    			delay(tdelay3, tdelay2); \
				row_select(128, x + 5); \
    			column_select(x + 5); \
    			delay(tdelay3, tdelay2); \
    			row_select(120, x + 6); \
    			column_select(x + 6); \
    			delay(tdelay3, tdelay2); \
			 	row_select(15, x + 7); \
				column_select(x + 7); \
			 	delay(tdelay3, tdelay2);

#define Y(x)	row_select(15, x); \
				column_select(x); \
			 	delay(tdelay3, tdelay2); \
			 	row_select(16, x + 1); \
    			column_select(x + 1); \
    			delay(tdelay3, tdelay2); \
    			row_select(224, x + 2); \
    			column_select(x + 2); \
    			delay(tdelay3, tdelay2); \
    			row_select(16, x + 3); \
    			column_select(x + 3); \
    			delay(tdelay3, tdelay2); \
    			row_select(15, x + 4); \
    			column_select(x + 4); \
    			delay(tdelay3, tdelay2);

#define Z(x)	row_select(193, x); \
				column_select(x); \
			 	delay(tdelay3, tdelay2); \
			 	row_select(161, x + 1); \
    			column_select(x + 1); \
    			delay(tdelay3, tdelay2); \
    			row_select(145, x + 2); \
    			column_select(x + 2); \
    			delay(tdelay3, tdelay2); \
    			row_select(137, x + 3); \
    			column_select(x + 3); \
    			delay(tdelay3, tdelay2); \
    			row_select(135, x + 4); \
    			column_select(x + 4); \
    			delay(tdelay3, tdelay2);

#define Empty row_select(0, 0);

/* Configuration of the necessary MCU peripherals */
/* Big part was taken from test 
void SystemConfig() {
	/* Turn on all port clocks */
	SIM->SCGC5 = SIM_SCGC5_PORTA_MASK | SIM_SCGC5_PORTE_MASK;

	// turn on PIT clock
	SIM->SCGC6 |= SIM_SCGC6_PIT_MASK;

	NVIC->ICPR[2] = (1 << 27);
	NVIC->ISER[2] = (1 << 27);

	/* Taken from FITkit3 demo */
	PORTE->PCR[10] = PORT_PCR_MUX(0x01); // SW2
	PORTE->PCR[11] = PORT_PCR_MUX(0x01); // SW6
	PORTE->PCR[12] = PORT_PCR_MUX(0x01); // SW3
	PORTE->PCR[27] = PORT_PCR_MUX(0x01); // SW4
	PORTE->PCR[26] = PORT_PCR_MUX(0x01); // SW5


	/* Set corresponding PTA pins (column activators of 74HC154) for GPIO functionality */
	PORTA->PCR[8] = ( 0|PORT_PCR_MUX(0x01) );  // A0
	PORTA->PCR[10] = ( 0|PORT_PCR_MUX(0x01) ); // A1
	PORTA->PCR[6] = ( 0|PORT_PCR_MUX(0x01) );  // A2
	PORTA->PCR[11] = ( 0|PORT_PCR_MUX(0x01) ); // A3

	/* Set corresponding PTA pins (rows selectors of 74HC154) for GPIO functionality */
	PORTA->PCR[26] = ( 0|PORT_PCR_MUX(0x01) );  // R0
	PORTA->PCR[24] = ( 0|PORT_PCR_MUX(0x01) );  // R1
	PORTA->PCR[9] = ( 0|PORT_PCR_MUX(0x01) );   // R2
	PORTA->PCR[25] = ( 0|PORT_PCR_MUX(0x01) );  // R3
	PORTA->PCR[28] = ( 0|PORT_PCR_MUX(0x01) );  // R4
	PORTA->PCR[7] = ( 0|PORT_PCR_MUX(0x01) );   // R5
	PORTA->PCR[27] = ( 0|PORT_PCR_MUX(0x01) );  // R6
	PORTA->PCR[29] = ( 0|PORT_PCR_MUX(0x01) );  // R7

	/* Set corresponding PTE pins (output enable of 74HC154) for GPIO functionality */
	PORTE->PCR[28] = ( 0|PORT_PCR_MUX(0x01) ); // #EN


	/* Change corresponding PTA port pins as outputs */
	PTA->PDDR = GPIO_PDDR_PDD(0x3F000FC0);

	/* Change corresponding PTE port pins as outputs */
	PTE->PDDR = GPIO_PDDR_PDD( GPIO_PIN(28) );

	// PIT timer
	// turn on PIT
	PIT_MCR = 0x00;

	// set timer value
	PIT->CHANNEL[1].LDVAL= 2000000;
	// enable timer and interrupts generated by timer
	PIT->CHANNEL[1].TCTRL = PIT_TCTRL_TIE_MASK | PIT_TCTRL_TEN_MASK;
}


/* Variable delay loop */
void delay(int t1, int t2)
{
	int i, j;

	for(i=0; i<t1; i++) {
		for(j=0; j<t2; j++);
	}
}


/* Conversion of requested column number into the 4-to-16 decoder control.  */
/* Taken (and modified) from 'IMP_projekt - had_tabule_test'*/
void column_select(int col_num_first)
{
	unsigned i, col_num, result, col_sel[4];

	if (col_num_first < 0 || col_num_first > 15) {
		return;
	}

	col_num = (unsigned)col_num_first;

	for (i =0; i<4; i++) {
		result = col_num / 2;
		col_sel[i] = col_num % 2;
		col_num = result;

		switch(i) {

			// Selection signal A0
		    case 0:
				((col_sel[i]) == 0) ? (PTA->PDOR &= ~GPIO_PDOR_PDO( GPIO_PIN(8))) : (PTA->PDOR |= GPIO_PDOR_PDO( GPIO_PIN(8)));
				break;

			// Selection signal A1
			case 1:
				((col_sel[i]) == 0) ? (PTA->PDOR &= ~GPIO_PDOR_PDO( GPIO_PIN(10))) : (PTA->PDOR |= GPIO_PDOR_PDO( GPIO_PIN(10)));
				break;

			// Selection signal A2
			case 2:
				((col_sel[i]) == 0) ? (PTA->PDOR &= ~GPIO_PDOR_PDO( GPIO_PIN(6))) : (PTA->PDOR |= GPIO_PDOR_PDO( GPIO_PIN(6)));
				break;

			// Selection signal A3
			case 3:
				((col_sel[i]) == 0) ? (PTA->PDOR &= ~GPIO_PDOR_PDO( GPIO_PIN(11))) : (PTA->PDOR |= GPIO_PDOR_PDO( GPIO_PIN(11)));
				break;

			// Otherwise nothing to do...
			default:
				break;
		}
	}
}

/* functions implements multiplexing for rows */
void row_select(unsigned int row_num, int col_num)
{

	if (col_num < 0 || col_num > 15) {
		return;
	}
	unsigned i, result, row_sel[8];

	for (i =0; i < 8; i++) {
			result = row_num / 2;
			row_sel[i] = row_num % 2;
			row_num = result;

			switch(i) {

				// Selection signal A0
			    case 0:
					((row_sel[i]) == 0) ? (PTA->PDOR &= ~GPIO_PDOR_PDO( GPIO_PIN(26))) : (PTA->PDOR |= GPIO_PDOR_PDO( GPIO_PIN(26)));
					break;

				// Selection signal A1
				case 1:
					((row_sel[i]) == 0) ? (PTA->PDOR &= ~GPIO_PDOR_PDO( GPIO_PIN(24))) : (PTA->PDOR |= GPIO_PDOR_PDO( GPIO_PIN(24)));
					break;

				// Selection signal A2
				case 2:
					((row_sel[i]) == 0) ? (PTA->PDOR &= ~GPIO_PDOR_PDO( GPIO_PIN(9))) : (PTA->PDOR |= GPIO_PDOR_PDO( GPIO_PIN(9)));
					break;

				// Selection signal A3
				case 3:
					((row_sel[i]) == 0) ? (PTA->PDOR &= ~GPIO_PDOR_PDO( GPIO_PIN(25))) : (PTA->PDOR |= GPIO_PDOR_PDO( GPIO_PIN(25)));
					break;

				case 4:
					((row_sel[i]) == 0) ? (PTA->PDOR &= ~GPIO_PDOR_PDO( GPIO_PIN(28))) : (PTA->PDOR |= GPIO_PDOR_PDO( GPIO_PIN(28)));
					break;

				// Selection signal A1
				case 5:
					((row_sel[i]) == 0) ? (PTA->PDOR &= ~GPIO_PDOR_PDO( GPIO_PIN(7))) : (PTA->PDOR |= GPIO_PDOR_PDO( GPIO_PIN(7)));
					break;

				// Selection signal A2
				case 6:
					((row_sel[i]) == 0) ? (PTA->PDOR &= ~GPIO_PDOR_PDO( GPIO_PIN(27))) : (PTA->PDOR |= GPIO_PDOR_PDO( GPIO_PIN(27)));
					break;

				// Selection signal A3
				case 7:
					((row_sel[i]) == 0) ? (PTA->PDOR &= ~GPIO_PDOR_PDO( GPIO_PIN(29))) : (PTA->PDOR |= GPIO_PDOR_PDO( GPIO_PIN(29)));
					break;

				// Otherwise nothing to do...
				default:
					break;
			}
		}
}

void print_VUT()
{
	// calculate number of columns the message will take
	int vut_len = len_V + len_U + len_T + 3;
	int msg_pointer = 0;
	int result = 0;
	int loop_cnt = len_V + 15;

	for(;;) {
		// start timer
		PIT_TFLG1 = 1;
		// loop until PIT interrupt is generated
		while(1) {

			T(loop_cnt);

			msg_pointer += (len_U + 1);
			result = loop_cnt - msg_pointer;
			U(result);

			msg_pointer += (len_V + 1);
			result = loop_cnt - msg_pointer;
			V(result);

			msg_pointer = 0;
			if(PIT_TFLG1 == 1){
				break;
			}
			Empty;
		}

		// if button was pressed return to main and print according message
		if (!(GPIOE_PDIR & BTN_SW2) || !(GPIOE_PDIR & BTN_SW4) || !(GPIOE_PDIR & BTN_SW5)) {
			return;
		}

		if(loop_cnt < -len_T) {
			loop_cnt = vut_len + 15;
		} else {
			loop_cnt--;
		}
	}
}

void print_FIT()
{
	// calculate number of columns the message will take
	int fit_len = len_F + len_I + len_T + 3;
	int msg_pointer = 0;
	int result = 0;
	int loop_cnt = fit_len + 15;

	

	for(;;) {
		// start timer
		PIT_TFLG1 = 1;
		// loop until PIT interrupt is generated
		while(1) {

			T(loop_cnt);

			msg_pointer += (len_I + 1);
			result = loop_cnt - msg_pointer;
			I(result);

			msg_pointer += (len_F + 1);
			result = loop_cnt - msg_pointer;
			F(result);

			msg_pointer = 0;
			if(PIT_TFLG1 == 1){
				break;
			}
			Empty;
		}

		if (!(GPIOE_PDIR & BTN_SW3) || !(GPIOE_PDIR & BTN_SW4) || !(GPIOE_PDIR & BTN_SW5)) {
			return;
		}

		if(loop_cnt < -len_T) {
			loop_cnt = fit_len + 15;
		} else {
			loop_cnt--;
		}
	}
}

void print_IMP()
{
	// calculate number of columns the message will take
	int imp_len = len_I + len_M + len_P + 3;
	int msg_pointer = 0;
	int result = 0;
	int loop_cnt = imp_len + 15;

	

	for(;;) {
		// start timer
		PIT_TFLG1 = 1;
		// loop until PIT interrupt is generated
		while(1) {

			P(loop_cnt);

			msg_pointer += (len_M + 1);
			result = loop_cnt - msg_pointer;
			M(result);

			msg_pointer += (len_I + 1);
			result = loop_cnt - msg_pointer;
			I(result);

			msg_pointer = 0;
			if(PIT_TFLG1 == 1){
				break;
			}
			Empty;
		}

		if (!(GPIOE_PDIR & BTN_SW3) || !(GPIOE_PDIR & BTN_SW5) || !(GPIOE_PDIR & BTN_SW2)) {
			return;
		}

		if(loop_cnt < -len_P) {
			loop_cnt = imp_len + 15;
		} else {
			loop_cnt--;
		}
	}
}


int main(void)
{
	SystemConfig();

	row_select(255, 0);
	delay(tdelay1, tdelay2);

    for (;;) {

    	if(!(GPIOE_PDIR & BTN_SW2)){
    		print_FIT();
    	}

    	if(!(GPIOE_PDIR & BTN_SW3)){
    		print_VUT();
    	}

    	if(!(GPIOE_PDIR & BTN_SW4)){
    	    print_IMP();
    	}

    	if(!(GPIOE_PDIR & BTN_SW5)){

    	}
    }
    /* Never leave main */
    return 0;
}
