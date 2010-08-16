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
# OperatorParser.v
# YACC verbose file generated from OperatorParser.y.
# 
# Date: 12/27/03
# Time: 19:58:52
# 
# AYACC Version: 2.05
#############################################################################


##############################################################################
# Rules
##############################################################################

    0  $accept : Grammar $end

    1  Grammar : Facts
    2          | Operator_List
    3          | Facts Operator_List

    4  Facts : Start Goal

    5  Start : START '(' Predicate_List ')'

    6  Goal : GOAL '(' Predicate_List ')'

    7  Operator_List : Operator_List Operator
    8                | Operator

    9  Operator : OPERATOR IDENTIFIER '(' Term_List ')' Preconditions Effects
   10           | OPERATOR IDENTIFIER Preconditions Effects

   11  Preconditions : PRECONDS '(' Predicate_List ')'
   12                |

   13  Effects : EFFECTS '(' Predicate_List ')'
   14          |

   15  Predicate_List : Predicate_List ',' Predicate
   16                 | Predicate

   17  Predicate : IDENTIFIER '(' Term_List ')'
   18            | IDENTIFIER
   19            | Not IDENTIFIER '(' Term_List ')'
   20            | Not IDENTIFIER
   21            | Not '(' IDENTIFIER '(' Term_List ')' ')'
   22            | Not '(' IDENTIFIER ')'

   23  Not : NOT
   24      | '-'

   25  Term_List : Term_List ',' Term
   26            | Term

   27  Term : IDENTIFIER
   28       | STRING
   29       | NUMBER
   30       | IDENTIFIER '(' Term_List ')'


##############################################################################
# States
##############################################################################

state 0
	$accept : . Grammar $end

	OPERATOR  shift 1
	START  shift 2

	Start  goto 3
	Operator_List  goto 4
	Operator  goto 5
	Grammar  goto 6
	Facts  goto 7


state 1
	Operator : OPERATOR . IDENTIFIER '(' Term_List ')' Preconditions Effects
	Operator : OPERATOR . IDENTIFIER Preconditions Effects

	IDENTIFIER  shift 8


state 2
	Start : START . '(' Predicate_List ')'

	'('  shift 9


state 3
	Facts : Start . Goal

	GOAL  shift 10

	Goal  goto 11


state 4
	Grammar : Operator_List .  (2)
	Operator_List : Operator_List . Operator

	OPERATOR  shift 1
	.  reduce 2

	Operator  goto 12


state 5
	Operator_List : Operator .  (8)

	.  reduce 8


state 6
	$accept : Grammar . $end  (0)

	$end  accept


state 7
	Grammar : Facts .  (1)
	Grammar : Facts . Operator_List

	OPERATOR  shift 1
	.  reduce 1

	Operator_List  goto 13
	Operator  goto 5


state 8
	Operator : OPERATOR IDENTIFIER . '(' Term_List ')' Preconditions Effects
	Operator : OPERATOR IDENTIFIER . Preconditions Effects
	Preconditions : .  (12)

	'('  shift 14
	PRECONDS  shift 15
	.  reduce 12

	Preconditions  goto 16


state 9
	Start : START '(' . Predicate_List ')'

	'-'  shift 17
	IDENTIFIER  shift 18
	NOT  shift 19

	Predicate_List  goto 20
	Predicate  goto 21
	Not  goto 22


state 10
	Goal : GOAL . '(' Predicate_List ')'

	'('  shift 23


state 11
	Facts : Start Goal .  (4)

	.  reduce 4


state 12
	Operator_List : Operator_List Operator .  (7)

	.  reduce 7


state 13
	Grammar : Facts Operator_List .  (3)
	Operator_List : Operator_List . Operator

	OPERATOR  shift 1
	.  reduce 3

	Operator  goto 12


state 14
	Operator : OPERATOR IDENTIFIER '(' . Term_List ')' Preconditions Effects

	STRING  shift 24
	NUMBER  shift 25
	IDENTIFIER  shift 26

	Term_List  goto 27
	Term  goto 28


state 15
	Preconditions : PRECONDS . '(' Predicate_List ')'

	'('  shift 29


state 16
	Operator : OPERATOR IDENTIFIER Preconditions . Effects
	Effects : .  (14)

	EFFECTS  shift 30
	.  reduce 14

	Effects  goto 31


state 17
	Not : '-' .  (24)

	.  reduce 24


state 18
	Predicate : IDENTIFIER . '(' Term_List ')'
	Predicate : IDENTIFIER .  (18)

	'('  shift 32
	.  reduce 18


state 19
	Not : NOT .  (23)

	.  reduce 23


state 20
	Start : START '(' Predicate_List . ')'
	Predicate_List : Predicate_List . ',' Predicate

	')'  shift 33
	','  shift 34


state 21
	Predicate_List : Predicate .  (16)

	.  reduce 16


state 22
	Predicate : Not . IDENTIFIER '(' Term_List ')'
	Predicate : Not . IDENTIFIER
	Predicate : Not . '(' IDENTIFIER '(' Term_List ')' ')'
	Predicate : Not . '(' IDENTIFIER ')'

	'('  shift 35
	IDENTIFIER  shift 36


state 23
	Goal : GOAL '(' . Predicate_List ')'

	'-'  shift 17
	IDENTIFIER  shift 18
	NOT  shift 19

	Predicate_List  goto 37
	Predicate  goto 21
	Not  goto 22


state 24
	Term : STRING .  (28)

	.  reduce 28


state 25
	Term : NUMBER .  (29)

	.  reduce 29


state 26
	Term : IDENTIFIER .  (27)
	Term : IDENTIFIER . '(' Term_List ')'

	'('  shift 38
	.  reduce 27


state 27
	Operator : OPERATOR IDENTIFIER '(' Term_List . ')' Preconditions Effects
	Term_List : Term_List . ',' Term

	')'  shift 39
	','  shift 40


state 28
	Term_List : Term .  (26)

	.  reduce 26


state 29
	Preconditions : PRECONDS '(' . Predicate_List ')'

	'-'  shift 17
	IDENTIFIER  shift 18
	NOT  shift 19

	Predicate_List  goto 41
	Predicate  goto 21
	Not  goto 22


state 30
	Effects : EFFECTS . '(' Predicate_List ')'

	'('  shift 42


state 31
	Operator : OPERATOR IDENTIFIER Preconditions Effects .  (10)

	.  reduce 10


state 32
	Predicate : IDENTIFIER '(' . Term_List ')'

	STRING  shift 24
	NUMBER  shift 25
	IDENTIFIER  shift 26

	Term_List  goto 43
	Term  goto 28


state 33
	Start : START '(' Predicate_List ')' .  (5)

	.  reduce 5


state 34
	Predicate_List : Predicate_List ',' . Predicate

	'-'  shift 17
	IDENTIFIER  shift 18
	NOT  shift 19

	Predicate  goto 44
	Not  goto 22


state 35
	Predicate : Not '(' . IDENTIFIER '(' Term_List ')' ')'
	Predicate : Not '(' . IDENTIFIER ')'

	IDENTIFIER  shift 45


state 36
	Predicate : Not IDENTIFIER . '(' Term_List ')'
	Predicate : Not IDENTIFIER .  (20)

	'('  shift 46
	.  reduce 20


state 37
	Goal : GOAL '(' Predicate_List . ')'
	Predicate_List : Predicate_List . ',' Predicate

	')'  shift 47
	','  shift 34


state 38
	Term : IDENTIFIER '(' . Term_List ')'

	STRING  shift 24
	NUMBER  shift 25
	IDENTIFIER  shift 26

	Term_List  goto 48
	Term  goto 28


state 39
	Operator : OPERATOR IDENTIFIER '(' Term_List ')' . Preconditions Effects
	Preconditions : .  (12)

	PRECONDS  shift 15
	.  reduce 12

	Preconditions  goto 49


state 40
	Term_List : Term_List ',' . Term

	STRING  shift 24
	NUMBER  shift 25
	IDENTIFIER  shift 26

	Term  goto 50


state 41
	Preconditions : PRECONDS '(' Predicate_List . ')'
	Predicate_List : Predicate_List . ',' Predicate

	')'  shift 51
	','  shift 34


state 42
	Effects : EFFECTS '(' . Predicate_List ')'

	'-'  shift 17
	IDENTIFIER  shift 18
	NOT  shift 19

	Predicate_List  goto 52
	Predicate  goto 21
	Not  goto 22


state 43
	Predicate : IDENTIFIER '(' Term_List . ')'
	Term_List : Term_List . ',' Term

	')'  shift 53
	','  shift 40


state 44
	Predicate_List : Predicate_List ',' Predicate .  (15)

	.  reduce 15


state 45
	Predicate : Not '(' IDENTIFIER . '(' Term_List ')' ')'
	Predicate : Not '(' IDENTIFIER . ')'

	'('  shift 54
	')'  shift 55


state 46
	Predicate : Not IDENTIFIER '(' . Term_List ')'

	STRING  shift 24
	NUMBER  shift 25
	IDENTIFIER  shift 26

	Term_List  goto 56
	Term  goto 28


state 47
	Goal : GOAL '(' Predicate_List ')' .  (6)

	.  reduce 6


state 48
	Term_List : Term_List . ',' Term
	Term : IDENTIFIER '(' Term_List . ')'

	')'  shift 57
	','  shift 40


state 49
	Operator : OPERATOR IDENTIFIER '(' Term_List ')' Preconditions . Effects
	Effects : .  (14)

	EFFECTS  shift 30
	.  reduce 14

	Effects  goto 58


state 50
	Term_List : Term_List ',' Term .  (25)

	.  reduce 25


state 51
	Preconditions : PRECONDS '(' Predicate_List ')' .  (11)

	.  reduce 11


state 52
	Effects : EFFECTS '(' Predicate_List . ')'
	Predicate_List : Predicate_List . ',' Predicate

	')'  shift 59
	','  shift 34


state 53
	Predicate : IDENTIFIER '(' Term_List ')' .  (17)

	.  reduce 17


state 54
	Predicate : Not '(' IDENTIFIER '(' . Term_List ')' ')'

	STRING  shift 24
	NUMBER  shift 25
	IDENTIFIER  shift 26

	Term_List  goto 60
	Term  goto 28


state 55
	Predicate : Not '(' IDENTIFIER ')' .  (22)

	.  reduce 22


state 56
	Predicate : Not IDENTIFIER '(' Term_List . ')'
	Term_List : Term_List . ',' Term

	')'  shift 61
	','  shift 40


state 57
	Term : IDENTIFIER '(' Term_List ')' .  (30)

	.  reduce 30


state 58
	Operator : OPERATOR IDENTIFIER '(' Term_List ')' Preconditions Effects .  (9)

	.  reduce 9


state 59
	Effects : EFFECTS '(' Predicate_List ')' .  (13)

	.  reduce 13


state 60
	Predicate : Not '(' IDENTIFIER '(' Term_List . ')' ')'
	Term_List : Term_List . ',' Term

	')'  shift 62
	','  shift 40


state 61
	Predicate : Not IDENTIFIER '(' Term_List ')' .  (19)

	.  reduce 19


state 62
	Predicate : Not '(' IDENTIFIER '(' Term_List ')' . ')'

	')'  shift 63


state 63
	Predicate : Not '(' IDENTIFIER '(' Term_List ')' ')' .  (21)

	.  reduce 21


##############################################################################
# Summary
##############################################################################

15 token(s), 14 nonterminal(s)
31 grammar rule(s), 64 state(s)


##############################################################################
# End of File
##############################################################################
