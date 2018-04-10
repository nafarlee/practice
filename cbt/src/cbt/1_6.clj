(ns cbt.1-6)

(def asym-hobbit-body-parts [{:name "head" :size 3}
                             {:name "left-eye" :size 1}
                             {:name "left-ear" :size 1}
                             {:name "mouth" :size 1}
                             {:name "nose" :size 1}
                             {:name "neck" :size 2}
                             {:name "left-shoulder" :size 3}
                             {:name "left-upper-arm" :size 3}
                             {:name "chest" :size 10}
                             {:name "back" :size 10}
                             {:name "left-forearm" :size 3}
                             {:name "abdomen" :size 6}
                             {:name "left-kidney" :size 1}
                             {:name "left-hand" :size 2}
                             {:name "left-knee" :size 2}
                             {:name "left-thigh" :size 4}
                             {:name "left-lower-leg" :size 3}
                             {:name "left-achilles" :size 1}
                             {:name "left-foot" :size 2}])

(defn numbered-part [part-name number]
  (clojure.string/replace part-name
                          #"^left-(.*)"
                          (str "$1-" number)))

(defn matching-parts [part num-match]
  (let [part-name (:name part)
        part-size (:size part)
        n (inc num-match)]
    (->> (range 1 n)
         (map #(hash-map :name (numbered-part part-name %)
                         :size part-size)))))

(defn best-symmetrize-body-parts [n]
  (->> asym-hobbit-body-parts
       (reduce #(concat %1 (matching-parts %2 n))
               '())
       set))
