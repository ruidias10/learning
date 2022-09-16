from django.http import HttpResponse
from django.shortcuts import render


def home(request):
    return render(request, 'recipes/pages/home.html', context={
        'name': 'Rui Dias',
    })

# def home_old(request):
#    return HttpResponse('''<!DOCTYPE>
#    <html>
#        <h1>Home</h1>
#    </html>
#    ''')

# def sobre(request):
#    return HttpResponse('<h1>Sobre</h1>')
