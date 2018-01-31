;; this is how to load external modules in scheme
(load-from-path "/afs/nd.edu/user37/cmc/Public/paradigms/scheme/d1/paradigms_d1.scm")
(use-modules (ice-9 paradigms_d1))

;; Samantha Scaglione

;; the list q
;; notice it has a ' in front of the list; that tells the interpreter to read
;; the list literally (e.g., as atoms, instead of functions)
(define q '(turkey (gravy) (stuffing potatoes ham) peas))

;; question 1
(display "question 1: ")
(display (atom? (car (cdr (cdr q)))))
(display "\n")
;; output: #f
;; (copy the output you saw here)
;;
;; explanation:
;;	#f is a special atom which means false
;;	it displayed here because cdr removes
;;	the head of the list and returns the
;;	rest of the list, so the first cdr
;;	returns ((gravy) (stuffing potatoes ham) peas)
;;	then the second cdr does the same and returns
;;	((stuffing potatoes ham) peas) then the car
;;	removes the tail of the list and returns the
;;	rest so it returns ((stuffing potatoes ham))
;;	which is not an atom, so it returns false

;; question 2
(display "question 2: ")
(display (lat? (car (cdr (cdr q)))))
(display "\n")
;; output: #t
;;
;;
;; explanation: 
;;	(car (cdr (cdr q))) returns the same as above
;;	((stuffing potatoes ham)) which is true this
;; 	time since it is in fact a list of atoms


;; question 3
(display "question 3: ")
(display (cond ((atom? (car q)) (car q)) (else '())))
(display "\n")
;; output: turkey
;;
;;
;; explanation:
;;	cond ((atom? (car q)) works on the condition
;;	that car q is an atom; since car q returns
;;	((gravy) (stuffing potatoes ham) peas) which
;; 	is not an atom- it's a list of atoms and lists
;;	of atoms, so it moves on to the display statement
;;	and returns what was cut with cat- turkey

