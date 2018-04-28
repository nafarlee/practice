(ns cbt.9-2
  (:import [java.net URL]))

(def user-agent "Mozilla/5.0 (X11; Linux x86_64; rv:59.0) Gecko/20100101 Firefox/59.0")

(defn browser-slurp
  [url]
  (slurp
    (-> url
        URL.
        .openConnection
        (doto (.setRequestProperty "User-Agent" user-agent))
        .getInputStream)))

(defn base-search
  [url term]
  (->> term
       (str url)
       browser-slurp))

(def bing-search
  (partial base-search
           "https://www.bing.com/search?q="))

(def google-search
  (partial base-search
           "https://www.google.com/search?hl=en&q="))

(defn race-search
  [term search-fns]
  (let [winner (promise)]
    (doseq [f search-fns]
      (future (deliver winner (f term))))
    @winner))

(def engine-to-function {:Bing bing-search
                         :Google google-search})

(defn search
  [term engines]
  (->> engines
       (map #(% engine-to-function))
       (race-search term)))
