#!/usr/bin/python

import graphlab as gl

train_data = gl.SFrame.read_csv('/home/max/Documents/learningmaterials/RS_project/graphlab/SimLargeResults.csv');

model = gl.ranking_factorization_recommender.create(train_data, 'user_id', 'item_id', 'performance', num_factors=1)

model.recommend(exclude_known = False)
