/* Inclusion des bibliothéques standards du C utilisées dans cette bibliothéque-ci */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Inclusion des bibliothéques internes à l'API */
#include "../application_des_decalages_horaires/application_des_decalages_horaires.h"
#include "affichage_de_l_horloge.h"
#include "../fonctions_d_affichage_et_de_renvoie_de_l_heure_et_de_la_date/fonctions_d_affichage_et_de_renvoie_de_l_heure_et_de_la_date.h"
#include "../bibliotheque_de_fonctions_utiles/bibliotheque_de_fonctions_utiles.h"

//Fonction qui affiche l'heure courante et la date courante en temps réel sur tous les fuseaux horaires du monde entier en simultané
/*
	Explication du calcul:

	Prenons un fuseau horaire quelconque noté zone_quelquonque/fuseau_horaire_quelquonque.

	Définissons, pour le fuseau horaire zone_quelquonque/fuseau_horaire_quelquonque, les régles suivantes:

	-> Sur le fuseau zone_quelquonque/fuseau_horaire_quelquonque: UTC+03:00 (heure d'hiver),

	-> Sur le fuseau zone_quelquonque/fuseau_horaire_quelquonque: UTC+04:00 (heure d'été).

	UTC étant la notation officielle pour "Universel Temps Coordonné": échelle de temps adoptée comme base du temps civil international par la majorité des pays du globe (wikipedia).

	Donc:

	-> heure_pour_fuseau_horaire_quelquonque = temps_utc_courant_en_temps_reel + (nombre_de_minutes_de_decalage_entre_l_utc_et_le_fuseau_horaire_quelquonque * nombre_de_secondes_dans_une_minute) + ((nombre_d_heure_de_decalage_entre_l_utc_et_le_fuseau_horaire_quelquonque * nombre_de_secondes_dans_une_heure) + (application_du_changement_d_heure_pour_le_fuseau_horaire_quelquonque * nombre_de_secondes_dans_une_heure))

	Avec:

	-> nombre_de_secondes_dans_une_heure = 3600 (une heure étant composée de 3600 secondes),

	-> nombre_de_secondes_dans_une_minute = 60 (une minute étant composée de 60 secondes).

	application_du_changement_d_heure_pour_le_fuseau_horaire_quelquonque est une fonction qui applique, pour le fuseau zone_quelquonque/fuseau_horaire_quelquonque, le changement d'heure (d'hiver à été et réciproquement) selon les régles établies par le pays, ou la zone géographique, dans lequel est situé le fuseau zone_quelquonque/fuseau_horaire_quelquonque.
*/
void affichage_de_l_horloge()
{

	/* Définition de la variable temps_utc et initialisation de celle-ci au temps utc sous forme de timestamp */
	time_t temps_utc = retour_du_temps_utc_sous_forme_de_timestamp();

	/* Calcul des horaires de différents villes du monde et affectation de la valeur calculée à une variable correspondante */

	/* République française */
	time_t heure_de_paris = temps_utc + (1 * 3600) + (application_du_changement_d_heure_pour_l_europe_continentale(temps_utc) * 3600); //Paris
	time_t heure_de_cayenne = temps_utc - (3 * 3600); //Cayenne
	time_t heure_de_la_reunion = temps_utc + (4 * 3600); //La Reunion
	time_t heure_de_la_guadeloupe = temps_utc - (4 * 3600); //Guadeloupe
	time_t heure_de_noumea = temps_utc + (11 * 3600); //Nouméa
	time_t heure_de_mayotte = temps_utc + (3 * 3600); //Mayotte_
	time_t heure_des_iles_kerguelen = temps_utc + (5 * 3600); //îles Kerguelen
	time_t heure_de_tahiti = temps_utc - (10 * 3600); //Tahiti
	time_t heure_de_gambier = temps_utc - (9 * 3600); //Gambier
	time_t heure_a_marquesas = temps_utc - (30 * 60) - (9 * 3600); //îles Marquises
	time_t heure_de_miquelon = temps_utc - ((3 * 3600) - (application_du_changement_d_heure_pour_l_amerique_du_nord(temps_utc) * 3600)); //Miquelon
	time_t heure_de_st_barthelemy = temps_utc - (4 * 3600); //St Barthélemy
	time_t heure_de_la_martinique = temps_utc - (4 * 3600); //La Martinique
	time_t heure_de_wallis = temps_utc + (12 * 3600); //Wallis et Futuna

	/* Principauté de Monaco */
	time_t heure_a_monaco = temps_utc + (1 * 3600) + (application_du_changement_d_heure_pour_l_europe_continentale(temps_utc) * 3600); //Monaco

	/* Royaume d'Espagne */
	time_t heure_a_madrid = temps_utc + (1 * 3600) + (application_du_changement_d_heure_pour_l_europe_continentale(temps_utc) * 3600); //Madrid
	time_t heure_a_ceuta = temps_utc + (1 * 3600) + (application_du_changement_d_heure_pour_l_europe_continentale(temps_utc) * 3600); //Ceuta
	time_t heure_aux_iles_canaries = temps_utc + (application_du_changement_d_heure_pour_l_europe_continentale(temps_utc) * 3600); //îles Canaries

	/* République portugaise */
	time_t heure_a_lisbonne = temps_utc + (application_du_changement_d_heure_pour_l_europe_continentale(temps_utc) * 3600); //Lisbonne
	time_t heure_aux_acores = temps_utc - ((1 * 3600) - (application_du_changement_d_heure_pour_l_europe_continentale(temps_utc) * 3600)); //Açores
	time_t heure_a_madere = temps_utc + (application_du_changement_d_heure_pour_l_europe_continentale(temps_utc) * 3600); //Madère

	/* Grand-Duché de Luxembourg */
	time_t heure_au_luxembourg = temps_utc + (1 * 3600) + (application_du_changement_d_heure_pour_l_europe_continentale(temps_utc) * 3600); //Luxembourg

	/* Royaume de Belgique */
	time_t heure_a_bruxelles = temps_utc + (1 * 3600) + (application_du_changement_d_heure_pour_l_europe_continentale(temps_utc) * 3600); //Bruxelles

	/* Royaume des Pays-Bas */
	time_t heure_d_amsterdam = temps_utc + (1 * 3600) + (application_du_changement_d_heure_pour_l_europe_continentale(temps_utc) * 3600); //Amsterdam
	time_t heure_d_aruba = temps_utc - (4 * 3600); //Aruba
	time_t heure_de_kralendijk = temps_utc - (4 * 3600); //Kralendijk
	time_t heure_de_curacao = temps_utc - (4 * 3600); //Curaçao
	time_t heure_a_lower_princes = temps_utc - (4 * 3600); //Lower Princes

	/* République fédérale d'Allemagne */
	time_t heure_de_berlin = temps_utc + (1 * 3600) + (application_du_changement_d_heure_pour_l_europe_continentale(temps_utc) * 3600); //Berlin
	time_t heure_de_busingen = temps_utc + (1 * 3600) + (application_du_changement_d_heure_pour_l_europe_continentale(temps_utc) * 3600); //Busingen

	/* Royaume de Danemark */
	time_t heure_a_copenhague = temps_utc + (1 * 3600) + (application_du_changement_d_heure_pour_l_europe_continentale(temps_utc) * 3600); //Copenhague
	time_t heure_aux_iles_feroes = temps_utc + (application_du_changement_d_heure_pour_l_europe_continentale(temps_utc) * 3600); // Iles Féroé
	time_t heure_a_scoresbysund = temps_utc - ((1 * 3600) - (application_du_changement_d_heure_pour_l_europe_continentale(temps_utc) * 3600)); //Scoresbysund
	time_t heure_a_godthab = temps_utc - ((3 * 3600) - (application_du_changement_d_heure_pour_l_europe_continentale(temps_utc) * 3600)); //Godthab
	time_t heure_a_thule = temps_utc - ((4 * 3600) - (application_du_changement_d_heure_pour_l_amerique_du_nord(temps_utc) * 3600)); //Thule
	time_t heure_a_danmarkshavn = temps_utc; //Danmarkshavn

	/* Royaume de Norvège */
	time_t heure_a_oslo = temps_utc + (1 * 3600) + (application_du_changement_d_heure_pour_l_europe_continentale(temps_utc) * 3600); //Oslo
	time_t heure_a_longyearbyen = temps_utc + (1 * 3600) + (application_du_changement_d_heure_pour_l_europe_continentale(temps_utc) * 3600); //Longyearbyen

	/* Royaume de Suède */
	time_t heure_a_stockholm = temps_utc + (1 * 3600) + (application_du_changement_d_heure_pour_l_europe_continentale(temps_utc) * 3600); //Stockholm

	/* République de Finlande */
	time_t heure_a_helsinki = temps_utc + (2 * 3600) + (application_du_changement_d_heure_pour_l_europe_continentale(temps_utc) * 3600); //Helsinki

	/* République d'Islande */
	time_t heure_a_reykjavik = temps_utc; //Reykjavik

	/* République de Pologne */
	time_t heure_a_varsovie = temps_utc + (1 * 3600) + (application_du_changement_d_heure_pour_l_europe_continentale(temps_utc) * 3600); //Varsovie

	/* République de Lituanie */
	time_t heure_a_vilnius = temps_utc + (2 * 3600) + (application_du_changement_d_heure_pour_l_europe_continentale(temps_utc) * 3600); //Vilnius

	/* République de Lettonie */
	time_t heure_a_riga = temps_utc + (2 * 3600) + (application_du_changement_d_heure_pour_l_europe_continentale(temps_utc) * 3600); //Riga

	/* République d’Estonie */
	time_t heure_a_tallinn = temps_utc + (2 * 3600) + (application_du_changement_d_heure_pour_l_europe_continentale(temps_utc) * 3600); //Tallinn

	/* République italienne */
	time_t heure_de_rome = temps_utc + (1 * 3600) + (application_du_changement_d_heure_pour_l_europe_continentale(temps_utc) * 3600); //Rome

	/* État de la Cité du Vatican */
	time_t heure_du_vatican = temps_utc + (1 * 3600) + (application_du_changement_d_heure_pour_l_europe_continentale(temps_utc) * 3600); //Vatican

	/* République de Saint-Marin */
	time_t heure_a_saint_marin = temps_utc + (1 * 3600) + (application_du_changement_d_heure_pour_l_europe_continentale(temps_utc) * 3600); //Saint-Marin

	/* République d'Autriche */
	time_t heure_de_vienne = temps_utc + (1 * 3600) + (application_du_changement_d_heure_pour_l_europe_continentale(temps_utc) * 3600); //Vienne

	/* Hongrie */
	time_t heure_a_budapest = temps_utc + (1 * 3600) + (application_du_changement_d_heure_pour_l_europe_continentale(temps_utc) * 3600); //Budapest

	/* République tchèque */
	time_t heure_a_prague = temps_utc + (1 * 3600) + (application_du_changement_d_heure_pour_l_europe_continentale(temps_utc) * 3600); //Prague

	/* République slovaque */
	time_t heure_a_bratislava = temps_utc + (1 * 3600) + (application_du_changement_d_heure_pour_l_europe_continentale(temps_utc) * 3600); //Bratislava

	/* Roumanie */
	time_t heure_a_bucarest = temps_utc + (2 * 3600) + (application_du_changement_d_heure_pour_l_europe_continentale(temps_utc) * 3600); //Bucarest

	/* République de Bulgarie */
	time_t heure_a_sofia = temps_utc + (2 * 3600) + (application_du_changement_d_heure_pour_l_europe_continentale(temps_utc) * 3600); //Sofia

	/* République de Macédoine du Nord */
	time_t heure_a_skopje = temps_utc + (1 * 3600) + (application_du_changement_d_heure_pour_l_europe_continentale(temps_utc) * 3600); //Skopje

	/* République de Slovénie */
	time_t heure_a_ljubljana = temps_utc + (1 * 3600) + (application_du_changement_d_heure_pour_l_europe_continentale(temps_utc) * 3600); //Ljubljana

	/* République de Croatie */
	time_t heure_a_zagreb = temps_utc + (1 * 3600) + (application_du_changement_d_heure_pour_l_europe_continentale(temps_utc) * 3600); //Zagreb

	/* Bosnie-Herzégovine */
	time_t heure_a_sarajevo = temps_utc + (1 * 3600) + (application_du_changement_d_heure_pour_l_europe_continentale(temps_utc) * 3600); //Sarajevo

	/* Monténégro */
	time_t heure_a_podgorica = temps_utc + (1 * 3600) + (application_du_changement_d_heure_pour_l_europe_continentale(temps_utc) * 3600); //Podgorica

	/* République de Serbie */
	time_t heure_a_belgrade = temps_utc + (1 * 3600) + (application_du_changement_d_heure_pour_l_europe_continentale(temps_utc) * 3600); //Belgrade

	/* République d'Albanie */
	time_t heure_a_tirane = temps_utc + (1 * 3600) + (application_du_changement_d_heure_pour_l_europe_continentale(temps_utc) * 3600); //Tirane

	/* République de Biélorussie */
	time_t heure_a_minsk = temps_utc + (3 * 3600); //Minsk

	/* Ukraine */
	time_t heure_a_kiev = temps_utc + (2 * 3600) + (application_du_changement_d_heure_pour_l_europe_continentale(temps_utc) * 3600); //Kiev
	time_t heure_a_uzhgorod = temps_utc + (2 * 3600) + (application_du_changement_d_heure_pour_l_europe_continentale(temps_utc) * 3600); //Uzhgorod
	time_t heure_a_zaporozhye = temps_utc + (2 * 3600) + (application_du_changement_d_heure_pour_l_europe_continentale(temps_utc) * 3600); //Zaporozhye

	/* République de Moldavie */
	time_t heure_a_chisinau = temps_utc + (2 * 3600) + (application_du_changement_d_heure_pour_l_europe_continentale(temps_utc) * 3600); //Chisinau

	/* Commonwealth des Bahamas */
	time_t heure_a_nassau = temps_utc - ((5 * 3600) - (application_du_changement_d_heure_pour_l_amerique_du_nord(temps_utc) * 3600)); //Nassau

	/* République du Suriname */
	time_t heure_a_paramaribo = temps_utc - (3 * 3600); //Paramaribo

	/* République coopérative du Guyana */
	time_t heure_a_guyana = temps_utc - (4 * 3600); //Guyana

	/* République de Trinité-et-Tobago */
	time_t heure_a_port_d_espagne = temps_utc - (4 * 3600); //Port d'Espagne

	/* Jamaïque */
	time_t heure_en_jamaique = temps_utc - (5 * 3600); //Jamaique

	/* République de Cuba */
	time_t heure_a_la_havane = temps_utc - ((5 * 3600) - (application_du_changement_d_heure_pour_l_amerique_du_nord(temps_utc) * 3600)); //La Havane

	/* États-Unis d'Amérique */
        time_t heure_los_angeles = temps_utc - ((8 * 3600) - (application_du_changement_d_heure_pour_l_amerique_du_nord(temps_utc) * 3600)); //Los Angeles
        time_t heure_de_nyc = temps_utc - ((5 * 3600) - (application_du_changement_d_heure_pour_l_amerique_du_nord(temps_utc) * 3600)); //New York City
        time_t heure_de_phoenix = temps_utc - (7 * 3600); //Phoenix
	time_t heure_a_honolulu = temps_utc - (10 * 3600); //Honolulu
	time_t heure_a_juneau = temps_utc  - ((9 * 3600) - (application_du_changement_d_heure_pour_l_amerique_du_nord(temps_utc) * 3600)); //Juneau
	time_t heure_a_yakutat = temps_utc  - ((9 * 3600) - (application_du_changement_d_heure_pour_l_amerique_du_nord(temps_utc) * 3600)); //Yakutat
	time_t heure_a_menominee = temps_utc - ((6 * 3600) - (application_du_changement_d_heure_pour_l_amerique_du_nord(temps_utc) * 3600)); //Menominee
	time_t heure_a_chicago = temps_utc - ((6 * 3600) - (application_du_changement_d_heure_pour_l_amerique_du_nord(temps_utc) * 3600)); //Chicago
	time_t heure_a_boise = temps_utc - ((7 * 3600) - (application_du_changement_d_heure_pour_l_amerique_du_nord(temps_utc) * 3600)); //Boise
	time_t heure_a_denver = temps_utc - ((7 * 3600) - (application_du_changement_d_heure_pour_l_amerique_du_nord(temps_utc) * 3600)); //Denvers
	time_t heure_a_anchorage = temps_utc - ((9 * 3600) - (application_du_changement_d_heure_pour_l_amerique_du_nord(temps_utc) * 3600)); //Anchorage
	time_t heure_a_detroit = temps_utc - ((5 * 3600) - (application_du_changement_d_heure_pour_l_amerique_du_nord(temps_utc) * 3600)); //Detroit
	time_t heure_a_metlakatla = temps_utc - ((9 * 3600) - (application_du_changement_d_heure_pour_l_amerique_du_nord(temps_utc) * 3600)); //Metlakatla
	time_t heure_a_sitka = temps_utc - ((9 * 3600) - (application_du_changement_d_heure_pour_l_amerique_du_nord(temps_utc) * 3600)); //Sitka
	time_t heure_a_nome = temps_utc - ((9 * 3600) - (application_du_changement_d_heure_pour_l_amerique_du_nord(temps_utc) * 3600)); //Nome
	time_t heure_a_adak = temps_utc - ((10 * 3600) - (application_du_changement_d_heure_pour_l_amerique_du_nord(temps_utc) * 3600)); //Adak
	time_t heure_a_kentucky_louiseville = temps_utc - ((5 * 3600) - (application_du_changement_d_heure_pour_l_amerique_du_nord(temps_utc) * 3600)); //Kentucky Louiseville
	time_t heure_a_kentucky_monticello = temps_utc - ((5 * 3600) - (application_du_changement_d_heure_pour_l_amerique_du_nord(temps_utc) * 3600)); //Kentucky Monticello
	time_t heure_a_indiana_winamac = temps_utc - ((5 * 3600) - (application_du_changement_d_heure_pour_l_amerique_du_nord(temps_utc) * 3600)); //Indiana Winamac
	time_t heure_a_indiana_vincennes = temps_utc - ((5 * 3600) - (application_du_changement_d_heure_pour_l_amerique_du_nord(temps_utc) * 3600)); //Indiana Vincennes
	time_t heure_a_indiana_vevay = temps_utc - ((5 * 3600) - (application_du_changement_d_heure_pour_l_amerique_du_nord(temps_utc) * 3600)); //Indiana Vevay
	time_t heure_a_indiana_petersburg = temps_utc - ((5 * 3600) - (application_du_changement_d_heure_pour_l_amerique_du_nord(temps_utc) * 3600)); //Indiana Petersburg
	time_t heure_a_indiana_marengo = temps_utc - ((5 * 3600) - (application_du_changement_d_heure_pour_l_amerique_du_nord(temps_utc) * 3600)); //Indiana Marengo
	time_t heure_a_indiana_indianapolis = temps_utc - ((5 * 3600) - (application_du_changement_d_heure_pour_l_amerique_du_nord(temps_utc) * 3600)); //Indiana Indianapolis
	time_t heure_a_north_dakota_new_salem = temps_utc - ((6 * 3600) - (application_du_changement_d_heure_pour_l_amerique_du_nord(temps_utc) * 3600)); //North Dakota New Salem
	time_t heure_a_north_dakota_center = temps_utc - ((6 * 3600) - (application_du_changement_d_heure_pour_l_amerique_du_nord(temps_utc) * 3600)); //North Dakota Center
	time_t heure_a_north_dakota_beulah = temps_utc - ((6 * 3600) - (application_du_changement_d_heure_pour_l_amerique_du_nord(temps_utc) * 3600)); //North Dakota Beulah
	time_t heure_a_indiana_tell_city = temps_utc - ((6 * 3600) - (application_du_changement_d_heure_pour_l_amerique_du_nord(temps_utc) * 3600)); //Indiana Tell City
	time_t heure_a_indiana_knox = temps_utc - ((6 * 3600) - (application_du_changement_d_heure_pour_l_amerique_du_nord(temps_utc) * 3600)); //Indiana Knox
	time_t heure_a_pago_pago = temps_utc - (11 * 3600); //Samoa américaines
	time_t heure_a_guam = temps_utc + (10 * 3600); //Guam
	time_t heure_a_wake = temps_utc + (12 * 3600); //Wake

	/* Dominion du Canada */
	time_t heure_de_toronto = temps_utc - ((5 * 3600) - (application_du_changement_d_heure_pour_l_amerique_du_nord(temps_utc) * 3600)); //Toronto
	time_t heure_d_atikokan = temps_utc - (5 * 3600); //Atikokan
	time_t heure_de_pangnirtung = temps_utc - ((5 * 3600) - (application_du_changement_d_heure_pour_l_amerique_du_nord(temps_utc) * 3600)); //Pangnirtung
	time_t heure_de_thunder_bay = temps_utc - ((5 * 3600) - (application_du_changement_d_heure_pour_l_amerique_du_nord(temps_utc) * 3600)); //Thunder Bay
	time_t heure_de_nipigon = temps_utc - ((5 * 3600) - (application_du_changement_d_heure_pour_l_amerique_du_nord(temps_utc) * 3600)); //Nipigon
	time_t heure_d_iqaluit = temps_utc - ((5 * 3600) - (application_du_changement_d_heure_pour_l_amerique_du_nord(temps_utc) * 3600)); //Iqaluit
	time_t heure_de_winnipeg = temps_utc - ((6 * 3600) - (application_du_changement_d_heure_pour_l_amerique_du_nord(temps_utc) * 3600)); //Winnipeg
	time_t heure_de_swift_current = temps_utc - (6 * 3600); //Swift Current
	time_t heure_de_resolute = temps_utc - ((6 * 3600) - (application_du_changement_d_heure_pour_l_amerique_du_nord(temps_utc) * 3600)); //Resolute
	time_t heure_de_regina = temps_utc - (6 * 3600); //Regina
	time_t heure_de_rankin_inlet = temps_utc - ((6 * 3600) - (application_du_changement_d_heure_pour_l_amerique_du_nord(temps_utc) * 3600)); //Rankin Inlet
	time_t heure_de_rainy_river = temps_utc - ((6 * 3600) - (application_du_changement_d_heure_pour_l_amerique_du_nord(temps_utc) * 3600)); //Rainy River
	time_t heure_de_whitehorse = temps_utc - ((8 * 3600) - (application_du_changement_d_heure_pour_l_amerique_du_nord(temps_utc) * 3600)); //Whitehorse
	time_t heure_de_vancouver = temps_utc - ((8 * 3600) - (application_du_changement_d_heure_pour_l_amerique_du_nord(temps_utc) * 3600)); //Vancouver
	time_t heure_de_dawson = temps_utc - ((8 * 3600) - (application_du_changement_d_heure_pour_l_amerique_du_nord(temps_utc) * 3600)); //Dawson
	time_t heure_de_st_johns = temps_utc - (30 * 60) - ((3 * 3600) - (application_du_changement_d_heure_pour_l_amerique_du_nord(temps_utc) * 3600)); //St Johns
	time_t heure_de_blanc_sablon = temps_utc - (4 * 3600); //Blanc-Sablon
	time_t heure_de_moncton = temps_utc - ((4 * 3600) - (application_du_changement_d_heure_pour_l_amerique_du_nord(temps_utc) * 3600)); //Moncton
	time_t heure_d_halifax = temps_utc - ((4 * 3600) - (application_du_changement_d_heure_pour_l_amerique_du_nord(temps_utc) * 3600)); //Halifax
	time_t heure_de_goose_bay = temps_utc - ((4 * 3600) - (application_du_changement_d_heure_pour_l_amerique_du_nord(temps_utc) * 3600)); //Goose Bay
	time_t heure_de_glace_bay = temps_utc - ((4 * 3600) - (application_du_changement_d_heure_pour_l_amerique_du_nord(temps_utc) * 3600)); //Glace Bay
	time_t heure_d_inuvik = temps_utc - ((7 * 3600) - (application_du_changement_d_heure_pour_l_amerique_du_nord(temps_utc) * 3600)); //Inuvik
	time_t heure_de_fort_nelson = temps_utc - (7 * 3600); //Fort Nelson
	time_t heure_d_edmonton = temps_utc - ((7 * 3600) - (application_du_changement_d_heure_pour_l_amerique_du_nord(temps_utc) * 3600)); //Edmonton
	time_t heure_de_dawson_creek = temps_utc - (7 * 3600); //Dawson Creek
	time_t heure_de_creston = temps_utc - (7 * 3600); //Creston
	time_t heure_de_cambridge_bay = temps_utc - ((7 * 3600) - (application_du_changement_d_heure_pour_l_amerique_du_nord(temps_utc) * 3600)); //Cambridge Bay
	time_t heure_d_yellowknife = temps_utc - ((7 * 3600) - (application_du_changement_d_heure_pour_l_amerique_du_nord(temps_utc) * 3600)); //Yellowknife

	/* République du Nicaragua */
	time_t heure_managua = temps_utc - (6 * 3600); //Managua

	/* République du Salvador */
	time_t heure_d_el_salvador = temps_utc - (6 * 3600); //Salvador

	/* Belize */
	time_t heure_au_belize = temps_utc - (6 * 3600); //Belize

	/* République du Costa Rica */
	time_t heure_au_costa_rica = temps_utc - (6 * 3600); //Costa Rica

	/* République du Honduras */
	time_t heure_au_honduras = temps_utc - (6 * 3600); //Tegucigalpa

	/* République du Guatemala */
	time_t heure_au_guatemala = temps_utc - (6 * 3600); //Guatemala

	/* Confédération suisse */
	time_t heure_zurich = temps_utc + (1 * 3600) + (application_du_changement_d_heure_pour_l_europe_continentale(temps_utc) * 3600); //Zurich

	/* République de Malte */
	time_t heure_malte = temps_utc + (1 * 3600) + (application_du_changement_d_heure_pour_l_europe_continentale(temps_utc) * 3600); //Malte

	/* Principauté d'Andorre */
	time_t heure_andorre = temps_utc + (1 * 3600) + (application_du_changement_d_heure_pour_l_europe_continentale(temps_utc) * 3600); //Andorre

	/* Principauté de Liechtenstein */
	time_t heure_vaduz = temps_utc + (1 * 3600) + (application_du_changement_d_heure_pour_l_europe_continentale(temps_utc) * 3600); //Vaduz

	/* République hellénique */
	time_t heure_d_athenes = temps_utc + (2 * 3600) + (application_du_changement_d_heure_pour_l_europe_continentale(temps_utc) * 3600); //Athènes

	/* République de Chypre */
	time_t heure_de_nicosia = temps_utc + (2 * 3600) + (application_du_changement_d_heure_pour_l_europe_continentale(temps_utc) * 3600); //Nicosie

	/* Royaume-Uni de Grande-Bretagne et d'Irlande du Nord */
	time_t heure_de_londres = temps_utc + (application_du_changement_d_heure_pour_la_grande_bretagne(temps_utc) * 3600); //Londres
	time_t heure_aux_bermudes = temps_utc - ((4 * 3600) - (application_du_changement_d_heure_pour_l_amerique_du_nord(temps_utc) * 3600)); //Bermudes
	time_t heure_a_grand_turk = temps_utc - ((5 * 3600) - (application_du_changement_d_heure_pour_l_amerique_du_nord(temps_utc) * 3600)); //Grand Turk
	time_t heure_a_tortola = temps_utc - (4 * 3600); //Tortola
	time_t heure_a_st_helena = temps_utc; //St Hélène
	time_t heure_a_stanley = temps_utc - (3 * 3600); //Stanley
	time_t heure_a_gibraltar = temps_utc + (1 * 3600) + (application_du_changement_d_heure_pour_l_europe_continentale(temps_utc) * 3600); //Gibraltar
	time_t heure_a_anguilla = temps_utc - (4 * 3600); //Anguilla
	time_t heure_a_south_georgia = temps_utc - (2 * 3600); //Géorgie du Sud-et-les îles Sandwich du Sud
	time_t heure_a_cayman = temps_utc - (5 * 3600); //Îles Caïmans
	time_t heure_a_montserrat = temps_utc - (4 * 3600); //Montserrat
	time_t heure_a_pitcairn = temps_utc - (8 * 3600); //Îles Pitcairn
	time_t heure_a_chagos = temps_utc + (6 * 3600); //Territoire britannique de l'océan Indien

	/* République d'Irlande */
	time_t heure_a_dublin = temps_utc + (application_du_changement_d_heure_pour_l_europe_continentale(temps_utc) * 3600); //Dublin

	/* Niue */
	time_t heure_de_niue = temps_utc - (11 * 3600); //Niue

	/* Commonwealth d'Australie */
        time_t heure_a_sydney = temps_utc + ((11 * 3600) - (application_du_changement_d_heure_pour_l_australie(temps_utc) * 3600)); //Sydney
	time_t heure_a_macquarie = temps_utc + (11 * 3600); //Macquarie
	time_t heure_a_adelaide = temps_utc + (30 * 60) + ((10 * 3600) - (application_du_changement_d_heure_pour_l_australie(temps_utc) * 3600)); //Adelaide
	time_t heure_a_broken_hill = temps_utc + (30 * 60) + ((10 * 3600) - (application_du_changement_d_heure_pour_l_australie(temps_utc) * 3600)); //Broken Hill
	time_t heure_a_darwin = temps_utc + (30 * 60) + (9 * 3600); //Darwin
	time_t heure_a_brisbane = temps_utc + (10 * 3600); //Brisbane
	time_t heure_a_curie = temps_utc + ((11 * 3600) - (application_du_changement_d_heure_pour_l_australie(temps_utc) * 3600)); //Curie
	time_t heure_a_hobart = temps_utc + ((11 * 3600) - (application_du_changement_d_heure_pour_l_australie(temps_utc) * 3600)); //Hobart
	time_t heure_a_lindeman = temps_utc + (10 * 3600); //Lindeman
	time_t heure_a_melbourne = temps_utc + ((11 * 3600) - (application_du_changement_d_heure_pour_l_australie(temps_utc) * 3600)); //Melbourne
	time_t heure_a_eucla = temps_utc + (45 * 60) + (8 * 3600); //Eucla
	time_t heure_a_lord_howe = temps_utc + ((11 * 3600) - application_du_changement_d_heure_pour_le_cas_particulier_de_lord_howe(temps_utc)); //Lord Howe
	time_t heure_a_perth = temps_utc + (8 * 3600); //Perth
	time_t heure_aux_cocos = temps_utc + (30 * 60) + (6 * 3600); //Cocos
	time_t heure_a_l_ile_christmas = temps_utc + (7 * 3600); //Christmas
	time_t heure_a_l_ile_norfolk = temps_utc + (11 * 3600); //ile Norfolk

	/* République du Chili */
        time_t heure_santiago_chili = temps_utc - ((4 * 3600) - (application_du_changement_d_heure_pour_le_chili(temps_utc)  * 3600)); //Santiago du Chili
	time_t heure_a_punta_arenas = temps_utc - (3 * 3600); //Punta Arenas
	time_t heure_ile_de_paques = temps_utc - ((6 * 3600)  - (application_du_changement_d_heure_pour_le_chili(temps_utc) * 3600)); //Ile de Pâques

	/* République algérienne démocratique et populaire */
	time_t heure_a_alger = temps_utc + (1 * 3600); //Alger

	/* République du Soudan */
	time_t heure_a_khartoum = temps_utc + (2 * 3600); //Khartoum

	/* République du Soudan du Sud */
	time_t heure_a_djouba = temps_utc + (3 * 3600); //Djouba

	/* République du Mozambique */
	time_t heure_a_maputo = temps_utc + (2 * 3600); //Maputo

	/* Union des Comores */
	time_t heure_aux_comores = temps_utc + (3 * 3600); //Comores

	/* République des Maldives */
	time_t heure_aux_maldives = temps_utc + (5 * 3600); //Maldives

	/* République de Maurice */
	time_t heure_a_maurice = temps_utc + (4 * 3600); //Maurice

	/* Royaume du Lesotho */
	time_t heure_a_maseru = temps_utc + (2 * 3600); //Maseru

	/* Royaume d'Eswatini */
	time_t heure_a_mbabane = temps_utc + (2 * 3600); //Mbabane

	/* République du Botswana */
	time_t heure_a_gaborone = temps_utc + (2 * 3600); //Gaborone

	/* République de Namibie */
	time_t heure_windhoek = temps_utc + (2 * 3600); //Windhoek

	/* République d'Afrique du Sud */
        time_t heure_johannesburg = temps_utc + (2 * 3600); //Johannesburg

	/* État de Libye */
	time_t heure_tripoli = temps_utc + (2 * 3600); //Tripoli

	/* État d'Érythrée */
	time_t heure_a_asmara = temps_utc + (3 * 3600); //Asmara

	/* République fédérale de Somalie */
	time_t heure_a_mogadiscio = temps_utc + (3 * 3600); //Mogadiscio

	/* République démocratique fédérale d’Éthiopie */
	time_t heure_addis_abeba = temps_utc + (3  * 3600); //Addis-Abeba

	/* République de Djibouti */
	time_t heure_djibouti = temps_utc + (3 * 3600); //Djibouti

	/* République du Congo */
	time_t heure_a_brazzaville = temps_utc + (1 * 3600); //Brazzaville

	/* République démocratique du Congo */
	time_t heure_a_kinshasa = temps_utc + (1 * 3600); //Kinshasa
	time_t heure_a_lubumbashi = temps_utc + (2 * 3600); //Lubumbashi

	/* République unie de Tanzanie */
	time_t heure_a_dar_es_salam = temps_utc + (3 * 3600); //Dar_es_Salam

	/* République du Kenya */
	time_t heure_a_nairobi = temps_utc + (3 * 3600); //Nairobi

	/* République de Zambie */
	time_t heure_lusaka = temps_utc + (2 * 3600); //Lusaka

	/* République arabe d'Égypte */
	time_t heure_le_caire = temps_utc + (2 * 3600); //Le Caire

	/* République de Zimbabwe */
	time_t heure_harare = temps_utc + (2 * 3600); //Harare

	/* Nouvelle-Zélande */
	time_t heure_a_auckland = temps_utc + ((13 * 3600) - (application_du_changement_d_heure_pour_la_nouvelle_zelande(temps_utc) * 3600)); //Auckland
	time_t heure_a_waitangi = temps_utc + (45 * 60) + ((13 * 3600) - (application_du_changement_d_heure_pour_la_nouvelle_zelande(temps_utc) * 3600)); //Waitangi
	time_t heure_a_fakaofo = temps_utc + (13 * 3600); //Fakaofo

	/* îles Cook */
	time_t heure_a_rarotonga = temps_utc - (10 * 3600); //Rarotonga

	/* Royaume de Tonga */
	time_t heure_a_togatapu = temps_utc + (13 * 3600); //Togatapu

	/* République des Îles Marshall */
	heure_a_majuro = temps_utc + (12 * 3600); //Majuro
	heure_a_kwajalein = temps_utc + (10 * 3600); //Kwajalein

	/* République de Vanuatu */
	time_t heure_a_efate = temps_utc + (11 * 3600); //Efate

	/* État des Tuvalu */
	time_t heure_a_funafuti = temps_utc + (12 * 3600); //Funafuti

	/* République de Nauru */
	time_t heure_de_nauru = temps_utc + (12 * 3600); //Nauru

	/* République des Kiribati */
	time_t heure_a_tarawa = temps_utc + (12 * 3600); //Tarawa
	time_t heure_a_kiritimati = temps_utc + (14 * 3600); //Kiritimati
	time_t heure_a_enderbury = temps_utc + (13 * 3600); //Enderbury

	/* République du Panama */
	time_t heure_au_panama = temps_utc - (5 * 3600); //Panama

	/* République argentine */
        time_t heure_buenos_aires = temps_utc - (3 * 3600); //Buenos Aires
	time_t heure_a_catamarca = temps_utc - (3 * 3600); //Catamarca
	time_t heure_a_cordoba = temps_utc - (3 * 3600); //Cordoba
	time_t heure_a_jujuy = temps_utc - (3 * 3600); //Jujuy
	time_t heure_a_la_rioja = temps_utc - (3 * 3600); //La Rioja
	time_t heure_a_mendoza = temps_utc - (3 * 3600); //Mendoza
	time_t heure_a_rio_gallegos = temps_utc - (3 * 3600); //Rio Gallegos
	time_t heure_a_salta = temps_utc - (3 * 3600); //Salta
	time_t heure_a_san_juan = temps_utc - (3 * 3600); //San Juan
	time_t heure_a_san_luis = temps_utc - (3 * 3600); //San Luis
	time_t heure_a_tucuman = temps_utc - (3 * 3600); //Tucuman
	time_t heure_a_ushuaia = temps_utc - (3 * 3600); //Ushuaia

	/* République orientale de l'Uruguay */
	time_t heure_a_montevideo = temps_utc - (3 * 3600); //Montevideo

	/* République bolivarienne du Venezuela */
	time_t heure_a_caracas = temps_utc - (4 * 3600); //Caracas

	/* République de l'Équateur */
	time_t heure_a_guayaquil = temps_utc - (5 * 3600); //Guayaquil
	time_t heure_a_galapagos = temps_utc - (6 * 3600); //Galapagos

	/* État plurinational de Bolivie */
	time_t heure_a_la_paz = temps_utc - (4 * 3600); //La Paz

	/* République de Madagascar */
        time_t heure_antananarivo = temps_utc + (3 * 3600); //Antananarivo

	/* République du Pérou */
        time_t heure_lima = temps_utc - (5 * 3600); //Lima

	/* République de Colombie */
	time_t heure_a_bogota = temps_utc - (5 * 3600); //Bogota

	/* État du Qatar */
	time_t heure_au_qatar = temps_utc + (3 * 3600); //Qatar

	/* République du Yémen */
	time_t heure_a_aden = temps_utc + (3 * 3600); //Aden

	/* Royaume d'Arabie saoudite */
	time_t heure_a_riyad = temps_utc + (3 * 3600); //Riyad

	/* Sultanat d'Oman */
	time_t heure_a_mascate = temps_utc + (4 * 3600); //Mascate

	/* Émirats arabes unis */
	time_t heure_a_dubai = temps_utc + (4 * 3600); //Dubai

	/* Royaume de Bahreïn */
	time_t heure_au_bahrein = temps_utc + (3 * 3600); //Bahrein

	/* État du Koweït */
	time_t heure_au_koweit = temps_utc + (3 * 3600); //Koweit

	/* République islamique du Pakistan */
	time_t heure_a_karachi = temps_utc + (5 * 3600); //Karachi

	/* République de l'Inde */
	time_t heure_a_calcutta = temps_utc + (30 * 60) + (5 * 3600); //Calcutta

	/* République démocratique socialiste du Sri Lanka */
	time_t heure_a_colombo = temps_utc + (30 * 60) + (5 * 3600); //Colombo

	/* République populaire du Bangladesh */
	time_t heure_a_dacca = temps_utc + (6 * 3600);

	/* République du Kazakhstan */
	time_t heure_a_almaty = temps_utc + (6 * 3600); //Almaty
	time_t heure_a_qostanay = temps_utc + (6 * 3600); //Qostanay
	time_t heure_a_aktaou = temps_utc + (5 * 3600); //Aktaou
	time_t heure_a_aktioube = temps_utc + (5 * 3600); //Aktioubé
	time_t heure_a_atyrau = temps_utc + (5 * 3600); //Atyrau
	time_t heure_a_oural = temps_utc + (5 * 3600); //Oural
	time_t heure_a_qyzylorda = temps_utc + (5 * 3600); //Qyzylorda

	/* République d'Ouzbékistan */
	time_t heure_a_tachkent = temps_utc + (5 * 3600); //Tachkent
	time_t heure_a_samarkand = temps_utc + (5 * 3600); //Samarkand

	/* République du Tadjikistan */
	time_t heure_a_douchanbe = temps_utc + (5 * 3600); //Douchanbé

	/* République kirghize */
	time_t heure_a_bichkek = temps_utc + (6 * 3600); //Bichkek

	/* République démocratique fédérale du Népal */
	time_t heure_a_katmandou = temps_utc + (45 * 60) + (5 * 3600); //Katmandou

	/* République islamique d'Afghanistan */
	time_t heure_a_kaboul = temps_utc + (30 * 60) + (4 * 3600); //Kaboul

	/* Royaume de Thaïlande */
	time_t heure_a_bangkok = temps_utc + (7 * 3600); //Bangkok

	/* République socialiste du Viêt Nam */
	time_t heure_a_ho_chi_minh_ville = temps_utc + (7 * 3600); //Hô Chi Minh Ville

	/* République populaire démocratique de Corée */
	time_t heure_pyongyang = temps_utc + (9 * 3600); //Pyongyang

	/* République de Corée */
        time_t heure_seoul = temps_utc + (9 * 3600); //Seoul

	/* Empire du Japon */
	time_t heure_tokyo = temps_utc + (9 * 3600); //Tokyo

	/* Royaume du Bhoutan */
	time_t heure_a_thimphou = temps_utc + (6 * 3600); //Thimphou

	/* République populaire de Chine */
        time_t heure_pekin = temps_utc + (8 * 3600); //Pekin
	time_t heure_a_urumqi = temps_utc + (6 * 3600); //Urumqi

	/* Région administrative spéciale de Macao de la République populaire de Chine */
	time_t heure_a_macao = temps_utc + (8 * 3600); //Macao

	/* Région administrative spéciale de Hong Kong de la République populaire de Chine */
	time_t heure_a_hong_kong = temps_utc + (8 * 3600); //Hong Kong

	/* République démocratique populaire lao */
	time_t heure_a_vientiane = temps_utc + (7 * 3600); //Vientiane

	/* Royaume du Cambodge */
	time_t heure_a_phnom_penh = temps_utc + (7 * 3600); //Phnom Penh

	/* République de l'Union du Myanmar */
	time_t heure_a_yagon = temps_utc + (30 * 60) + (6 * 3600); //Yangon

	/* République démocratique du Timor oriental */
	time_t heure_a_dili = temps_utc + (9 * 3600); //Dili

	/* Negara Brunei Darussalam */
	time_t heure_brunei = temps_utc + (8 * 3600); //Brunei

	/* Mongolie */
	time_t heure_a_choibalsan = temps_utc + (8 * 3600); //Choibalsan
	time_t heure_a_ulaanbaatar = temps_utc + (8 * 3600); //Ulaanbaatar
	time_t heure_a_hovd = temps_utc + (7 * 3600); //Hovd

	/* République de Chine (Taiwan) */
	time_t heure_a_tapei = temps_utc + (8 * 3600); //Tapei

	/* République des Philippines */
	time_t heure_a_manille = temps_utc + (8 * 3600); //Manille

	/* République de Singapour */
	time_t heure_a_singapour = temps_utc + (8 * 3600); //Singapour

	/* Îles Salomon */
	time_t heure_a_guadalcanal = temps_utc + (11 * 3600); //Guadalcanal

	/* Malaisie */
	time_t heure_a_kuala_lumpur = temps_utc + (8 * 3600); //Kuala Lumpur
	time_t heure_a_kuching = temps_utc + (8 * 3600); //Kuching

	/* République des Seychelles */
	time_t heure_a_mahe = temps_utc + (4 * 3600); //Mahe

	/* État indépendant de Papouasie-Nouvelle-Guinée */
	time_t heure_a_bougainville = temps_utc + (11 * 3600); //Bougainville
	time_t heure_a_port_moresby = temps_utc + (10 * 3600); //Port Moresby

	/* États fédérés de Micronésie */
	time_t heure_a_pohnpei = temps_utc + (11 * 3600); //Pohnpei
	time_t heure_a_chuuk = temps_utc + (10 * 3600); //Chuuk
	time_t heure_a_kosrae = temps_utc + (11 * 3600); //kosrae

	/* République des Palaos */
	time_t heure_de_palau = temps_utc + (9 * 3600); //Palau

	/* îles Mariannes du Nord */
	time_t heure_a_saipan = temps_utc + (10 * 3600); //Saipan

	/* Porto Rico */
	time_t heure_a_porto_rico = temps_utc - (4 * 3600); //Porto Rico

	/* République de Turquie */
	time_t heure_a_istanbul = temps_utc + (3 * 3600); //Istanbul

	/* Fédération de Russie */
	time_t heure_moscou = temps_utc + (3 * 3600); //Moscou
        time_t heure_vladivostok = temps_utc + (10 * 3600); //Vladivostok
	time_t heure_kaliningrad = temps_utc + (2 * 3600); //Kaliningrad
	time_t heure_samara = temps_utc + (4 * 3600); //Samara
	time_t heure_volgograd = temps_utc + (4 * 3600); //Volgograd
	time_t heure_saratov = temps_utc + (4 * 3600); //Saratov
	time_t heure_oulianovsk = temps_utc + (4 * 3600); //Oulianovsk
	time_t heure_astrakhan = temps_utc + (4 * 3600); //Astrakhan
	time_t heure_anadyr = temps_utc + (12 * 3600); //Anadyr
	time_t heure_sakhalin = temps_utc + (11 * 3600); //Sakhalin
	time_t heure_omsk = temps_utc + (6 * 3600); //Omsk
	time_t heure_tchita = temps_utc + (9 * 3600); //Tchita
	time_t heure_tomsk = temps_utc + (7 * 3600); //Tomsk
	time_t heure_barnaoul = temps_utc + (7 * 3600); //Barnaoul
	time_t heure_magadan = temps_utc + (11 * 3600); //Magadan
	time_t heure_iekaterinbourg = temps_utc + (5 * 3600); //Iekaterinbourg
	time_t heure_yakoutsk = temps_utc + (9 * 3600); //Yakoutsk
	time_t heure_irkoutsk = temps_utc + (8 * 3600); //Irkoutsk
	time_t heure_khandyga = temps_utc + (9 * 3600); //Khandyga
	time_t heure_novokouznetsk = temps_utc + (7 * 3600); //Novokouznetsk
	time_t heure_nobossibirsk = temps_utc + (7 * 3600); //Nobossibirsk
	time_t heure_krasnoyarsk = temps_utc + (7 * 3600); //Krasnoyarsk
	time_t heure_oust_nera = temps_utc + (10 * 3600); //Oust-Nera
	time_t heure_srednekolymsk = temps_utc + (11 * 3600); //Srednekolymsk

	/* République d'Arménie */
	time_t heure_erevan = temps_utc + (4 * 3600); //Erevan

	/* Géorgie */
	time_t heure_a_tbilissi = temps_utc + (4 * 3600); //Tbilissi

	/* République d'Azerbaïdjan */
	time_t heure_a_bakou = temps_utc + (4 * 3600); //Bakou

	/*Affichage des différents horiares calculés à coté des villes correspondantes*/

        printf("\n");
	printf("République française:\n");
        calcul_et_affichage_horaire(heure_de_paris, "Paris");
	calcul_et_affichage_horaire(heure_de_cayenne, "Cayenne");
	calcul_et_affichage_horaire(heure_de_la_reunion, "La Reunion");
	calcul_et_affichage_horaire(heure_de_la_guadeloupe, "La guadeloupe");
	calcul_et_affichage_horaire(heure_de_noumea, "Nouméa");
	calcul_et_affichage_horaire(heure_de_mayotte, "Mayotte");
	calcul_et_affichage_horaire(heure_des_iles_kerguelen, "îles Kerguelen");
	calcul_et_affichage_horaire(heure_de_tahiti, "Tahiti");
	calcul_et_affichage_horaire(heure_de_miquelon, "Miquelon");
	calcul_et_affichage_horaire(heure_de_st_barthelemy, "St Barthélemy");
	calcul_et_affichage_horaire(heure_de_la_martinique, "Martinique");
	calcul_et_affichage_horaire(heure_de_wallis, "Wallis");
	calcul_et_affichage_horaire(heure_a_lower_princes, "Saint-Martin");

	printf("\n");
	printf("Principauté de Monaco:\n");
	calcul_et_affichage_horaire(heure_a_monaco, "Monaco");

	printf("\n");
	printf("Royaume d'Espagne:\n");
	calcul_et_affichage_horaire(heure_a_madrid, "Madrid");
	calcul_et_affichage_horaire(heure_a_ceuta, "Ceuta");
	calcul_et_affichage_horaire(heure_aux_iles_canaries, "îles Canaries");

	printf("\n");
	printf("République portugaise:\n");
	calcul_et_affichage_horaire(heure_a_lisbonne, "Lisbonne");
	calcul_et_affichage_horaire(heure_aux_acores, "Açores");
	calcul_et_affichage_horaire(heure_a_madere, "Madère");

	printf("\n");
	printf("Grand-Duché de Luxembourg:\n");
	calcul_et_affichage_horaire(heure_au_luxembourg, "Luxembourg");

	printf("\n");
	printf("Royaume de Belgique:\n");
	calcul_et_affichage_horaire(heure_a_bruxelles, "Bruxelles");

	printf("\n");
	printf("Royaume des Pays-Bas:\n");
	calcul_et_affichage_horaire(heure_d_amsterdam, "Amsterdam");
	calcul_et_affichage_horaire(heure_d_aruba, "Aruba");
	calcul_et_affichage_horaire(heure_de_kralendijk, "Kralendijk");
	calcul_et_affichage_horaire(heure_de_curacao, "Curacao");
	calcul_et_affichage_horaire(heure_a_lower_princes, "Sint Maarten");

	printf("\n");
	printf("République fédérale d'Allemagne:\n");
	calcul_et_affichage_horaire(heure_de_berlin, "Berlin");
	calcul_et_affichage_horaire(heure_de_busingen, "Busingen");

	printf("\n");
	printf("Royaume du Danemark:\n");
	calcul_et_affichage_horaire(heure_a_copenhague, "Copenhague");
	calcul_et_affichage_horaire(heure_aux_iles_feroes, "Iles Féroé");
	calcul_et_affichage_horaire(heure_a_scoresbysund, "Scoresbysund");
	calcul_et_affichage_horaire(heure_a_godthab, "Godthab");
	calcul_et_affichage_horaire(heure_a_thule, "Thule");
	calcul_et_affichage_horaire(heure_a_danmarkshavn, "Danmarkshavn");

	printf("\n");
	printf("Royaume de Norvège:\n");
	calcul_et_affichage_horaire(heure_a_oslo, "Oslo");
	calcul_et_affichage_horaire(heure_a_longyearbyen, "Longyearbyen");

	printf("\n");
	printf("Royaume de Suède:\n");
	calcul_et_affichage_horaire(heure_a_stockholm, "Stockholm");

	printf("\n");
	printf("République de Finlande:\n");
	calcul_et_affichage_horaire(heure_a_helsinki, "Helsinki");

	printf("\n");
	printf("République d'Islande:\n");
	calcul_et_affichage_horaire(heure_a_reykjavik, "Reykjavik");

	printf("\n");
	printf("République de Pologne:\n");
	calcul_et_affichage_horaire(heure_a_varsovie, "Varsovie");

	printf("\n");
	printf("République de Lituanie:\n");
	calcul_et_affichage_horaire(heure_a_vilnius, "Vilnius");

	printf("\n");
	printf("République de Lettonie:\n");
	calcul_et_affichage_horaire(heure_a_riga, "Riga");

	printf("\n");
	printf("République d’Estonie:\n");
	calcul_et_affichage_horaire(heure_a_tallinn, "Tallinn");

	printf("\n");
	printf("République italienne:\n");
	calcul_et_affichage_horaire(heure_de_rome, "Rome");

	printf("\n");
	printf("État de la Cité du Vatican:\n");
	calcul_et_affichage_horaire(heure_du_vatican, "Vatican");

	printf("\n");
	printf("République de Saint-Marin:\n");
	calcul_et_affichage_horaire(heure_a_saint_marin, "Saint-Marin");

	printf("\n");
	printf("République d'Autriche:\n");
	calcul_et_affichage_horaire(heure_de_vienne, "Vienne");

	printf("\n");
	printf("Hongrie:\n");
	calcul_et_affichage_horaire(heure_a_budapest, "Budapest");

	printf("\n");
	printf("République tchèque:\n");
	calcul_et_affichage_horaire(heure_a_prague, "Prague");

	printf("\n");
	printf("République slovaque:\n");
	calcul_et_affichage_horaire(heure_a_bratislava, "Bratislava");

	printf("\n");
	printf("République de Biélorussie:\n");
	calcul_et_affichage_horaire(heure_a_minsk, "Minsk");

	printf("\n");
	printf("Ukraine:\n");
	calcul_et_affichage_horaire(heure_a_kiev, "Kiev");
	calcul_et_affichage_horaire(heure_a_uzhgorod, "Uzhgorod");
	calcul_et_affichage_horaire(heure_a_zaporozhye, "Zaporozhye");

	printf("\n");
	printf("République de Moldavie:\n");
	calcul_et_affichage_horaire(heure_a_chisinau, "Chisinau");

	printf("\n");
	printf("Confédération suisse:\n");
	calcul_et_affichage_horaire(heure_zurich, "Zurich");

	printf("\n");
	printf("Principauté d'Andorre:\n");
	calcul_et_affichage_horaire(heure_andorre, "Andorre");

	printf("\n");
	printf("République de Malte:\n");
	calcul_et_affichage_horaire(heure_malte, "Malte");

	printf("\n");
	printf("Principauté de Liechtenstein:\n");
	calcul_et_affichage_horaire(heure_vaduz, "Vaduz");

	printf("\n");
	printf("Roumanie:\n");
	calcul_et_affichage_horaire(heure_a_bucarest, "Bucarest");

	printf("\n");
	printf("République de Bulgarie:\n");
	calcul_et_affichage_horaire(heure_a_sofia, "Sofia");

	printf("\n");
	printf("République de Macédoine du Nord:\n");
	calcul_et_affichage_horaire(heure_a_skopje, "Skopje");

	printf("\n");
	printf("République de Slovénie:\n");
	calcul_et_affichage_horaire(heure_a_ljubljana, "Ljubljana");

	printf("\n");
	printf("République de Croatie:\n");
	calcul_et_affichage_horaire(heure_a_zagreb, "Zagreb");

	printf("\n");
	printf("Bosnie-Herzégovine:\n");
	calcul_et_affichage_horaire(heure_a_sarajevo, "Sarajevo");

	printf("\n");
	printf("Monténégro:\n");
	calcul_et_affichage_horaire(heure_a_podgorica, "Podgorica");

	printf("\n");
	printf("République de Serbie:\n");
	calcul_et_affichage_horaire(heure_a_belgrade, "Belgrade");

	printf("\n");
	printf("République d'Albanie:\n");
	calcul_et_affichage_horaire(heure_a_tirane, "Tirane");

	printf("\n");
	printf("République hellénique:\n");
	calcul_et_affichage_horaire(heure_d_athenes, "Athènes");

	printf("\n");
	printf("République de Chypre:\n");
	calcul_et_affichage_horaire(heure_de_nicosia, "Nicosie");

	printf("\n");
	printf("Commonwealth des Bahamas:\n");
	calcul_et_affichage_horaire(heure_a_nassau, "Nassau");

	printf("\n");
	printf("République du Suriname:\n");
	calcul_et_affichage_horaire(heure_a_paramaribo, "Paramaribo");

	printf("\n");
	printf("République coopérative du Guyana:\n");
	calcul_et_affichage_horaire(heure_a_guyana, "Guyana");

	printf("\n");
	printf("République de Trinité-et-Tobago:\n");
	calcul_et_affichage_horaire(heure_a_port_d_espagne, "Port d'Espagne");

	printf("\n");
	printf("République de Cuba:\n");
	calcul_et_affichage_horaire(heure_a_la_havane, "La Havane");

	printf("\n");
	printf("Jamaïque:\n");
	calcul_et_affichage_horaire(heure_en_jamaique, "Jamaique");

	printf("\n");
	printf("États-Unis d'Amérique:\n");
        calcul_et_affichage_horaire(heure_los_angeles, "Los Angeles");
        calcul_et_affichage_horaire(heure_de_nyc, "New York City");
        calcul_et_affichage_horaire(heure_de_phoenix, "Phoenix");
	calcul_et_affichage_horaire(heure_a_honolulu, "Honolulu");
	calcul_et_affichage_horaire(heure_a_juneau, "Juneau");
	calcul_et_affichage_horaire(heure_a_yakutat, "Yakutat");
	calcul_et_affichage_horaire(heure_a_menominee, "Menominee");
	calcul_et_affichage_horaire(heure_a_chicago, "Chicago");
	calcul_et_affichage_horaire(heure_a_boise, "Boise");
	calcul_et_affichage_horaire(heure_a_denver, "Denver");
	calcul_et_affichage_horaire(heure_a_anchorage, "Anchorage");
	calcul_et_affichage_horaire(heure_a_detroit, "Detroit");
	calcul_et_affichage_horaire(heure_a_metlakatla, "Metlakatla");
	calcul_et_affichage_horaire(heure_a_sitka, "Sikta");
	calcul_et_affichage_horaire(heure_a_nome, "Nome");
	calcul_et_affichage_horaire(heure_a_adak, "Adak");
	calcul_et_affichage_horaire(heure_a_kentucky_louiseville, "Louiseville");
	calcul_et_affichage_horaire(heure_a_kentucky_monticello, "Monticello");
	calcul_et_affichage_horaire(heure_a_indiana_winamac, "winamac");
	calcul_et_affichage_horaire(heure_a_indiana_vincennes, "Vincennes");
	calcul_et_affichage_horaire(heure_a_indiana_vevay, "Vevay");
	calcul_et_affichage_horaire(heure_a_indiana_petersburg, "Petersburg");
	calcul_et_affichage_horaire(heure_a_indiana_marengo, "Marengo");
	calcul_et_affichage_horaire(heure_a_indiana_indianapolis, "Indianapolis");
	calcul_et_affichage_horaire(heure_a_north_dakota_new_salem, "New Salem");
	calcul_et_affichage_horaire(heure_a_north_dakota_center, "Center");
	calcul_et_affichage_horaire(heure_a_north_dakota_beulah, "Beulah");
	calcul_et_affichage_horaire(heure_a_indiana_tell_city, "Tell City");
	calcul_et_affichage_horaire(heure_a_indiana_knox, "Knox");
	calcul_et_affichage_horaire(heure_a_pago_pago, "Samoa américaines");

	printf("\n");
	printf("Dominion du Canada:\n");
	calcul_et_affichage_horaire(heure_de_toronto, "Toronto");
	calcul_et_affichage_horaire(heure_d_atikokan, "Atikokan");
	calcul_et_affichage_horaire(heure_de_pangnirtung, "Pangnirtung");
	calcul_et_affichage_horaire(heure_de_thunder_bay, "Thunder Bay");
	calcul_et_affichage_horaire(heure_de_nipigon, "Nipigon");
	calcul_et_affichage_horaire(heure_d_iqaluit, "Iqaluit");
	calcul_et_affichage_horaire(heure_de_winnipeg, "Winnipeg");
	calcul_et_affichage_horaire(heure_de_swift_current, "Swift Current");
	calcul_et_affichage_horaire(heure_de_resolute, "Resolute");
	calcul_et_affichage_horaire(heure_de_regina, "Regina");
	calcul_et_affichage_horaire(heure_de_rankin_inlet, "Rankin Inlet");
	calcul_et_affichage_horaire(heure_de_rainy_river, "Rainy River");
	calcul_et_affichage_horaire(heure_de_whitehorse, "Whitehorse");
	calcul_et_affichage_horaire(heure_de_vancouver, "Vancouver");
	calcul_et_affichage_horaire(heure_de_dawson, "Dawson");
	calcul_et_affichage_horaire(heure_de_st_johns, "St Johns");
	calcul_et_affichage_horaire(heure_de_blanc_sablon, "Blanc Sablon");
	calcul_et_affichage_horaire(heure_de_moncton, "Moncton");
	calcul_et_affichage_horaire(heure_d_halifax, "Halifax");
	calcul_et_affichage_horaire(heure_de_goose_bay, "Goose Bay");
	calcul_et_affichage_horaire(heure_de_glace_bay, "Glace Bay");
	calcul_et_affichage_horaire(heure_d_inuvik, "Inuvik");
	calcul_et_affichage_horaire(heure_de_fort_nelson, "Fort Nelson");
	calcul_et_affichage_horaire(heure_d_edmonton, "Edmonton");
	calcul_et_affichage_horaire(heure_de_dawson_creek, "Dawson Creek");
	calcul_et_affichage_horaire(heure_de_creston, "Creston");
	calcul_et_affichage_horaire(heure_de_cambridge_bay, "Cambridge Bay");
	calcul_et_affichage_horaire(heure_d_yellowknife, "Yellowknife");

	printf("\n");
	printf("République du Guatemala:\n");
	calcul_et_affichage_horaire(heure_au_guatemala, "Guatemala");

	printf("\n");
	printf("République du Salvador:\n");
	calcul_et_affichage_horaire(heure_d_el_salvador, "El Salvador");

	printf("\n");
	printf("République du Honduras:\n");
	calcul_et_affichage_horaire(heure_au_honduras, "Tegucigalpa");

	printf("\n");
	printf("Belize:\n");
	calcul_et_affichage_horaire(heure_au_belize, "Belize");

	printf("\n");
	printf("République du Nicaragua:\n");
	calcul_et_affichage_horaire(heure_managua, "Managua");

	printf("\n");
	printf("République du Costa Rica:\n");
	calcul_et_affichage_horaire(heure_au_costa_rica, "Costa Rica");

	printf("\n");
	printf("Royaume-Uni de Grande-Bretagne et d'Irlande du Nord:\n");
	calcul_et_affichage_horaire(heure_de_londres, "Londres");
	calcul_et_affichage_horaire(heure_aux_bermudes, "Bermudes");
	calcul_et_affichage_horaire(heure_a_grand_turk, "Grand Turk");
	calcul_et_affichage_horaire(heure_a_tortola, "Tortola");
	calcul_et_affichage_horaire(heure_a_st_helena, "St Hélène");
	calcul_et_affichage_horaire(heure_a_st_helena, "Île de l'Ascension");
	calcul_et_affichage_horaire(heure_a_st_helena, "Tristan da Cunha");
	calcul_et_affichage_horaire(heure_a_stanley, "Îles Malouines");
	calcul_et_affichage_horaire(heure_a_gibraltar, "Gibraltar");
	calcul_et_affichage_horaire(heure_a_anguilla, "Anguilla");
	calcul_et_affichage_horaire(heure_a_south_georgia, "Géorgie du Sud-et-les îles Sandwich du Sud");
	calcul_et_affichage_horaire(heure_a_cayman, "Îles Caïmans");
	calcul_et_affichage_horaire(heure_a_montserrat, "Montserrat");
	calcul_et_affichage_horaire(heure_d_athenes, "Akrotiri et Dhekelia");
	calcul_et_affichage_horaire(heure_a_chagos, "Territoire britannique de l'océan Indien");

	printf("\n");
	printf("République d'Irlande:\n");
	calcul_et_affichage_horaire(heure_a_dublin, "Dublin");

	printf("\n");
	printf("Commonwealth d'Australie:\n");
        calcul_et_affichage_horaire(heure_a_sydney, "Sydney");
	calcul_et_affichage_horaire(heure_a_macquarie, "Macquarie");
	calcul_et_affichage_horaire(heure_a_adelaide, "Adelaide");
	calcul_et_affichage_horaire(heure_a_broken_hill, "Broken Hill");
	calcul_et_affichage_horaire(heure_a_darwin, "Darwin");
	calcul_et_affichage_horaire(heure_a_brisbane, "Brisbane");
	calcul_et_affichage_horaire(heure_a_curie, "Curie");
	calcul_et_affichage_horaire(heure_a_hobart, "Hobart");
	calcul_et_affichage_horaire(heure_a_lindeman, "Lindeman");
	calcul_et_affichage_horaire(heure_a_melbourne, "Melbourne");
	calcul_et_affichage_horaire(heure_a_eucla, "Eucla");
	calcul_et_affichage_horaire(heure_a_lord_howe, "Lord Howe");
	calcul_et_affichage_horaire(heure_a_perth, "Perth");
	calcul_et_affichage_horaire(heure_aux_cocos, "Cocos");
	calcul_et_affichage_horaire(heure_a_l_ile_christmas, "îles Christmas");
	calcul_et_affichage_horaire(heure_a_l_ile_norfolk, "îles Norfolk");

	printf("\n");
	printf("Nouvelle-Zélande:\n");
	calcul_et_affichage_horaire(heure_a_auckland, "Auckland");
	calcul_et_affichage_horaire(heure_a_waitangi, "Waitangi");
	calcul_et_affichage_horaire(heure_a_fakaofo, "Fakaofo");

	printf("\n");
	printf("îles Cook:\n");
	calcul_et_affichage_horaire(heure_a_rarotonga, "Rarotonga");

	printf("\n");
	printf("Royaume de Tonga:\n");
	calcul_et_affichage_horaire(heure_a_togatapu, "Togatapu");

	printf("\n");
	printf("Niue:\n");
	calcul_et_affichage_horaire(heure_de_niue, "Niue");

	printf("\n");
	printf("République de Vanuatu:\n");
	calcul_et_affichage_horaire(heure_a_efate, "Efate");

	printf("\n");
	printf("République islamique du Pakistan:\n");
	calcul_et_affichage_horaire(heure_a_karachi, "Karachi");

	printf("\n");
	printf("République démocratique socialiste du Sri Lanka:\n");
	calcul_et_affichage_horaire(heure_a_colombo, "Colombo");

	printf("\n");
	printf("République des Kiribati:\n");
	calcul_et_affichage_horaire(heure_a_tarawa, "Tarawa");
	calcul_et_affichage_horaire(heure_a_kiritimati, "Kiritimati");
	calcul_et_affichage_horaire(heure_a_enderbury, "Enderbury");

	printf("\n");
	printf("État des Tuvalu:\n");
	calcul_et_affichage_horaire(heure_a_funafuti, "Funafuti");

	printf("\n");
	printf("République de Nauru:\n");
	calcul_et_affichage_horaire(heure_de_nauru, "Nauru");

	printf("\n");
	printf("République du Chili:\n");
        calcul_et_affichage_horaire(heure_santiago_chili, "Santiago du Chili");
	calcul_et_affichage_horaire(heure_a_punta_arenas, "Punta Arenas");
	calcul_et_affichage_horaire(heure_ile_de_paques, "Ile de Pâques");

	printf("\n");
	printf("République algérienne démocratique et populaire:\n");
	calcul_et_affichage_horaire(heure_a_alger, "Alger");

	printf("\n");
	printf("République du Soudan:\n");
	calcul_et_affichage_horaire(heure_a_khartoum, "Khartoum");

	printf("\n");
	printf("République du Soudan du Sud:\n");
	calcul_et_affichage_horaire(heure_a_djouba, "Djouba");

	printf("\n");
	printf("République d'Afrique du Sud:\n");
        calcul_et_affichage_horaire(heure_johannesburg, "Johannesburg");

	printf("\n");
	printf("République du Panama:\n");
	calcul_et_affichage_horaire(heure_au_panama, "Panama");

	printf("\n");
	printf("République argentine:\n");
        calcul_et_affichage_horaire(heure_buenos_aires, "Buenos Aires");
	calcul_et_affichage_horaire(heure_a_catamarca, "Catamarca");
	calcul_et_affichage_horaire(heure_a_cordoba, "Cordoba");
	calcul_et_affichage_horaire(heure_a_jujuy, "Jujuy");
	calcul_et_affichage_horaire(heure_a_la_rioja, "La Rioja");
	calcul_et_affichage_horaire(heure_a_mendoza, "Mendoza");
	calcul_et_affichage_horaire(heure_a_rio_gallegos, "Rio Gallegos");
	calcul_et_affichage_horaire(heure_a_salta, "Salta");
	calcul_et_affichage_horaire(heure_a_san_juan, "San Juan");
	calcul_et_affichage_horaire(heure_a_san_luis, "San Luis");
	calcul_et_affichage_horaire(heure_a_tucuman, "Tucuman");
	calcul_et_affichage_horaire(heure_a_ushuaia, "Ushuaia");

	printf("\n");
	printf("République orientale de l'Uruguay:\n");
	calcul_et_affichage_horaire(heure_a_montevideo, "Montivideo");

	printf("\n");
	printf("République bolivarienne du Venezuela:\n");
	calcul_et_affichage_horaire(heure_a_caracas, "Caracas");

	printf("\n");
	printf("République de l'Équateur:\n");
	calcul_et_affichage_horaire(heure_a_guayaquil, "Guayaquil");
	calcul_et_affichage_horaire(heure_a_galapagos, "Galapagos");

	printf("\n");
	printf("République de Colombie:\n");
	calcul_et_affichage_horaire(heure_a_bogota, "Bogota");

	printf("\n");
	printf("État plurinational de Bolivie:\n");
	calcul_et_affichage_horaire(heure_a_la_paz, "La Paz");

	printf("\n");
	printf("République de Madagascar:\n");
        calcul_et_affichage_horaire(heure_antananarivo, "Antananarivo");

	printf("\n");
	printf("République du Congo:\n");
	calcul_et_affichage_horaire(heure_a_brazzaville, "Brazzaville");

	printf("\n");
	printf("République démocratique du Congo:\n");
	calcul_et_affichage_horaire(heure_a_kinshasa, "Kinshasa");
	calcul_et_affichage_horaire(heure_a_lubumbashi, "Lubumbashi");

	printf("\n");
	printf("République de Namibie:\n");
        calcul_et_affichage_horaire(heure_windhoek, "Windhoek");

	printf("\n");
	printf("République du Mozambique:\n");
	calcul_et_affichage_horaire(heure_a_maputo, "Maputo");

	printf("\n");
	printf("Union des Comores:\n");
	calcul_et_affichage_horaire(heure_aux_comores, "Comores");

	printf("\n");
	printf("République des Maldives:\n");
	calcul_et_affichage_horaire(heure_aux_maldives, "Maldives");

	printf("\n");
	printf("République de Maurice:\n");
	calcul_et_affichage_horaire(heure_a_maurice, "Maurice");

	printf("\n");
	printf("Royaume du Lesotho:\n");
	calcul_et_affichage_horaire(heure_a_maseru, "Maseru");

	printf("\n");
	printf("Royaume d'Eswatini:\n");
	calcul_et_affichage_horaire(heure_a_mbabane, "Mbabane");

	printf("\n");
	printf("République du Botswana:\n");
	calcul_et_affichage_horaire(heure_a_gaborone, "Gaborone");

	printf("\n");
	printf("État de Libye:\n");
	calcul_et_affichage_horaire(heure_tripoli, "Tripoli");

	printf("\n");
	printf("République arabe d'Égypte:\n");
	calcul_et_affichage_horaire(heure_le_caire, "Le Caire");

	printf("\n");
	printf("Royaume d'Arabie saoudite:\n");
	calcul_et_affichage_horaire(heure_a_riyad, "Riyad");

	printf("\n");
	printf("État du Qatar:\n");
	calcul_et_affichage_horaire(heure_au_qatar, "Qatar");

	printf("\n");
	printf("Émirats arabes unis:\n");
	calcul_et_affichage_horaire(heure_a_dubai, "Dubai");

	printf("\n");
	printf("République du Yémen:\n");
	calcul_et_affichage_horaire(heure_a_aden, "Aden");

	printf("\n");
	printf("Sultanat d'Oman:\n");
	calcul_et_affichage_horaire(heure_a_mascate, "Mascate");

	printf("\n");
	printf("Royaume de Bahreïn:\n");
	calcul_et_affichage_horaire(heure_au_bahrein, "Bahrein");

	printf("\n");
	printf("État du Koweït:\n");
	calcul_et_affichage_horaire(heure_au_koweit, "Koweit");

	printf("\n");
	printf("République démocratique fédérale d’Éthiopie:\n");
	calcul_et_affichage_horaire(heure_addis_abeba, "Addis-Abeba");

	printf("\n");
	printf("République fédérale de Somalie:\n");
	calcul_et_affichage_horaire(heure_a_mogadiscio, "Mogadiscio");

	printf("\n");
	printf("État d'Érythrée:\n");
	calcul_et_affichage_horaire(heure_a_asmara, "Asmara");

	printf("\n");
	printf("République de Djibouti:\n");
	calcul_et_affichage_horaire(heure_djibouti, "Djibouti");

	printf("\n");
	printf("République du Kenya:\n");
	calcul_et_affichage_horaire(heure_a_nairobi, "Nairobi");

	printf("\n");
	printf("République unie de Tanzanie:\n");
	calcul_et_affichage_horaire(heure_a_dar_es_salam, "Dar es Salam");

	printf("\n");
	printf("République de Zambie:\n");
	calcul_et_affichage_horaire(heure_lusaka, "Lusaka");

	printf("\n");
	printf("République de Zimbabwe:\n");
	calcul_et_affichage_horaire(heure_harare, "Harare");

	printf("\n");
	printf("République du Pérou:\n");
        calcul_et_affichage_horaire(heure_lima, "Lima");

	printf("\n");
	printf("République de l'Inde:\n");
	calcul_et_affichage_horaire(heure_a_calcutta, "Calcutta");

	printf("\n");
	printf("République populaire du Bangladesh:\n");
	calcul_et_affichage_horaire(heure_a_dacca, "Dacca");

	printf("\n");
	printf("République du Kazakhstan:\n");
	calcul_et_affichage_horaire(heure_a_almaty, "Almaty");
	calcul_et_affichage_horaire(heure_a_qostanay, "Qostanay");
	calcul_et_affichage_horaire(heure_a_aktaou, "Aktaou");
	calcul_et_affichage_horaire(heure_a_aktioube, "Aktioube");
	calcul_et_affichage_horaire(heure_a_atyrau, "Atyrau");
	calcul_et_affichage_horaire(heure_a_oural, "Oural");
	calcul_et_affichage_horaire(heure_a_qyzylorda, "Qyzylorda");

	printf("\n");
	printf("République d'Ouzbékistan:\n");
	calcul_et_affichage_horaire(heure_a_tachkent, "Tachkent");
	calcul_et_affichage_horaire(heure_a_samarkand, "Samarkand");

	printf("\n");
	printf("République du Tadjikistan:\n");
	calcul_et_affichage_horaire(heure_a_douchanbe, "Dushanbe");

	printf("\n");
	printf("République kirghize:\n");
	calcul_et_affichage_horaire(heure_a_bichkek, "Bichkek");

	printf("\n");
	printf("République démocratique fédérale du Népal:\n");
	calcul_et_affichage_horaire(heure_a_katmandou, "Katmandou");

	printf("\n");
        printf("République islamique d'Afghanistan:\n");
        calcul_et_affichage_horaire(heure_a_kaboul, "Kaboul");

	printf("\n");
	printf("Royaume de Thaïlande:\n");
	calcul_et_affichage_horaire(heure_a_bangkok, "Bangkok");

	printf("\n");
	printf("République socialiste du Viêt Nam:\n");
	calcul_et_affichage_horaire(heure_a_ho_chi_minh_ville, "Hô Chi Minh Ville");

	printf("\n");
	printf("République populaire démocratique de Corée:\n");
	calcul_et_affichage_horaire(heure_pyongyang, "Pyongyang");

	printf("\n");
	printf("République de Corée:\n");
        calcul_et_affichage_horaire(heure_seoul, "Seoul");

	printf("\n");
	printf("Empire du Japon:\n");
        calcul_et_affichage_horaire(heure_tokyo, "Tokyo");

	printf("\n");
	printf("Negara Brunei Darussalam:\n");
	calcul_et_affichage_horaire(heure_brunei, "Brunei");

	printf("\n");
	printf("République populaire de Chine:\n");
        calcul_et_affichage_horaire(heure_pekin, "Pekin");
	calcul_et_affichage_horaire(heure_a_urumqi, "Urumqi");

	printf("\n");
	printf("République de Chine (Taiwan):\n");
	calcul_et_affichage_horaire(heure_a_tapei, "Tapei");

	printf("\n");
	printf("Région administrative spéciale de Macao de la République populaire de Chine:\n");
	calcul_et_affichage_horaire(heure_a_macao, "Macao");

	printf("\n");
	printf("Région administrative spéciale de Hong Kong de la République populaire de Chine:\n");
	calcul_et_affichage_horaire(heure_a_hong_kong, "Hong Kong");

	printf("\n");
	printf("République des Philippines:\n");
	calcul_et_affichage_horaire(heure_a_manille, "Manille");

	printf("\n");
	printf("République de Singapour:\n");
	calcul_et_affichage_horaire(heure_a_singapour, "Singapour");

	printf("\n");
	printf("République démocratique populaire lao:\n");
	calcul_et_affichage_horaire(heure_a_vientiane, "Vientiane");

	printf("\n");
	printf("Royaume du Cambodge:\n");
	calcul_et_affichage_horaire(heure_a_phnom_penh, "Phnom Penh");

	printf("\n");
	printf("République de l'Union du Myanmar:\n");
	calcul_et_affichage_horaire(heure_a_yagon, "Yagon");

	printf("\n");
	printf("République démocratique du Timor oriental:\n");
	calcul_et_affichage_horaire(heure_a_dili, "Dili");

	printf("\n");
	printf("Îles Salomon:\n");
	calcul_et_affichage_horaire(heure_a_guadalcanal, "Guadalcanal");

	printf("\n");
	printf("Malaisie:\n");
	calcul_et_affichage_horaire(heure_a_kuala_lumpur, "Kuala Lumpur");
	calcul_et_affichage_horaire(heure_a_kuching, "Kuching");

	printf("\n");
	printf("République des Seychelles:\n");
	calcul_et_affichage_horaire(heure_a_mahe, "Mahe");

	printf("\n");
	printf("État indépendant de Papouasie-Nouvelle-Guinée:\n");
	calcul_et_affichage_horaire(heure_a_bougainville, "Bougainville");
	calcul_et_affichage_horaire(heure_a_port_moresby, "Port Moresby");

	printf("\n");
	printf("États fédérés de Micronésie:\n");
	calcul_et_affichage_horaire(heure_a_pohnpei, "Pohnpei");
	calcul_et_affichage_horaire(heure_a_chuuk, "Chuuk");
	calcul_et_affichage_horaire(heure_a_kosrae, "Kosrae");

	printf("\n");
	printf("République des Palaos:\n");
	calcul_et_affichage_horaire(heure_de_palau, "Palau");

	printf("\n");
	printf("îles Mariannes du Nord:\n");
	calcul_et_affichage_horaire(heure_a_saipan, "Saipan");

	printf("\n");
	printf("Porto Rico:\n");
	calcul_et_affichage_horaire(heure_a_porto_rico, "Porto Rico");

	printf("\n");
	printf("Royaume du Bhoutan:\n");
	calcul_et_affichage_horaire(heure_a_thimphou, "Thimphou");

	printf("\n");
	printf("République de Turquie:\n");
	calcul_et_affichage_horaire(heure_a_istanbul, "Istanbul");

	printf("\n");
	printf("Fédération de Russie:\n");
	calcul_et_affichage_horaire(heure_moscou, "Moscou");
        calcul_et_affichage_horaire(heure_vladivostok, "Vladivostok");
	calcul_et_affichage_horaire(heure_kaliningrad, "Kaliningrad");
	calcul_et_affichage_horaire(heure_samara, "Samara");
	calcul_et_affichage_horaire(heure_volgograd, "Volgograd");
	calcul_et_affichage_horaire(heure_saratov, "Saratov");
	calcul_et_affichage_horaire(heure_oulianovsk, "Oulianovsk");
	calcul_et_affichage_horaire(heure_astrakhan, "Astrakhan");
	calcul_et_affichage_horaire(heure_anadyr, "Anadyr");
	calcul_et_affichage_horaire(heure_sakhalin, "Sakhalin");
	calcul_et_affichage_horaire(heure_omsk, "Omsk");
	calcul_et_affichage_horaire(heure_tchita, "Tchita");
	calcul_et_affichage_horaire(heure_tomsk, "Tomsk");
	calcul_et_affichage_horaire(heure_barnaoul, "Barnaoul");
	calcul_et_affichage_horaire(heure_magadan, "Magadan");
	calcul_et_affichage_horaire(heure_iekaterinbourg, "Iekaterinbourg");
	calcul_et_affichage_horaire(heure_yakoutsk, "Yakoutsk");
	calcul_et_affichage_horaire(heure_irkoutsk, "Irkoutsk");
	calcul_et_affichage_horaire(heure_khandyga, "Khandyga");
	calcul_et_affichage_horaire(heure_novokouznetsk, "Novokouznetsk");
	calcul_et_affichage_horaire(heure_nobossibirsk, "Nobossibirsk");
	calcul_et_affichage_horaire(heure_krasnoyarsk, "Krasnoyarsk");
	calcul_et_affichage_horaire(heure_oust_nera, "Oust-Nera");
	calcul_et_affichage_horaire(heure_srednekolymsk, "Srednekolymsk");

	printf("\n");
	printf("République d'Arménie:\n");
	calcul_et_affichage_horaire(heure_erevan, "Erevan");

	printf("\n");
	printf("Géorgie:\n");
	calcul_et_affichage_horaire(heure_a_tbilissi, "Tbilissi");

	printf("\n");
	printf("République d'Azerbaïdjan:\n");
	calcul_et_affichage_horaire(heure_a_bakou, "Bakou");

	printf("\n");
	printf("Mongolie:\n");
	calcul_et_affichage_horaire(heure_a_choibalsan, "Choibalsan");
	calcul_et_affichage_horaire(heure_a_ulaanbaatar, "Ulaanbaatar");
	calcul_et_affichage_horaire(heure_a_hovd, "Hovd");

	printf("\n");
}
