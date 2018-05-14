#lang sicp

; a' = bq + a(q + p)
; b' = bp + aq
; 
; a'' = b'q + a'(q + p)
; a'' = (bp + aq)q + (bq + a(q + p))(q + p)
; a'' = bpq + aq^2 + bq(q + p) + a(q + p)^2
; a'' = bpq + aq^2 + bq^2 + bqp + a(q + p)^2
; a'' = bpq + bq^2 + bqp + a(2q^2 + 2pq + p^2)
; a'' = b(pq + q^2 + qp) + a(2q^2 + 2pq + p^2)
; 
; b'' = b'p + a'q
; b'' = (bp + aq)p + (bq + a(q + p))q
; b'' = bp^2 + aqp + bq^2 + aq^2 + aqp
; b'' = bp^2 + bq^2 + aq^2 + aqp + aqp 
; b'' = b(p^2 + q^2) + a(q^2 + qp + qp)
; 
; p' = p^2 + q^2
; q' = q^2 + 2qp

(define (square x)
  (* x x))

(define (fib n)
  (fib-iter 1 0 0 1 n))

(define (fib-iter a b p q count)
  (cond ((= count 0) 
         b)
        ((even? count)
         (fib-iter a
                   b
                   (+ (square p) (square q))  ;compute p'
                   (+ (square q) (* 2 q p))  ;compute q'
                   (/ count 2)))
        (else 
         (fib-iter (+ (* b q) 
                      (* a q) 
                      (* a p))
                   (+ (* b p) 
                      (* a q))
                   p
                   q
                   (- count 1)))))
