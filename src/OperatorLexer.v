#############################################################################
#                         A C A D E M I C   C O P Y
# 
# This file was produced by an ACADEMIC COPY of Parser Generator. It is for
# use in non-commercial software only. An ACADEMIC COPY of Parser Generator
# can only be used by a student, or a member of an academic community. If
# however you want to use Parser Generator for commercial purposes then you
# will need to purchase a license. For more information see the online help or
# go to the Bumble-Bee Software homepage at:
# 
# http://www.bumblebeesoftware.com
# 
# This notice must remain present in the file. It cannot be removed.
#############################################################################

#############################################################################
# OperatorLexer.v
# Lex verbose file generated from OperatorLexer.l.
# 
# Date: 12/27/03
# Time: 19:58:52
# 
# ALex Version: 2.05
#############################################################################


#############################################################################
# Expressions
#############################################################################

    1  "operator"

    2  "preconds"

    3  "effects"

    4  "start"

    5  "goal"

    6  "not"

    7  [a-zA-Z_][a-zA-Z_0-9]*

    8  [0-9]+[uUlL]*

    9  L?\"([^"\\\n]|\\([abfnrtv"'?\\]|[0-7]{1,3}|x[0-9a-fA-F]+))*\"

   10  L?\'([^"\\\n]|\\([abfnrtv"'?\\]|[0-7]{1,3}|x[0-9a-fA-F]+))*\'

   11  [0-9]+\.[0-9]*((e|E)("+"|"-")[0-9]+)?

   12  \.[0-9]+((e|E)("+"|"-")[0-9]+)?

   13  [ \t]+

   14  "/*"

   15  <COMMENT>"*/"

   16  <COMMENT>[^*\n]+

   17  <COMMENT>\n

   18  <COMMENT>"*"

   19  "//"

   20  <LINECOMMENT>"\n"

   21  .


#############################################################################
# States
#############################################################################

state 1
	INITIAL

	0x00 - 0x08 (9)    goto 7
	0x09               goto 8
	0x0b - 0x1f (21)   goto 7
	0x20               goto 8
	0x21               goto 7
	0x22               goto 9
	0x23 - 0x26 (4)    goto 7
	0x27               goto 10
	0x28 - 0x2d (6)    goto 7
	0x2e               goto 11
	0x2f               goto 12
	0x30 - 0x39 (10)   goto 13
	0x3a - 0x40 (7)    goto 7
	0x41 - 0x4b (11)   goto 14
	0x4c               goto 15
	0x4d - 0x5a (14)   goto 14
	0x5b - 0x5e (4)    goto 7
	0x5f               goto 14
	0x60               goto 7
	0x61 - 0x64 (4)    goto 14
	0x65               goto 16
	0x66               goto 14
	0x67               goto 17
	0x68 - 0x6d (6)    goto 14
	0x6e               goto 18
	0x6f               goto 19
	0x70               goto 20
	0x71 - 0x72 (2)    goto 14
	0x73               goto 21
	0x74 - 0x7a (7)    goto 14
	0x7b - 0xff (133)  goto 7


state 2
	^INITIAL

	0x00 - 0x08 (9)    goto 7
	0x09               goto 8
	0x0b - 0x1f (21)   goto 7
	0x20               goto 8
	0x21               goto 7
	0x22               goto 9
	0x23 - 0x26 (4)    goto 7
	0x27               goto 10
	0x28 - 0x2d (6)    goto 7
	0x2e               goto 11
	0x2f               goto 12
	0x30 - 0x39 (10)   goto 13
	0x3a - 0x40 (7)    goto 7
	0x41 - 0x4b (11)   goto 14
	0x4c               goto 15
	0x4d - 0x5a (14)   goto 14
	0x5b - 0x5e (4)    goto 7
	0x5f               goto 14
	0x60               goto 7
	0x61 - 0x64 (4)    goto 14
	0x65               goto 16
	0x66               goto 14
	0x67               goto 17
	0x68 - 0x6d (6)    goto 14
	0x6e               goto 18
	0x6f               goto 19
	0x70               goto 20
	0x71 - 0x72 (2)    goto 14
	0x73               goto 21
	0x74 - 0x7a (7)    goto 14
	0x7b - 0xff (133)  goto 7


state 3
	COMMENT

	0x00 - 0x09 (10)   goto 76
	0x0a               goto 77
	0x0b - 0x29 (31)   goto 76
	0x2a               goto 78
	0x2b - 0xff (213)  goto 76


state 4
	^COMMENT

	0x00 - 0x09 (10)   goto 76
	0x0a               goto 77
	0x0b - 0x29 (31)   goto 76
	0x2a               goto 78
	0x2b - 0xff (213)  goto 76


state 5
	LINECOMMENT

	0x0a               goto 80


state 6
	^LINECOMMENT

	0x0a               goto 80


state 7
	match 21


state 8
	0x09               goto 8
	0x20               goto 8

	match 13


state 9
	0x00 - 0x09 (10)   goto 22
	0x0b - 0x21 (23)   goto 22
	0x22               goto 23
	0x23 - 0x5b (57)   goto 22
	0x5c               goto 24
	0x5d - 0xff (163)  goto 22

	match 21


state 10
	0x00 - 0x09 (10)   goto 25
	0x0b - 0x21 (23)   goto 25
	0x23 - 0x26 (4)    goto 25
	0x27               goto 26
	0x28 - 0x5b (52)   goto 25
	0x5c               goto 27
	0x5d - 0xff (163)  goto 25

	match 21


state 11
	0x30 - 0x39 (10)   goto 28

	match 21


state 12
	0x2a               goto 29
	0x2f               goto 30

	match 21


state 13
	0x2e               goto 31
	0x30 - 0x39 (10)   goto 13
	0x4c               goto 32
	0x55               goto 32
	0x6c               goto 32
	0x75               goto 32

	match 8


state 14
	0x30 - 0x39 (10)   goto 14
	0x41 - 0x5a (26)   goto 14
	0x5f               goto 14
	0x61 - 0x7a (26)   goto 14

	match 7


state 15
	0x22               goto 22
	0x27               goto 25
	0x30 - 0x39 (10)   goto 14
	0x41 - 0x5a (26)   goto 14
	0x5f               goto 14
	0x61 - 0x7a (26)   goto 14

	match 7


state 16
	0x30 - 0x39 (10)   goto 14
	0x41 - 0x5a (26)   goto 14
	0x5f               goto 14
	0x61 - 0x65 (5)    goto 14
	0x66               goto 33
	0x67 - 0x7a (20)   goto 14

	match 7


state 17
	0x30 - 0x39 (10)   goto 14
	0x41 - 0x5a (26)   goto 14
	0x5f               goto 14
	0x61 - 0x6e (14)   goto 14
	0x6f               goto 34
	0x70 - 0x7a (11)   goto 14

	match 7


state 18
	0x30 - 0x39 (10)   goto 14
	0x41 - 0x5a (26)   goto 14
	0x5f               goto 14
	0x61 - 0x6e (14)   goto 14
	0x6f               goto 35
	0x70 - 0x7a (11)   goto 14

	match 7


state 19
	0x30 - 0x39 (10)   goto 14
	0x41 - 0x5a (26)   goto 14
	0x5f               goto 14
	0x61 - 0x6f (15)   goto 14
	0x70               goto 36
	0x71 - 0x7a (10)   goto 14

	match 7


state 20
	0x30 - 0x39 (10)   goto 14
	0x41 - 0x5a (26)   goto 14
	0x5f               goto 14
	0x61 - 0x71 (17)   goto 14
	0x72               goto 37
	0x73 - 0x7a (8)    goto 14

	match 7


state 21
	0x30 - 0x39 (10)   goto 14
	0x41 - 0x5a (26)   goto 14
	0x5f               goto 14
	0x61 - 0x73 (19)   goto 14
	0x74               goto 38
	0x75 - 0x7a (6)    goto 14

	match 7


state 22
	0x00 - 0x09 (10)   goto 22
	0x0b - 0x21 (23)   goto 22
	0x22               goto 23
	0x23 - 0x5b (57)   goto 22
	0x5c               goto 24
	0x5d - 0xff (163)  goto 22


state 23
	match 9


state 24
	0x22               goto 22
	0x27               goto 22
	0x30 - 0x37 (8)    goto 39
	0x3f               goto 22
	0x5c               goto 22
	0x61 - 0x62 (2)    goto 22
	0x66               goto 22
	0x6e               goto 22
	0x72               goto 22
	0x74               goto 22
	0x76               goto 22
	0x78               goto 40


state 25
	0x00 - 0x09 (10)   goto 25
	0x0b - 0x21 (23)   goto 25
	0x23 - 0x26 (4)    goto 25
	0x27               goto 26
	0x28 - 0x5b (52)   goto 25
	0x5c               goto 27
	0x5d - 0xff (163)  goto 25


state 26
	0x00 - 0x09 (10)   goto 25
	0x0b - 0x21 (23)   goto 25
	0x23 - 0x26 (4)    goto 25
	0x27               goto 26
	0x28 - 0x5b (52)   goto 25
	0x5c               goto 27
	0x5d - 0xff (163)  goto 25

	match 10


state 27
	0x22               goto 25
	0x27               goto 25
	0x30 - 0x37 (8)    goto 41
	0x3f               goto 25
	0x5c               goto 25
	0x61 - 0x62 (2)    goto 25
	0x66               goto 25
	0x6e               goto 25
	0x72               goto 25
	0x74               goto 25
	0x76               goto 25
	0x78               goto 42


state 28
	0x30 - 0x39 (10)   goto 28
	0x45               goto 43
	0x65               goto 43

	match 12


state 29
	match 14


state 30
	match 19


state 31
	0x30 - 0x39 (10)   goto 31
	0x45               goto 44
	0x65               goto 44

	match 11


state 32
	0x4c               goto 32
	0x55               goto 32
	0x6c               goto 32
	0x75               goto 32

	match 8


state 33
	0x30 - 0x39 (10)   goto 14
	0x41 - 0x5a (26)   goto 14
	0x5f               goto 14
	0x61 - 0x65 (5)    goto 14
	0x66               goto 45
	0x67 - 0x7a (20)   goto 14

	match 7


state 34
	0x30 - 0x39 (10)   goto 14
	0x41 - 0x5a (26)   goto 14
	0x5f               goto 14
	0x61               goto 46
	0x62 - 0x7a (25)   goto 14

	match 7


state 35
	0x30 - 0x39 (10)   goto 14
	0x41 - 0x5a (26)   goto 14
	0x5f               goto 14
	0x61 - 0x73 (19)   goto 14
	0x74               goto 47
	0x75 - 0x7a (6)    goto 14

	match 7


state 36
	0x30 - 0x39 (10)   goto 14
	0x41 - 0x5a (26)   goto 14
	0x5f               goto 14
	0x61 - 0x64 (4)    goto 14
	0x65               goto 48
	0x66 - 0x7a (21)   goto 14

	match 7


state 37
	0x30 - 0x39 (10)   goto 14
	0x41 - 0x5a (26)   goto 14
	0x5f               goto 14
	0x61 - 0x64 (4)    goto 14
	0x65               goto 49
	0x66 - 0x7a (21)   goto 14

	match 7


state 38
	0x30 - 0x39 (10)   goto 14
	0x41 - 0x5a (26)   goto 14
	0x5f               goto 14
	0x61               goto 50
	0x62 - 0x7a (25)   goto 14

	match 7


state 39
	0x00 - 0x09 (10)   goto 22
	0x0b - 0x21 (23)   goto 22
	0x22               goto 23
	0x23 - 0x2f (13)   goto 22
	0x30 - 0x37 (8)    goto 51
	0x38 - 0x5b (36)   goto 22
	0x5c               goto 24
	0x5d - 0xff (163)  goto 22


state 40
	0x30 - 0x39 (10)   goto 52
	0x41 - 0x46 (6)    goto 52
	0x61 - 0x66 (6)    goto 52


state 41
	0x00 - 0x09 (10)   goto 25
	0x0b - 0x21 (23)   goto 25
	0x23 - 0x26 (4)    goto 25
	0x27               goto 26
	0x28 - 0x2f (8)    goto 25
	0x30 - 0x37 (8)    goto 53
	0x38 - 0x5b (36)   goto 25
	0x5c               goto 27
	0x5d - 0xff (163)  goto 25


state 42
	0x30 - 0x39 (10)   goto 54
	0x41 - 0x46 (6)    goto 54
	0x61 - 0x66 (6)    goto 54


state 43
	0x2b               goto 55
	0x2d               goto 55


state 44
	0x2b               goto 56
	0x2d               goto 56


state 45
	0x30 - 0x39 (10)   goto 14
	0x41 - 0x5a (26)   goto 14
	0x5f               goto 14
	0x61 - 0x64 (4)    goto 14
	0x65               goto 57
	0x66 - 0x7a (21)   goto 14

	match 7


state 46
	0x30 - 0x39 (10)   goto 14
	0x41 - 0x5a (26)   goto 14
	0x5f               goto 14
	0x61 - 0x6b (11)   goto 14
	0x6c               goto 58
	0x6d - 0x7a (14)   goto 14

	match 7


state 47
	0x30 - 0x39 (10)   goto 14
	0x41 - 0x5a (26)   goto 14
	0x5f               goto 14
	0x61 - 0x7a (26)   goto 14

	match 6


state 48
	0x30 - 0x39 (10)   goto 14
	0x41 - 0x5a (26)   goto 14
	0x5f               goto 14
	0x61 - 0x71 (17)   goto 14
	0x72               goto 59
	0x73 - 0x7a (8)    goto 14

	match 7


state 49
	0x30 - 0x39 (10)   goto 14
	0x41 - 0x5a (26)   goto 14
	0x5f               goto 14
	0x61 - 0x62 (2)    goto 14
	0x63               goto 60
	0x64 - 0x7a (23)   goto 14

	match 7


state 50
	0x30 - 0x39 (10)   goto 14
	0x41 - 0x5a (26)   goto 14
	0x5f               goto 14
	0x61 - 0x71 (17)   goto 14
	0x72               goto 61
	0x73 - 0x7a (8)    goto 14

	match 7


state 51
	0x00 - 0x09 (10)   goto 22
	0x0b - 0x21 (23)   goto 22
	0x22               goto 23
	0x23 - 0x2f (13)   goto 22
	0x30 - 0x37 (8)    goto 22
	0x38 - 0x5b (36)   goto 22
	0x5c               goto 24
	0x5d - 0xff (163)  goto 22


state 52
	0x00 - 0x09 (10)   goto 22
	0x0b - 0x21 (23)   goto 22
	0x22               goto 23
	0x23 - 0x2f (13)   goto 22
	0x30 - 0x39 (10)   goto 52
	0x3a - 0x40 (7)    goto 22
	0x41 - 0x46 (6)    goto 52
	0x47 - 0x5b (21)   goto 22
	0x5c               goto 24
	0x5d - 0x60 (4)    goto 22
	0x61 - 0x66 (6)    goto 52
	0x67 - 0xff (153)  goto 22


state 53
	0x00 - 0x09 (10)   goto 25
	0x0b - 0x21 (23)   goto 25
	0x23 - 0x26 (4)    goto 25
	0x27               goto 26
	0x28 - 0x2f (8)    goto 25
	0x30 - 0x37 (8)    goto 25
	0x38 - 0x5b (36)   goto 25
	0x5c               goto 27
	0x5d - 0xff (163)  goto 25


state 54
	0x00 - 0x09 (10)   goto 25
	0x0b - 0x21 (23)   goto 25
	0x23 - 0x26 (4)    goto 25
	0x27               goto 26
	0x28 - 0x2f (8)    goto 25
	0x30 - 0x39 (10)   goto 54
	0x3a - 0x40 (7)    goto 25
	0x41 - 0x46 (6)    goto 54
	0x47 - 0x5b (21)   goto 25
	0x5c               goto 27
	0x5d - 0x60 (4)    goto 25
	0x61 - 0x66 (6)    goto 54
	0x67 - 0xff (153)  goto 25


state 55
	0x30 - 0x39 (10)   goto 62


state 56
	0x30 - 0x39 (10)   goto 63


state 57
	0x30 - 0x39 (10)   goto 14
	0x41 - 0x5a (26)   goto 14
	0x5f               goto 14
	0x61 - 0x62 (2)    goto 14
	0x63               goto 64
	0x64 - 0x7a (23)   goto 14

	match 7


state 58
	0x30 - 0x39 (10)   goto 14
	0x41 - 0x5a (26)   goto 14
	0x5f               goto 14
	0x61 - 0x7a (26)   goto 14

	match 5


state 59
	0x30 - 0x39 (10)   goto 14
	0x41 - 0x5a (26)   goto 14
	0x5f               goto 14
	0x61               goto 65
	0x62 - 0x7a (25)   goto 14

	match 7


state 60
	0x30 - 0x39 (10)   goto 14
	0x41 - 0x5a (26)   goto 14
	0x5f               goto 14
	0x61 - 0x6e (14)   goto 14
	0x6f               goto 66
	0x70 - 0x7a (11)   goto 14

	match 7


state 61
	0x30 - 0x39 (10)   goto 14
	0x41 - 0x5a (26)   goto 14
	0x5f               goto 14
	0x61 - 0x73 (19)   goto 14
	0x74               goto 67
	0x75 - 0x7a (6)    goto 14

	match 7


state 62
	0x30 - 0x39 (10)   goto 62

	match 12


state 63
	0x30 - 0x39 (10)   goto 63

	match 11


state 64
	0x30 - 0x39 (10)   goto 14
	0x41 - 0x5a (26)   goto 14
	0x5f               goto 14
	0x61 - 0x73 (19)   goto 14
	0x74               goto 68
	0x75 - 0x7a (6)    goto 14

	match 7


state 65
	0x30 - 0x39 (10)   goto 14
	0x41 - 0x5a (26)   goto 14
	0x5f               goto 14
	0x61 - 0x73 (19)   goto 14
	0x74               goto 69
	0x75 - 0x7a (6)    goto 14

	match 7


state 66
	0x30 - 0x39 (10)   goto 14
	0x41 - 0x5a (26)   goto 14
	0x5f               goto 14
	0x61 - 0x6d (13)   goto 14
	0x6e               goto 70
	0x6f - 0x7a (12)   goto 14

	match 7


state 67
	0x30 - 0x39 (10)   goto 14
	0x41 - 0x5a (26)   goto 14
	0x5f               goto 14
	0x61 - 0x7a (26)   goto 14

	match 4


state 68
	0x30 - 0x39 (10)   goto 14
	0x41 - 0x5a (26)   goto 14
	0x5f               goto 14
	0x61 - 0x72 (18)   goto 14
	0x73               goto 71
	0x74 - 0x7a (7)    goto 14

	match 7


state 69
	0x30 - 0x39 (10)   goto 14
	0x41 - 0x5a (26)   goto 14
	0x5f               goto 14
	0x61 - 0x6e (14)   goto 14
	0x6f               goto 72
	0x70 - 0x7a (11)   goto 14

	match 7


state 70
	0x30 - 0x39 (10)   goto 14
	0x41 - 0x5a (26)   goto 14
	0x5f               goto 14
	0x61 - 0x63 (3)    goto 14
	0x64               goto 73
	0x65 - 0x7a (22)   goto 14

	match 7


state 71
	0x30 - 0x39 (10)   goto 14
	0x41 - 0x5a (26)   goto 14
	0x5f               goto 14
	0x61 - 0x7a (26)   goto 14

	match 3


state 72
	0x30 - 0x39 (10)   goto 14
	0x41 - 0x5a (26)   goto 14
	0x5f               goto 14
	0x61 - 0x71 (17)   goto 14
	0x72               goto 74
	0x73 - 0x7a (8)    goto 14

	match 7


state 73
	0x30 - 0x39 (10)   goto 14
	0x41 - 0x5a (26)   goto 14
	0x5f               goto 14
	0x61 - 0x72 (18)   goto 14
	0x73               goto 75
	0x74 - 0x7a (7)    goto 14

	match 7


state 74
	0x30 - 0x39 (10)   goto 14
	0x41 - 0x5a (26)   goto 14
	0x5f               goto 14
	0x61 - 0x7a (26)   goto 14

	match 1


state 75
	0x30 - 0x39 (10)   goto 14
	0x41 - 0x5a (26)   goto 14
	0x5f               goto 14
	0x61 - 0x7a (26)   goto 14

	match 2


state 76
	0x00 - 0x09 (10)   goto 76
	0x0b - 0x29 (31)   goto 76
	0x2b - 0xff (213)  goto 76

	match 16


state 77
	match 17


state 78
	0x2f               goto 79

	match 18


state 79
	match 15


state 80
	match 20


#############################################################################
# Summary
#############################################################################

3 start state(s)
21 expression(s), 80 state(s)


#############################################################################
# End of File
#############################################################################
