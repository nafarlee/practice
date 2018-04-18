(ns cbt.5-3)

(defn assoc-in'
  [m [k & ks] v]
    (if (empty? ks)
      (assoc m k v)
      (assoc m k (assoc-in' (get m k) ks v))))
