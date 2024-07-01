#!/usr/bin/env gxi
(import (only-in :std/iter for for/fold yield in-coroutine iter-end iter))

(def (fib)
  (in-coroutine
    (lambda ()
      (yield 1)
      (yield 2)
      (let lp ((a 1)
               (b 2))
        (yield (+ a b))
        (lp b (+ a b))))))

(def (iter-take-while pred iterable)
  (in-coroutine
    (lambda ()
      (for (x (iter iterable))
        (if (pred x)
          (yield x)
          (yield iter-end))))))

(def (main . args)
  (displayln
    (for/fold (sum 0)
              ((x (iter-take-while (cut < <> 4000000) (fib)))
               when (even? x))
      (+ sum x))))
