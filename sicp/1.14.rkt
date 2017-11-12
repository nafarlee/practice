#lang sicp

(define (count-change amount)
  (cc amount 5))

(define (cc amount kinds-of-coins)
  (cond ((= amount 0) 1)
        ((or (< amount 0) 
             (= kinds-of-coins 0)) 
         0)
        (else 
         (+ (cc amount (- kinds-of-coins 1))
            (cc (- amount (first-denomination 
                           kinds-of-coins))
                kinds-of-coins)))))

(define (first-denomination kinds-of-coins)
  (cond ((= kinds-of-coins 1) 1)
        ((= kinds-of-coins 2) 5)
        ((= kinds-of-coins 3) 10)
        ((= kinds-of-coins 4) 25)
        ((= kinds-of-coins 5) 50)))

; Space - The calls are evaluated depth-first, meaning that the maximum space
; that is needed is the call stack at the deepest point in the tree. The max
; depth reached by a call to count-change scales linearly with n, and in fact
; is always equal to n + kinds-of-coins if the root node is considered depth 1.
; As a result, the order of space growth is O(n).
;
; Steps - For a call (cc n k) where k = 1, the number of steps required is
; 2n + 1. This would have order O(n).
;
; For a call (cc n k) where k = 2, this recurses to create ceil(n / 5) (cc n 1)
; call trees, where each has order O(n). n/5 * O(n) results in O(n^2).
;
; For a call (cc n k) where k = 3, this recurses to create ceil(n / 10) (cc n 2)
; call trees, where each has order O(n^2). n/10 * O(n^2) results in O(n^3).
;
; This pattern continues as k increases, where a call (cc n k) recurses to
; create O(n) (cc n (- k 1)) call trees, where a call tree (cc n (- k 1)) has
; O(n^(k-1)). O(n) * O(n^(k-1)) results in O(n^k). As such, for count-change
; (where k is always assumed to 5), the order is O(n^5).
