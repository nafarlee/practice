(ns cbt.9-1
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
  [term]
  (let [winner (promise)]
    (doseq [f [google-search bing-search]]
      (future (deliver winner (f term))))
    @winner))
