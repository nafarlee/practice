#lang sicp

(define (cont-frac n d k)
  (define (recur c) 
    (if (> c k)
      0
      (/ (n c)
         (+ (d c)
            (recur (inc c))))))
  (recur 1))

(define (cont-frac-iter n d k)
  (define (recur c result)
    (if (= c 0)
      result
      (recur (dec c)
             (/ (n c)
                (+ (d c) result)))))
  (recur k 0))

(/ 1
   (cont-frac-iter (lambda (i) 1.0)
                   (lambda (i) 1.0)
                   12))

; k must greater than 11 to get accuracy to 4 decimal places
; k = 11
; 1.617977528089887
; k = 12
; 1.6180555555555558
