import 'package:flutter/material.dart';

class PageAccueil extends StatelessWidget {
  const PageAccueil({super.key});

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: const Text("Accueil"),
        backgroundColor: Theme.of(context).colorScheme.primary,
        foregroundColor: Theme.of(context).colorScheme.surface,
      ),
      drawer: const Drawer(
        child: Column(
          children: [
          DrawerHeader(child: Icon(
            Icons.menu_book,
            size:48,
          ),),
          ListTile(
            leading: Icon(Icons.home_outlined),
            title: Text("Accueil"),
          ),
          ListTile(
            leading: Icon(Icons.favorite_outline),
            title: Text("Favoris"),
          )
          ]
        ),
      ),
    );

  }
}