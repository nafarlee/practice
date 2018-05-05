(ns cbt.13-1)

(defmulti full-moon-behavior
  (fn [were-creature]
    (:were-type were-creature)))

(defmethod full-moon-behavior :bear
  [were-creature]
  (str (:name were-creature) " will probably eat salmon"))
