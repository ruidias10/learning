from django.urls import path

# from app_recipes.views import home, sobre
# from app_recipes.views import home
from app_recipes import views

urlpatterns = [
    path('', views.home),
    # path('sobre/', sobre),
    path('recipes/<int:id>/', views.recipe),
]
