(define (fast-expt b n)
  (cond ((= n 0) 1)
        ((even? n) 
         (square (fast-expt b (/ n 2))))
        (else 
         (* b (fast-expt b (- n 1))))))

(define (expmod base exp m)
  (cond ((= exp 0) 1)
        ((even? exp) (remainder (square (expmod base
                                                (/ exp 2)
                                                m))
                                m))
        (else (remainder (* base
                            (expmod base
                                    (- exp 1)
                                    m))
                         m))))

(define (expmod base exp m)
  (remainder (fast-expt base exp) m))

; The modification made actually makes expmod much slower. This is because the previous version
; was applying remainder operations between each recursion, preventing b^n from getting arbitrarily
; large. In this version, in many cases, arbitrary-precision numbers are needed, which are quite
; slow.
