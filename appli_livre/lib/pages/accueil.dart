//import 'dart:ffi';

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
      drawer: menu(),
      body: Column(
        mainAxisSize: MainAxisSize.min,
        children: [
          const SizedBox(
            height: 16,
          ),
          const Center(
            child: Row(
              mainAxisAlignment: MainAxisAlignment.center,
              mainAxisSize: MainAxisSize.min,
              children: [
                SearchBar(
                  hintText: "Rechercher un titre",
                  //onSubmitted: Navigator.pushNamed(context, "/recherche"),
                ),
                Icon(Icons.search),
              ],
            ),
          ),
          const SizedBox(
            height: 32,
          ),
        ],
      ),
    );
  }

  Drawer menu() {
    return const Drawer(
      child: Column(children: [
        DrawerHeader(
          child: Icon(
            Icons.menu_book,
            size: 48,
          ),
        ),
        ListTile(
          leading: Icon(Icons.home_outlined),
          title: Text("Accueil"),
        ),
        ListTile(
          leading: Icon(Icons.favorite_outline),
          title: Text("Favoris"),
        )
      ]),
    );
  }

  /* Text filtre(BuildContext context){
    showDialog(
      context: context,
      builder: (context) {
        return AlertDialog(
          title: const Text("Filtrer par type de tags"),
          content: SizedBox(
            width: double.maxFinite,
            height: 300,
            child: ListView.builder(
              itemBuilder: (context, index) {
                return Text(index.toString());
              },
              itemCount: 3,
              /* itemCount: typeTags.length, // Nombre réel de types de tags
              itemBuilder: (context, index) {
                final typeTag = typeTags[index]; // Utilise un type réel de la liste

                return ListTile(
                  title: Text(typeTag.nomComplet), // Affiche le nom complet réel
                  onTap: () {
                    Navigator.pop(context);
                    _showTagSelectionDialog(context, typeTag);
                  },
                );
              }, */
            ),
          ),
          actions: [
            TextButton(
              onPressed: () {
                Navigator.pop(context);
              },
              child: const Text("Annuler", style: TextStyle(color: Colors.red),),
            ),
          ],
        );
      },
    );
  } */
}
