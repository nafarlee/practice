(ns cbt.9-3
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

(defn bing-parse
  [html]
  (->> html
       (re-seq #"<cite.*?>([\s\S]+?)</cite>")
       (map second)
       (map #(clojure.string/replace % #"</?strong>" ""))
       ))

(def google-search
  (partial base-search
           "https://www.google.com/search?hl=en&q="))

(defn google-parse
  [html]
  (->> html
       (re-seq #"<cite.+?>(.+?)</cite>")
       (map second)))

(def engine-to-function {:Bing bing-search
                         :Google google-search})

(def engine-to-parser {:Bing bing-parse
                       :Google google-parse}) 

(defn hits
  [term engines]
  (let [searchers (map engine-to-function engines)
        parsers (map engine-to-parser engines)
        search-futures (map #(future (% term)) searchers)
        results (map #(%1 @%2) parsers search-futures)
        vecs (map vec results)]
    vecs))
