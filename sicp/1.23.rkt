#lang sicp

(define (square x) (* x x))

(define (smallest-divisor n) (find-divisor n 2))

(define (find-divisor n test-divisor)
  (cond
    ((> (square test-divisor) n) n)
    ((divides? test-divisor n) test-divisor)
    (else (find-divisor n (next test-divisor)))))

(define (next n)
  (if (= n 2)
    3
    (+ n 2)))

(define (divides? a b)
  (= (remainder b a) 0))

(define (prime? n)
  (= n (smallest-divisor n)))

(define (timed-prime-test n)
  (newline)
  (display n)
  (start-prime-test n (runtime)))

(define (start-prime-test n start-time)
  (if (prime? n)
      (report-prime (- (runtime) start-time))))

(define (report-prime elapsed-time)
  (display " *** ")
  (display elapsed-time))

(define (search-for-primes lower upper)
  (define (recur current)
    (if (<= current upper)
      (begin
        (timed-prime-test current)
        (recur (+ 2 current)))))
  (recur (if (even? lower)
           (inc lower)
           lower)))

; Bounds adjusted to account for increase in generally available computing
; speed

(search-for-primes 10000000 10000103)
; 10000001
; 10000003
; 10000005
; 10000007
; 10000009
; 10000011
; 10000013
; 10000015
; 10000017
; 10000019 *** 33
; 10000021
; 10000023
; 10000025
; 10000027
; 10000029
; 10000031
; 10000033
; 10000035
; 10000037
; 10000039
; 10000041
; 10000043
; 10000045
; 10000047
; 10000049
; 10000051
; 10000053
; 10000055
; 10000057
; 10000059
; 10000061
; 10000063
; 10000065
; 10000067
; 10000069
; 10000071
; 10000073
; 10000075
; 10000077
; 10000079 *** 32
; 10000081
; 10000083
; 10000085
; 10000087
; 10000089
; 10000091
; 10000093
; 10000095
; 10000097
; 10000099
; 10000101
; 10000103 *** 26

(search-for-primes 100000000 100000039)
; 100000001
; 100000003
; 100000005
; 100000007 *** 82
; 100000009
; 100000011
; 100000013
; 100000015
; 100000017
; 100000019
; 100000021
; 100000023
; 100000025
; 100000027
; 100000029
; 100000031
; 100000033
; 100000035
; 100000037 *** 82
; 100000039 *** 81

(search-for-primes 1000000000 1000000021)
; 1000000001
; 1000000003
; 1000000005
; 1000000007 *** 263
; 1000000009 *** 256
; 1000000011
; 1000000013
; 1000000015
; 1000000017
; 1000000019
; 1000000021 *** 256

; 1.22 Average time for first trials: 54.7
; 1.23 Average time for first trials: 30.3
; Roughly 45% speedup

; 1.22 Average time for second trials: 158
; 1.23 Average time for second trials: 81.67
; Roughly a 48% speedup

; 1.22 Average time for third trials: 501.33
; 1.23 Average time for third trials: 258.33
; Roughly a 48% speedup

; Though there is a slight margin of error, the tests now run roughly twice as fast. This margin of
; error could most likely be explained by the "static" steps of the process that were not cut in
; half via the aformentioned modification.
