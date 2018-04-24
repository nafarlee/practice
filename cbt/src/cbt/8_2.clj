(ns cbt.8-2)

(defmacro or*
  ([] nil)
  ([x] x)
  ([x & xs]
    `(let [result# ~x]
       (if result# result# (or ~@xs)))))
