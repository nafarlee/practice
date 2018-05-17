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

(define (expmod base exp m)
  (cond ((= exp 0) 1)
        ((even? exp)
         (remainder 
          (square (expmod base (/ exp 2) m))
          m))
        (else
         (remainder 
          (* base (expmod base (- exp 1) m))
          m))))

(define (fermat-test n)
  (define (try-it a)
    (= (expmod a n n) a))
  (try-it (+ 1 (random (- n 1)))))

(define (fast-prime? n times)
  (cond ((= times 0) true)
        ((fermat-test n) 
         (fast-prime? n (- times 1)))
        (else false)))

(define (timed-prime-test n)
  (newline)
  (display n)
  (start-prime-test n (runtime)))

(define (start-prime-test n start-time)
  (if (fast-prime? n 10)
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
; 10000019 *** 173
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
; 10000079 *** 14
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
; 10000103 *** 12

(search-for-primes 1000000000 1000000021)
; 1000000001
; 1000000003
; 1000000005
; 1000000007 *** 16
; 1000000009 *** 16
; 1000000011
; 1000000013
; 1000000015
; 1000000017
; 1000000019
; 1000000021 *** 16

; Average completion time for first trials (not including outlier): 13
; log_2(10000000) = 23.3
; Average completion time for second trials: 16 
; log_2(1000000000) = 29.9

; 23.3 / 29.9 * 100 ~= 78%
; 13 / 16 * 100 ~= 81.25

; Based on this data, the increase in computation time required from the first trial to the second
; upholds the ratio that is to be expected from a O(logn) process.
