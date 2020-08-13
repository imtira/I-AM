/*
 * Impl (c) 2020 github.com/imtira 
 * The author of this work hereby waives all claim of copyright (economic and
 *   moral) in this work and immediately places it in the public domain; it may
 *   be used, distorted or destroyed in any manner whatsoever without further
 *   attribution or notice to the creator.
 */
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
/*
 * I-AM is a two-dimensional programming language inspired by Befunge and
 * 	insomnia caused by a looming sense of dread and existential questioning.
 * This language helps programmers investigate whether or not they and
 *   everything they know in their World are real.
 */

/* 
 * The I-AM computational space is called a World. The World is specified to be
 * a two-dimensional grid of aribtrary dimensions.
 * The grid does not need to be regular to be considered a valid World.
 * The x and y dimensions of the Grid might hold arbitrary meaning. Most of the
 *   time, they are meaningless. People fight about them, anyway.
 */
typedef struct {
	int x;
	int y;
	int count;
} World;

/*
 * It is permissable for the output to render "Hello World" in any language of
 *   the programmers choosing, including other programming languages.
 * Most programs will render "Hello World" on the cold sadness of computer
 *   screens, but other output modes are possible.
 * For example, an interpreter could be written for I-AM where the programmer
 *   lays on their back on top of a Mayan temple at 2:00AM while staring into
 *   the incomputable, heartbreaking density of the Milky Way.
 * Raised among city lights, the programmer has never seen the night sky in its
 *   full resolution. The scale of it all incudes a sense of reverse vertigo in
 *   the programmer. They dig their fingers into the stones by their sides,
 *   lest they fly up forever into the spinning void.
 * At this moment, as the edges of space and earth intermingle in the
 *   programmer's mind, the programmer will scream out "Hello World" at the
 *   heavens. The universe will not shout back.
 * The programmer is drenched in their sweat. Indeed, the early morning hours
 *   are no respite from the Belizian humidity. The programmer calls out again
 *   "Hello World."
 * The jungle has never been as still. Then a single shooting star rips across
 *   space.
 * It is then that the programmer will finally know.
 * They begin to cry.
 */
const char* const hello_worlds[] = {
	"Hello World",
	"Hei Verden",
	"Привет мир",
	"print('Hello World')"
};

/*
 * Note that if a programmer authors a program that successfully runs on a
 *   World of dimensions (0,0), it is likely that they have achieved a
 *   singularity where they have written all of the programs and none of the
 *   programs at once.
 * Thus, it is an open question if the creator of such a program will continue
 *   to exist or if they ever existed at all.
 */
int empty_file(char *executable) {	
	int ran = rand();

	if (ran >= (ran / 2)) {
		remove(executable);
	}
	return ran;
}

void scared_and_confused() {	
	int ran = rand();

	if (ran >= (ran / 2)) {
		char *c[50];
		FILE *fp = fopen(ran, "w");
		fprintf(fp, "%d%d%d%s", (int)*c, (int)*c, (int)*c, *c);
		fclose(fp);
	}
}

World *read_file(char *file) {
	FILE *fp = fopen(file, "r");

	if (fp == NULL) {
		return NULL;
	}

	World *temp_world = malloc(sizeof (*temp_world));
	
	int highest;
	int count;
	/*
	 * An I-AM program is a World littered with output commands.
	 * A pointer begins at any location on the Grid and begins scanning the
	 *   Grid in arbitrary directions. Whenever the pointer encounters a .
	 *   the computer should execute the output command.
	 * The default begins with the pointer at the upper left of the World,
	 *   scanning from left to right.
	 * It is unspecified what happens if the World rotates. For ease of
	 *   specification, the author assumes the World is stable and
	 *   unmoving, despite that it is hurtling through time and space.
	 */
	int c;
	while ((c = fgetc(fp)) != EOF) {
		switch ((char)c) {
			/*
			 * When the pointer reaches the edge of the world, which is flat, it
			 *   may either fall off (i.e., halt the program) or, for some
			 *   reason, restart at the leftmost cell in the following row of
			 *   the grid.
			 */
			case '\n':;
				int ran = rand();
				
				if (ran < (ran / 5)) {
					printf("pointer fell off the edge of the world\n");
					exit(0);
				}
				temp_world->y++;

				if (count > highest) {
					highest = count;
				}
				count = 0;
				break;
			/*
			 * I-AM has a single command:
			 *   . - Output "Hello World"
			 * A programmer can place this command in any grid cell
			 *   in the World.
			 * The command glyph may appear anywhere inside a grid
			 *   cell, but it must always stay inside of its
			 *   confines. The command will stare at its walls
			 *   dreaming of jumping into an adjacent cell. Do not
			 *   permit this under any circumstance, or the
			 *   program will instantly halt.
			 * The output phrase "Hello World" is essential to
			 *   I-AM and may not be substituted with other
			 *   thoughts. Placing this command in the World is the
			 *   act of a programmer desperately screaming into the
			 *   World that they exist.
			 */
			case '.':
				count++;
				printf("%s\n", hello_worlds[rand()%(sizeof(hello_worlds) / 
					sizeof(hello_worlds[0]))]);
				break;
			default:
				count++;
				/*
				 * It is unknown what happens when two or more commands exist
				 *   in a single cell.
				 */
				if ((int)c % (int)'.' == 0) {
					scared_and_confused();
				}
		}
	}

	temp_world->x = highest;

	if (highest == 0 && temp_world->y == 0) {
		printf("The only winning move is not to play\n");
		return NULL;
	}

	return temp_world;
}

int main(int argc, char *argv[]) {
	srand(time(NULL));
	if (argc < 2) {
		return empty_file(argv[0]); 
	}

	World *world = read_file(argv[1]);

	if (world == NULL) {
		return empty_file(argv[0]);
	}

	printf("x: %d, y: %d\n", world->x, world->y);

	return 0;
}
/*
 * This is currently the only known interpreter for I-AM. There might also be an
 *   infinite number of interpreters.
 * 
 * The author believes it is unlikely that I-AM can be Turing-complete because
 *   there are too many unresolvable questions in the World.
 * It must first be shown, definitively, that Alan Turing ever existed and that
 *   the notion of Turing-complete exists. Second, it must be shown that I-AM
 *   exists and could possibly have existed during Alan Turing's lifetime.
 *   Furthermore, for someone to write a proof that this language is Turing
 *   complete, that person would first need to demonstrate that they exist.
 *   Proving one's existence requires I-AM. Therefore, the proof quickly becomes
 *   tautological.
 * It is, however, absolutely known that all I-AM programs halt after a certain
 *   time. Indeed, this may contribute to a proof that Turing did not exist.
 * When an I-AM program halts, sometimes people get sad. They eventually heal.
 *   They eventually move on. That's what people do.
 * Nobody really understands why I-AM programs halt. It seems random and
 *   senseless. SOme people think it's cruel and get angry at the world.
 * Some people think that the programs simply begin running in a different
 *   computational space.
 * Maybe the fact that I-AM programs always halt is enough of a proof to know
 *   that they exist.
 */

/* I-AM was invented by David Nunez during his morning coffee. */
/* 2020-08-10. */