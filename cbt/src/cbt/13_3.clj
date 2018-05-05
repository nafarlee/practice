(ns cbt.13-3)

(defprotocol Append
  "Add an item to the end of a collection"
  (append [coll a]))

(extend-type clojure.lang.PersistentList
  Append
    (append [coll a]
      (concat coll (list a))))

(extend-protocol Append
  clojure.lang.PersistentVector
    (append [coll a] (conj coll a))
  java.lang.String
    (append [coll a] (str coll a))
  clojure.lang.PersistentList$EmptyList
    (append [coll a] (list a)))
