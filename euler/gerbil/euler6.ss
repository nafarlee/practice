#!/usr/bin/env gxi
(import
  (only-in :std/iter iter-end
                     yield
                     iter
                     in-coroutine
                     in-naturals
                     for
                     for/fold))
(export main)

(def (iter-take-while pred iterable)
  (in-coroutine
    (lambda ()
      (for (x (iter iterable))
        (if (pred x)
          (yield x)
          (yield iter-end))))))

(def (take-100)
  (iter-take-while (cut <= <> 100) (in-naturals)))

(def (main . args)
  (displayln
   (-
    (expt (for/fold (sum 0) (x (take-100))
            (+ sum x))
          2)
    (for/fold (sum 0) (x (take-100))
      (+ sum (expt x 2))))))
