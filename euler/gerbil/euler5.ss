#!/usr/bin/env gxi
(import
  (only-in :std/iter
           iter
           yield
           for
           in-coroutine
           in-naturals
           iter-next!
           iter-end?))
(export main)

(def (iter-map f iterable)
  (in-coroutine
    (lambda ()
      (for (x (iter iterable))
        (yield (f x))))))

(def (iter-find pred iterable)
  (def current (iter-next! iterable))
  (cond
    ((iter-end? current) #f)
    ((pred current) current)
    (else (iter-find pred iterable))))

(def (div-by? num denom)
  (zero? (modulo num denom)))

(def (every? pred l)
  (match l
    ([] #t)
    ([x . xs]
     (if (pred x)
       (every? pred xs)
       #f))))

(def (main . args)
  (displayln
    (iter-find
      (lambda (num)
        (every? (cut div-by? num <>) (iota 10 20 -1)))
      (iter-map (lambda (x) (* 19 20 (1+ x))) (in-naturals)))))
