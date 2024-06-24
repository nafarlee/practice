#!/usr/bin/env gxi
(import (only-in :std/iter in-iota for/fold))

(def (multiple-5? x)
  (zero? (remainder x 5)))

(def (multiple-3? x)
  (zero? (remainder x 3)))

(def (main . args)
  (displayln
   (for/fold (sum 0) (x (in-iota 1000))
     (cond
      ((multiple-3? x) (+ sum x))
      ((multiple-5? x) (+ sum x))
      (else sum)))))
