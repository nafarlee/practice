(define (expmod base exp m)
  (cond ((= exp 0) 1)
        ((even? exp)
         (remainder 
          (* (expmod base (/ exp 2) m)
             (expmod base (/ exp 2) m))
          m))
        (else
         (remainder 
          (* base 
             (expmod base (- exp 1) m))
          m))))

; This expmod is no longer linear recursive. Put another way, each invocation of expmod can
; potentially invoke expmod two more times, as opposed to just once. A single invocation can
; become 2, and each of those can split again recursively. This means the number of invocations
; is growing exponentially. Because this algorithm was O(logn) when it was linear recursive,
; it is O(n) now that it is exponentially recursive.
