(ns cbt.core
  (:require [cbt.3-1])
  (:require [cbt.3-2])
  (:require [cbt.3-3])
  (:require [cbt.3-4])
  (:require [cbt.3-5])
  (:require [cbt.3-6])
  (:require [cbt.4-1])
  (:require [cbt.4-2])
  (:gen-class))

(defn -main
  [& args]
  (-> (cbt.4-1/main)
      println))
