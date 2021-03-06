(ns cbt.4-4)

(def filename "suspects.csv")

(def vamp-keys [:name :glitter-index])

(defn str->int
  [str]
  (Integer. str))

(def conversions {:name identity :glitter-index str->int})

(defn convert
  [vamp-key value]
  ((get conversions vamp-key) value))

(defn parse
  "Convert a CSV into rows of columns"
  [string]
  (map #(clojure.string/split %
                              #",")
       (clojure.string/split string
                             #"\n")))

(defn mapify
  "Return a seq of maps like {:name \"Edward Cullen\" :glitter-index 10}"
  [rows]
  (map (fn [unmapped-row]
         (reduce (fn [row-map [vamp-key value]]
                   (assoc row-map
                          vamp-key
                          (convert vamp-key value)))
                 {}
                 (map vector vamp-keys unmapped-row)))
       rows))

(defn glitter-filter
  [minimum-glitter records]
  (->> records
       (filter #(>= (:glitter-index %)
                    minimum-glitter))
       (map :name)))

(defn validate
  [validators record]
  (every? #((second %) ((first %) record))
          validators))

(defn append
  [suspects new-suspect]
  (let [validators {:name string? :glitter-index integer?}]
    (if (validate validators new-suspect)
        (concat suspects [new-suspect])
        suspects)))

(defn serialize
  [suspects]
  (->> suspects
       (map #(str (:name %) ", " (:glitter-index %)))
       (clojure.string/join "\n")))

(defn main
  []
  (->> filename
      slurp
      parse
      mapify
      (glitter-filter 3)))
