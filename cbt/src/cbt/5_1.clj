(ns cbt.5-1)

(def record {:attributes {:intelligence 1 }})

(defn attr
  [key-in]
  (comp key-in :attributes))
