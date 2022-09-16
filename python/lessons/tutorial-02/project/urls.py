"""project URL Configuration

The `urlpatterns` list routes URLs to views. For more information please see:
    https://docs.djangoproject.com/en/4.1/topics/http/urls/
Examples:
Function views
    1. Add an import:  from my_app import views
    2. Add a URL to urlpatterns:  path('', views.home, name='home')
Class-based views
    1. Add an import:  from other_app.views import Home
    2. Add a URL to urlpatterns:  path('', Home.as_view(), name='home')
Including another URLconf
    1. Import the include() function: from django.urls import include, path
    2. Add a URL to urlpatterns:  path('blog/', include('blog.urls'))
"""
from django.contrib import admin
from django.urls import include, path

# # from app_recipes.views import home, sobre
# # from django.http import HttpResponse

# HTTP REQUEST -> return HTTP RESPONSE
# def home_view(request):
#     return HttpResponse("Home")

# def sobre_view(request):
#     return HttpResponse("Sobre")


urlpatterns = [
    path('admin/', admin.site.urls),

    # # # dominio.com/
    path('', include('app_recipes.urls')),

    # # # dominio.com/app_recipes
    # # # path('recipes/', include('app_recipes.urls')),

    # path('', home_view),
    # path('sobre/', sobre_view),
    # # path('', home),
    # # path('sobre/', sobre),
]
