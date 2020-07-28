/****************************************************************************
 ** Deling Final Fantasy VIII Field Editor
 ** Copyright (C) 2009-2012 Arzel Jérôme <myst6re@gmail.com>
 **
 ** This program is free software: you can redistribute it and/or modify
 ** it under the terms of the GNU General Public License as published by
 ** the Free Software Foundation, either version 3 of the License, or
 ** (at your option) any later version.
 **
 ** This program is distributed in the hope that it will be useful,
 ** but WITHOUT ANY WARRANTY; without even the implied warranty of
 ** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 ** GNU General Public License for more details.
 **
 ** You should have received a copy of the GNU General Public License
 ** along with this program.  If not, see <http://www.gnu.org/licenses/>.
 ****************************************************************************/
#include "Data.h"

QString Data::AppPathCache;

bool Data::ff8Found()
{
	return QFile::exists(AppPath() % "/FF8.exe");
}

QString Data::AppPath()
{
	if(Config::value("dontUseRegAppPath").toBool()) {
		return Config::value("appPath").toString();
	}

	if(AppPathCache.isNull()) {
		QSettings settings("Square Soft, Inc", "Final Fantasy VIII");
		AppPathCache = QDir::cleanPath(settings.value("1.00/AppPath", "").toString());
	}
	return AppPathCache;
}

QString Data::location(int i)
{
	return i<LOC_COUNT && i>=0 ? tr(locations[i].source, locations[i].comment) : "";
}

TranslateChar Data::locations[LOC_COUNT] = {
	QT_TRANSLATE_NOOP3("Data","???","0"), QT_TRANSLATE_NOOP3("Data","Plaines d'Arkland - Balamb","1"), QT_TRANSLATE_NOOP3("Data","Monts Gaulg - Balamb","2"), QT_TRANSLATE_NOOP3("Data","Baie de Rinaul - Balamb","3"), QT_TRANSLATE_NOOP3("Data","Cap Raha - Balamb","4"), QT_TRANSLATE_NOOP3("Data","Forêt de Rosfall - Timber","5"), QT_TRANSLATE_NOOP3("Data","Mandy Beach - Timber","6"), QT_TRANSLATE_NOOP3("Data","Lac Obel - Timber","7"), QT_TRANSLATE_NOOP3("Data","Vallée de Lanker - Timber","8"), QT_TRANSLATE_NOOP3("Data","Ile Nantakhet - Timber","9"), QT_TRANSLATE_NOOP3("Data","Yaulny Canyon - Timber","10"), QT_TRANSLATE_NOOP3("Data","Val Hasberry - Dollet","11"), QT_TRANSLATE_NOOP3("Data","Cap Holy Glory - Dollet","12"), QT_TRANSLATE_NOOP3("Data","Longhorn Island - Dollet","13"), QT_TRANSLATE_NOOP3("Data","Péninsule Malgo - Dollet","14"), QT_TRANSLATE_NOOP3("Data","Plateau Monterosa - Galbadia","15"),
	QT_TRANSLATE_NOOP3("Data","Lallapalooza Canyon - Galbadia","16"), QT_TRANSLATE_NOOP3("Data","Shenand Hill - Timber","17"), QT_TRANSLATE_NOOP3("Data","Péninsule Gotland - Galbadia","18"), QT_TRANSLATE_NOOP3("Data","Ile de l'Enfer - Galbadia","19"), QT_TRANSLATE_NOOP3("Data","Plaine Galbadienne","20"), QT_TRANSLATE_NOOP3("Data","Wilburn Hill - Galbadia","21"), QT_TRANSLATE_NOOP3("Data","Archipel Rem - Galbadia","22"), QT_TRANSLATE_NOOP3("Data","Dingo Désert - Galbadia","23"), QT_TRANSLATE_NOOP3("Data","Cap Winhill","24"), QT_TRANSLATE_NOOP3("Data","Archipel Humphrey - Winhill","25"), QT_TRANSLATE_NOOP3("Data","Ile Winter - Trabia","26"), QT_TRANSLATE_NOOP3("Data","Val de Solvard - Trabia","27"), QT_TRANSLATE_NOOP3("Data","Crête d'Eldbeak - Trabia","28"), QT_TRANSLATE_NOOP3("Data","","29"), QT_TRANSLATE_NOOP3("Data","Plaine d'Hawkind - Trabia","30"), QT_TRANSLATE_NOOP3("Data","Atoll Albatross - Trabia","31"),
	QT_TRANSLATE_NOOP3("Data","Vallon de Bika - Trabia","32"), QT_TRANSLATE_NOOP3("Data","Péninsule Thor - Trabia","33"), QT_TRANSLATE_NOOP3("Data","","34"), QT_TRANSLATE_NOOP3("Data","Crête d'Heath - Trabia","35"), QT_TRANSLATE_NOOP3("Data","Trabia Crater - Trabia","36"), QT_TRANSLATE_NOOP3("Data","Mont Vienne - Trabia","37"), QT_TRANSLATE_NOOP3("Data","Plaine de Mordor - Esthar","38"), QT_TRANSLATE_NOOP3("Data","Mont Nortes - Esthar","39"), QT_TRANSLATE_NOOP3("Data","Atoll Fulcura - Esthar","40"), QT_TRANSLATE_NOOP3("Data","Forêt Grandidi - Esthar","41"), QT_TRANSLATE_NOOP3("Data","Iles Millefeuilles - Esthar","42"), QT_TRANSLATE_NOOP3("Data","Grandes plaines d'Esthar","43"), QT_TRANSLATE_NOOP3("Data","Esthar City","44"), QT_TRANSLATE_NOOP3("Data","Salt Lake - Esthar","45"), QT_TRANSLATE_NOOP3("Data","Côte Ouest - Esthar","46"), QT_TRANSLATE_NOOP3("Data","Mont Sollet - Esthar","47"),
	QT_TRANSLATE_NOOP3("Data","Vallée d'Abadan - Esthar","48"), QT_TRANSLATE_NOOP3("Data","Ile Minde - Esthar","49"), QT_TRANSLATE_NOOP3("Data","Désert Kashkabald - Esthar","50"), QT_TRANSLATE_NOOP3("Data","Ile Paradisiaque - Esthar","51"), QT_TRANSLATE_NOOP3("Data","Pic de Talle - Esthar","52"), QT_TRANSLATE_NOOP3("Data","Atoll Shalmal - Esthar","53"), QT_TRANSLATE_NOOP3("Data","Vallée de Lolestern - Centra","54"), QT_TRANSLATE_NOOP3("Data","Aiguille d'Almage - Centra","55"), QT_TRANSLATE_NOOP3("Data","Vallon Lenown - Centra","56"), QT_TRANSLATE_NOOP3("Data","Cap de l'espoir - Centra","57"), QT_TRANSLATE_NOOP3("Data","Mont Yorn - Centra","58"), QT_TRANSLATE_NOOP3("Data","Ile Pampa - Esthar","59"), QT_TRANSLATE_NOOP3("Data","Val Serengetti - Centra","60"), QT_TRANSLATE_NOOP3("Data","Péninsule Nectalle - Centra","61"), QT_TRANSLATE_NOOP3("Data","Centra Crater - Centra","62"), QT_TRANSLATE_NOOP3("Data","Ile Poccarahi - Centra","63"),
	QT_TRANSLATE_NOOP3("Data","Bibliothèque - BGU","64"), QT_TRANSLATE_NOOP3("Data","Entrée - BGU","65"), QT_TRANSLATE_NOOP3("Data","Salle de cours - BGU","66"), QT_TRANSLATE_NOOP3("Data","Cafétéria - BGU","67"), QT_TRANSLATE_NOOP3("Data","Niveau MD - BGU","68"), QT_TRANSLATE_NOOP3("Data","Hall 1er étage - BGU","69"), QT_TRANSLATE_NOOP3("Data","Hall - BGU","70"), QT_TRANSLATE_NOOP3("Data","Infirmerie - BGU","71"), QT_TRANSLATE_NOOP3("Data","Dortoirs doubles - BGU","72"), QT_TRANSLATE_NOOP3("Data","Dortoirs simples - BGU","73"), QT_TRANSLATE_NOOP3("Data","Bureau proviseur - BGU","74"), QT_TRANSLATE_NOOP3("Data","Parking - BGU","75"), QT_TRANSLATE_NOOP3("Data","Salle de bal - BGU","76"), QT_TRANSLATE_NOOP3("Data","Campus - BGU","77"), QT_TRANSLATE_NOOP3("Data","Serre de combat - BGU","78"), QT_TRANSLATE_NOOP3("Data","Zone secrète - BGU","79"),
	QT_TRANSLATE_NOOP3("Data","Corridor - BGU","80"), QT_TRANSLATE_NOOP3("Data","Temple - BGU","81"), QT_TRANSLATE_NOOP3("Data","Pont - BGU","82"), QT_TRANSLATE_NOOP3("Data","Villa Dincht - Balamb","83"), QT_TRANSLATE_NOOP3("Data","Hôtel - Balamb","84"), QT_TRANSLATE_NOOP3("Data","Place centrale - Balamb","85"), QT_TRANSLATE_NOOP3("Data","Place de la gare - Balamb","86"), QT_TRANSLATE_NOOP3("Data","Port - Balamb","87"), QT_TRANSLATE_NOOP3("Data","Résidence - Balamb","88"), QT_TRANSLATE_NOOP3("Data","Train","89"), QT_TRANSLATE_NOOP3("Data","Voiture","90"), QT_TRANSLATE_NOOP3("Data","Vaisseau","91"), QT_TRANSLATE_NOOP3("Data","Mine de souffre","92"), QT_TRANSLATE_NOOP3("Data","Place du village - Dollet","93"), QT_TRANSLATE_NOOP3("Data","Zuma Beach","94"), QT_TRANSLATE_NOOP3("Data","Port -Dollet","95"),
	QT_TRANSLATE_NOOP3("Data","Pub - Dollet","96"), QT_TRANSLATE_NOOP3("Data","Hôtel - Dollet","97"), QT_TRANSLATE_NOOP3("Data","Résidence - Dollet","98"), QT_TRANSLATE_NOOP3("Data","Tour satellite - Dollet","99"), QT_TRANSLATE_NOOP3("Data","Refuge montagneux - Dollet","100"), QT_TRANSLATE_NOOP3("Data","Centre ville - Timber","101"), QT_TRANSLATE_NOOP3("Data","Chaîne de TV - Timber","102"), QT_TRANSLATE_NOOP3("Data","Base des Hiboux - Timber","103"), QT_TRANSLATE_NOOP3("Data","Pub - Timber","104"), QT_TRANSLATE_NOOP3("Data","Hôtel - Timber","105"), QT_TRANSLATE_NOOP3("Data","Train - Timber","106"), QT_TRANSLATE_NOOP3("Data","Résidence - Timber","107"), QT_TRANSLATE_NOOP3("Data","Ecran géant - Timber","108"), QT_TRANSLATE_NOOP3("Data","Centre de presse - Timber","109"), QT_TRANSLATE_NOOP3("Data","Forêt de Timber","110"), QT_TRANSLATE_NOOP3("Data","Entrée - Fac deGalbadia","111"),
	QT_TRANSLATE_NOOP3("Data","Station Fac de Galbadia","112"), QT_TRANSLATE_NOOP3("Data","Hall - Fac de Galbadia","113"), QT_TRANSLATE_NOOP3("Data","Corridor - Fac de Galbadia","114"), QT_TRANSLATE_NOOP3("Data","Salle d'attente - Fac Galbadia","115"), QT_TRANSLATE_NOOP3("Data","Salle de cours - Fac Galbadia","116"), QT_TRANSLATE_NOOP3("Data","Salle de réunion - Fac Galbadia","117"), QT_TRANSLATE_NOOP3("Data","Dortoirs - Fac de Galbadia","118"), QT_TRANSLATE_NOOP3("Data","Ascenseur - Fac de Galbadia","119"), QT_TRANSLATE_NOOP3("Data","Salle recteur - Fac Galbadia","120"), QT_TRANSLATE_NOOP3("Data","Auditorium - Fac de Galbadia","121"), QT_TRANSLATE_NOOP3("Data","Stade - Fac de Galbadia","122"), QT_TRANSLATE_NOOP3("Data","Stand - Fac de Galbadia","123"), QT_TRANSLATE_NOOP3("Data","2nde entrée - Fac Galbadia","124"), QT_TRANSLATE_NOOP3("Data","Gymnase - Fac de Galbadia","125"), QT_TRANSLATE_NOOP3("Data","Palais président - Deling City","126"), QT_TRANSLATE_NOOP3("Data","Manoir Caraway - Deling City","127"),
	QT_TRANSLATE_NOOP3("Data","Gare - Deling City","128"), QT_TRANSLATE_NOOP3("Data","Place centrale - Deling City","129"), QT_TRANSLATE_NOOP3("Data","Hôtel - Deling City","130"), QT_TRANSLATE_NOOP3("Data","Bar - Deling City","131"), QT_TRANSLATE_NOOP3("Data","Sortie - Deling City","132"), QT_TRANSLATE_NOOP3("Data","Parade - Deling City","133"), QT_TRANSLATE_NOOP3("Data","Egout - Deling City","134"), QT_TRANSLATE_NOOP3("Data","Prison du désert - Galbadia","135"), QT_TRANSLATE_NOOP3("Data","Désert","136"), QT_TRANSLATE_NOOP3("Data","Base des missiles","137"), QT_TRANSLATE_NOOP3("Data","Village de Winhill","138"), QT_TRANSLATE_NOOP3("Data","Pub - Winhill","139"), QT_TRANSLATE_NOOP3("Data","Maison vide - Winhill","140"), QT_TRANSLATE_NOOP3("Data","Manoir - Winhill","141"), QT_TRANSLATE_NOOP3("Data","Résidence - Winhill","142"), QT_TRANSLATE_NOOP3("Data","Hôtel - Winhill","143"),
	QT_TRANSLATE_NOOP3("Data","Voiture - Winhill","144"), QT_TRANSLATE_NOOP3("Data","Tombe du roi inconnu","145"), QT_TRANSLATE_NOOP3("Data","Horizon","146"), QT_TRANSLATE_NOOP3("Data","Habitations - Horizon","147"), QT_TRANSLATE_NOOP3("Data","Ecrans solaires - Horizon","148"), QT_TRANSLATE_NOOP3("Data","Villa du maire - Horizon","149"), QT_TRANSLATE_NOOP3("Data","Usine - Horizon","150"), QT_TRANSLATE_NOOP3("Data","Salle des fêtes - Horizon","151"), QT_TRANSLATE_NOOP3("Data","Hôtel - Horizon","152"), QT_TRANSLATE_NOOP3("Data","Résidence - Horizon","153"), QT_TRANSLATE_NOOP3("Data","Gare - Horizon","154"), QT_TRANSLATE_NOOP3("Data","Aqueduc d'Horizon","155"), QT_TRANSLATE_NOOP3("Data","Station balnéaire","156"), QT_TRANSLATE_NOOP3("Data","Salt Lake","157"), QT_TRANSLATE_NOOP3("Data","Bâtiment mystérieux","158"), QT_TRANSLATE_NOOP3("Data","Esthar City","159"),
	QT_TRANSLATE_NOOP3("Data","Laboratoire Geyser - Esthar","160"), QT_TRANSLATE_NOOP3("Data","Aérodrome - Esthar","161"), QT_TRANSLATE_NOOP3("Data","Lunatic Pandora approche","162"), QT_TRANSLATE_NOOP3("Data","Résidence président - Esthar","163"), QT_TRANSLATE_NOOP3("Data","Hall - Résidence président","164"), QT_TRANSLATE_NOOP3("Data","Couloir - Résidence président","165"), QT_TRANSLATE_NOOP3("Data","Bureau - Résidence président","166"), QT_TRANSLATE_NOOP3("Data","Accueil - Labo Geyser","167"), QT_TRANSLATE_NOOP3("Data","Laboratoire Geyser","168"), QT_TRANSLATE_NOOP3("Data","Deleted","169"), QT_TRANSLATE_NOOP3("Data","Lunar Gate","170"), QT_TRANSLATE_NOOP3("Data","Parvis - Lunar Gate","171"), QT_TRANSLATE_NOOP3("Data","Glacière - Lunar gate","172"), QT_TRANSLATE_NOOP3("Data","Mausolée - Esthar","173"), QT_TRANSLATE_NOOP3("Data","Entrée - Mausolée","174"), QT_TRANSLATE_NOOP3("Data","Pod de confinement -Mausolée","175"),
	QT_TRANSLATE_NOOP3("Data","Salle de contrôle - Mausolée","176"), QT_TRANSLATE_NOOP3("Data","Tears Point","177"), QT_TRANSLATE_NOOP3("Data","Labo Lunatic Pandora","178"), QT_TRANSLATE_NOOP3("Data","Zone d'atterrissage de secours","179"), QT_TRANSLATE_NOOP3("Data","Zone d'atterrissage officielle","180"), QT_TRANSLATE_NOOP3("Data","Lunatic Pandora","181"), QT_TRANSLATE_NOOP3("Data","Site des fouilles - Centra","182"), QT_TRANSLATE_NOOP3("Data","Orphelinat","183"), QT_TRANSLATE_NOOP3("Data","Salle de jeux - Orphelinat","184"), QT_TRANSLATE_NOOP3("Data","Dortoir - Orphelinat","185"), QT_TRANSLATE_NOOP3("Data","Jardin - Orphelinat","186"), QT_TRANSLATE_NOOP3("Data","Front de mer - Orphelinat","187"), QT_TRANSLATE_NOOP3("Data","Champ - Orphelinat","188"), QT_TRANSLATE_NOOP3("Data","Ruines de Centra","189"), QT_TRANSLATE_NOOP3("Data","Entrée - Fac de Trabia","190"), QT_TRANSLATE_NOOP3("Data","Cimetière - Fac deTrabia","191"),
	QT_TRANSLATE_NOOP3("Data","Garage - Fac de Trabia","192"), QT_TRANSLATE_NOOP3("Data","Campus - Fac Trabia","193"), QT_TRANSLATE_NOOP3("Data","Amphithéatre - Fac de Trabia","194"), QT_TRANSLATE_NOOP3("Data","Stade - Fac de Trabia","195"), QT_TRANSLATE_NOOP3("Data","Dôme mystérieux","196"), QT_TRANSLATE_NOOP3("Data","Ville du désert - Shumi Village","197"), QT_TRANSLATE_NOOP3("Data","Ascenseur - Shumi Village","198"), QT_TRANSLATE_NOOP3("Data","Shumi Village","199"), QT_TRANSLATE_NOOP3("Data","Habitation - Shumi Village","200"), QT_TRANSLATE_NOOP3("Data","Résidence - Shumi Village","201"), QT_TRANSLATE_NOOP3("Data","Habitat - Shumi Village","202"), QT_TRANSLATE_NOOP3("Data","Hôtel - Shumi Village","203"), QT_TRANSLATE_NOOP3("Data","Trabia canyon","204"), QT_TRANSLATE_NOOP3("Data","Vaisseau des Seeds blancs","205"), QT_TRANSLATE_NOOP3("Data","Navire des Seeds Blancs","206"), QT_TRANSLATE_NOOP3("Data","Cabine - Navire Seeds blancs","207"),
	QT_TRANSLATE_NOOP3("Data","Cockpit - Hydre","208"), QT_TRANSLATE_NOOP3("Data","Siège passager - Hydre","209"), QT_TRANSLATE_NOOP3("Data","Couloir - Hydre","210"), QT_TRANSLATE_NOOP3("Data","Hangar - Hydre","211"), QT_TRANSLATE_NOOP3("Data","Accès - Hydre","212"), QT_TRANSLATE_NOOP3("Data","Air Room - Hydre","213"), QT_TRANSLATE_NOOP3("Data","Salle de pression - Hydre","214"), QT_TRANSLATE_NOOP3("Data","Centre de recherches Deep Sea","215"), QT_TRANSLATE_NOOP3("Data","Laboratoire - Deep Sea","216"), QT_TRANSLATE_NOOP3("Data","Salle de travail - Deep Sea","217"), QT_TRANSLATE_NOOP3("Data","Fouilles - Deep Sea","218"), QT_TRANSLATE_NOOP3("Data","Salle de contrôle - Base lunaire","219"), QT_TRANSLATE_NOOP3("Data","Centre médical - Base lunaire","220"), QT_TRANSLATE_NOOP3("Data","Pod - Base lunaire","221"), QT_TRANSLATE_NOOP3("Data","Dock - Base lunaire","222"), QT_TRANSLATE_NOOP3("Data","Passage - Base lunaire","223"),
	QT_TRANSLATE_NOOP3("Data","Vestiaire - Base lunaire","224"), QT_TRANSLATE_NOOP3("Data","Habitats - Base lunaire","225"), QT_TRANSLATE_NOOP3("Data","Hyper Espace","226"), QT_TRANSLATE_NOOP3("Data","Forêt Chocobo","227"), QT_TRANSLATE_NOOP3("Data","Jungle","228"), QT_TRANSLATE_NOOP3("Data","Citadelle d'Ultimecia - Vestibule","229"), QT_TRANSLATE_NOOP3("Data","Citadelle d'Ultimecia - Hall","230"), QT_TRANSLATE_NOOP3("Data","Citadelle d'Ultimecia - Terrasse","231"), QT_TRANSLATE_NOOP3("Data","Citadelle d'Ultimecia - Cave","232"), QT_TRANSLATE_NOOP3("Data","Citadelle d'Ultimecia - Couloir","233"), QT_TRANSLATE_NOOP3("Data","Elévateur - Citadelle","234"), QT_TRANSLATE_NOOP3("Data","Escalier - Citadelle d'Ultimecia","235"), QT_TRANSLATE_NOOP3("Data","Salle du trésor - Citadelle","236"), QT_TRANSLATE_NOOP3("Data","Salle de rangement - Citadelle","237"), QT_TRANSLATE_NOOP3("Data","Citadelle d'Ultimecia - Galerie","238"), QT_TRANSLATE_NOOP3("Data","Citadelle d'Ultimecia - Ecluse","239"),
	QT_TRANSLATE_NOOP3("Data","Citadelle - Armurerie","240"), QT_TRANSLATE_NOOP3("Data","Citadelle d'Ultimecia - Prison","241"), QT_TRANSLATE_NOOP3("Data","Citadelle d'Ultimecia - Fossé","242"), QT_TRANSLATE_NOOP3("Data","Citadelle d'Ultimecia - Jardin","243"), QT_TRANSLATE_NOOP3("Data","Citadelle d'Ultimecia - Chapelle","244"), QT_TRANSLATE_NOOP3("Data","Clocher - Citadelle d'Ultimecia","245"), QT_TRANSLATE_NOOP3("Data","Chambre d'Ultimecia - Citadelle","246"), QT_TRANSLATE_NOOP3("Data","???","247"), QT_TRANSLATE_NOOP3("Data","Citadelle d'Ultimecia","248"), QT_TRANSLATE_NOOP3("Data","Salle d'initiation","249"), QT_TRANSLATE_NOOP3("Data","Reine des cartes","250"), QT_TRANSLATE_NOOP3("Data","???","251"), QT_TRANSLATE_NOOP3("Data","???","252"), QT_TRANSLATE_NOOP3("Data","???","253"), QT_TRANSLATE_NOOP3("Data","???","254"), QT_TRANSLATE_NOOP3("Data","???","255")
};

QString Data::name(int i)
{
	static const char *names[NAM_COUNT] = {
		QT_TR_NOOP("Squall"), QT_TR_NOOP("Zell"), QT_TR_NOOP("Irvine"), QT_TR_NOOP("Quistis"), QT_TR_NOOP("Linoa"),
		QT_TR_NOOP("Selphie"), QT_TR_NOOP("Seifer"), QT_TR_NOOP("Edea"), QT_TR_NOOP("Laguna"), QT_TR_NOOP("Kiros"),
		QT_TR_NOOP("Ward"), "", QT_TR_NOOP("Cronos"), QT_TR_NOOP("MiniMog"), QT_TR_NOOP("Boko"), QT_TR_NOOP("Angel")
	};

	return i<NAM_COUNT && i>=0 ? tr(names[i]) : "";
}

QString Data::magic(int i)
{
	static const char *_magic[MAG_COUNT] = {
		"-", QT_TR_NOOP("Brasier"), QT_TR_NOOP("Brasier+"), QT_TR_NOOP("BrasierX"), QT_TR_NOOP("Glacier"), QT_TR_NOOP("Glacier+"),
		QT_TR_NOOP("GlacierX"), QT_TR_NOOP("Foudre"), QT_TR_NOOP("Foudre+"), QT_TR_NOOP("FoudreX"), QT_TR_NOOP("H2O"), QT_TR_NOOP("Rafale"), QT_TR_NOOP("Cyanure"),
		QT_TR_NOOP("Quart"), QT_TR_NOOP("Sidéral"), QT_TR_NOOP("Fournaise"), QT_TR_NOOP("Météore"), QT_TR_NOOP("Quake"), QT_TR_NOOP("Tornade"), QT_TR_NOOP("Ultima"),
		QT_TR_NOOP("Apocalypse"), QT_TR_NOOP("Soin"), QT_TR_NOOP("Soin+"), QT_TR_NOOP("Soin Max"), QT_TR_NOOP("Vie"), QT_TR_NOOP("Vie Max"), QT_TR_NOOP("Récup"), QT_TR_NOOP("Esuna"),
		QT_TR_NOOP("Anti-sort"), QT_TR_NOOP("Carapace"), QT_TR_NOOP("Blindage"), QT_TR_NOOP("Boormg"), QT_TR_NOOP("Aura"), QT_TR_NOOP("Double"), QT_TR_NOOP("Triple"), QT_TR_NOOP("Booster"),
		QT_TR_NOOP("Somni"), QT_TR_NOOP("Stop"), QT_TR_NOOP("Cécité"), QT_TR_NOOP("Folie"), QT_TR_NOOP("Morphée"), QT_TR_NOOP("Aphasie"), QT_TR_NOOP("Mégalith"), QT_TR_NOOP("Ankou"),
		QT_TR_NOOP("Saignée"), QT_TR_NOOP("Supplice"), QT_TR_NOOP("Furie"), QT_TR_NOOP("Décubitus"), QT_TR_NOOP("Zombie"), QT_TR_NOOP("Meltdown"), QT_TR_NOOP("Scan"), QT_TR_NOOP("Joobu"),
		QT_TR_NOOP("Wall"), QT_TR_NOOP("Arkange"), QT_TR_NOOP("Percent"), QT_TR_NOOP("Catastrophe"), QT_TR_NOOP("The End")
	};

	return i<MAG_COUNT && i>=0 ? tr(_magic[i]) : "";
}

QStringList Data::maplist()
{
	QStringList maps;
	for(int i=0 ; i<MAP_COUNT ; ++i) {
		maps.append(_maplist[i]);
	}
	return maps;
}

const char *Data::_maplist[MAP_COUNT] = {
	"wm00",
	"wm01",
	"wm02",
	"wm03",
	"wm04",
	"wm05",
	"wm06",
	"wm07",
	"wm08",
	"wm09",
	"wm10",
	"wm11",
	"wm12",
	"wm13",
	"wm14",
	"wm15",
	"wm16",
	"wm17",
	"wm18",
	"wm19",
	"wm20",
	"wm21",
	"wm22",
	"wm23",
	"wm24",
	"wm25",
	"wm26",
	"wm27",
	"wm28",
	"wm29",
	"wm30",
	"wm31",
	"wm32",
	"wm33",
	"wm34",
	"wm35",
	"wm36",
	"wm37",
	"wm38",
	"wm39",
	"wm40",
	"wm41",
	"wm42",
	"wm43",
	"wm44",
	"wm45",
	"wm46",
	"wm47",
	"wm48",
	"wm49",
	"wm50",
	"wm51",
	"wm52",
	"wm53",
	"wm54",
	"wm55",
	"wm56",
	"wm57",
	"wm58",
	"wm59",
	"wm60",
	"wm61",
	"wm62",
	"wm63",
	"wm64",
	"wm65",
	"wm66",
	"wm67",
	"wm68",
	"wm69",
	"wm70",
	"wm71",
	"testno",
	"start",
	"start0",
	"gover",
	"ending",
	"test",
	"test1",
	"test2",
	"test3",
	"test4",
	"test5",
	"test6",
	"test7",
	"test8",
	"test9",
	"test13",
	"test14",
	"testbl0",
	"testbl1",
	"testbl2",
	"testbl3",
	"testbl4",
	"testbl5",
	"testbl6",
	"testbl7",
	"testbl8",
	"testbl9",
	"testbl13",
	"testbl14",
	"testmv",
	"bccent_1",
	"bccent1a",
	"bcform_1",
	"bcform1a",
	"bcgate_1",
	"bcgate1a",
	"bchtl_1",
	"bchtl1a",
	"bchtr_1",
	"bchtr1a",
	"bcmin1_1",
	"bcmin11a",
	"bcmin2_1",
	"bcmin21a",
	"bcmin2_2",
	"bcmin22a",
	"bcmin2_3",
	"bcmin23a",
	"bcport_1",
	"bcport1a",
	"bcport1b",
	"bcport_2",
	"bcport2a",
	"bcsaka_1",
	"bcsaka1a",
	"bcsta_1",
	"bcsta1a",
	"bdenter1",
	"bdifrit1",
	"bdin1",
	"bdin2",
	"bdin3",
	"bdin4",
	"bdin5",
	"bdview1",
	"bg2f_1",
	"bg2f_11",
	"bg2f_2",
	"bg2f_21",
	"bg2f_4",
	"bg2f_22",
	"bg2f_3",
	"bg2f_31",
	"bgbook_1",
	"bgbook1a",
	"bgbook1b",
	"bgbook_2",
	"bgbook2a",
	"bgbook_3",
	"bgbook3a",
	"bgbtl_1",
	"bgcrash1",
	"bgeat_1",
	"bgeat1a",
	"bgeat_2",
	"bgeat2a",
	"bgeat_3",
	"bggate_1",
	"bggate_2",
	"bggate_4",
	"bggate_5",
	"bggate_6",
	"bggate6a",
	"bghall_1",
	"bghall1a",
	"bghall1b",
	"bghall_2",
	"bghall2a",
	"bghall_3",
	"bghall3a",
	"bghall_4",
	"bghall4a",
	"bghall_5",
	"bghall_6",
	"bghall6b",
	"bghall_7",
	"bghall_8",
	"bghoke_1",
	"bghoke_2",
	"bghoke_3",
	"bgkote_1",
	"bgkote1a",
	"bgkote_2",
	"bgkote_3",
	"bgkote3a",
	"bgkote_4",
	"bgkote_5",
	"bgmast_1",
	"bgmast_2",
	"bgmast_3",
	"bgmast_4",
	"bgmast_5",
	"bgmd1_1",
	"bgmd1_2",
	"bgmd1_3",
	"bgmd1_4",
	"bgmd2_1",
	"bgmd2_3",
	"bgmd2_4",
	"bgmd2_5",
	"bgmd2_6",
	"bgmd2_7",
	"bgmd2_8",
	"bgmd3_1",
	"bgmd3_2",
	"bgmd4_1",
	"bgmd4_2",
	"bgmd4_3",
	"bgmdele1",
	"bgmdele2",
	"bgmdele3",
	"bgmdele4",
	"bgmon_1",
	"bgmon_2",
	"bgmon_3",
	"bgmon_4",
	"bgmon_5",
	"bgmon_6",
	"bgpark_1",
	"bgpaty_1",
	"bgpaty_2",
	"bgrank1",
	"bgroad_1",
	"bgroad_2",
	"bgroad_3",
	"bgroad_4",
	"bgroad_5",
	"bgroad_6",
	"bgroad_7",
	"bgroad_9",
	"bgroom_1",
	"bgroom_3",
	"bgroom_4",
	"bgroom_5",
	"bgroom_6",
	"bgryo1_1",
	"bgryo1_2",
	"bgryo1_3",
	"bgryo1_4",
	"bgryo1_5",
	"bgryo1_6",
	"bgryo1_7",
	"bgryo1_8",
	"bgryo2_1",
	"bgryo2_2",
	"bgsecr_1",
	"bgsecr_2",
	"bgsido_1",
	"bgsido1a",
	"bgsido_2",
	"bgsido_3",
	"bgsido_4",
	"bgsido_5",
	"bgsido5a",
	"bgsido_6",
	"bgsido_7",
	"bgsido_8",
	"bgsido_9",
	"bvboat_1",
	"bvboat_2",
	"bvcar_1",
	"bvtr_1",
	"bvtr_2",
	"bvtr_3",
	"bvtr_4",
	"bvtr_5",
	"cdfield1",
	"cdfield2",
	"cdfield3",
	"cdfield4",
	"cdfield5",
	"cdfield6",
	"cdfield7",
	"cdfield8",
	"crenter1",
	"crodin1",
	"cropen1",
	"crpower1",
	"crroof1",
	"crsanc1",
	"crsphi1",
	"crtower1",
	"crtower2",
	"crtower3",
	"crview1",
	"cwwood1",
	"cwwood2",
	"cwwood3",
	"cwwood4",
	"cwwood5",
	"cwwood6",
	"cwwood7",
	"ddruins1",
	"ddruins2",
	"ddruins3",
	"ddruins4",
	"ddruins5",
	"ddruins6",
	"ddsteam1",
	"ddtower1",
	"ddtower2",
	"ddtower3",
	"ddtower4",
	"ddtower5",
	"ddtower6",
	"doan1_1",
	"doan1_2",
	"doani1_1",
	"doani1_2",
	"doani3_1",
	"doani3_2",
	"doani4_1",
	"doani4_2",
	"dogate_1",
	"dogate1a",
	"dogate_2",
	"dohtl_1",
	"dohtr_1",
	"domin2_1",
	"domt1_1",
	"domt2_1",
	"domt3_1",
	"domt3_2",
	"domt3_3",
	"domt3_4",
	"domt4_1",
	"domt5_1",
	"domt6_1",
	"doopen_1",
	"doopen1a",
	"doopen_2",
	"doopen2a",
	"doport_1",
	"dopub_1",
	"dopub_2",
	"dopub_3",
	"dosea_1",
	"dosea_2",
	"dotown_1",
	"dotown1a",
	"dotown_2",
	"dotown2a",
	"dotown_3",
	"dotown3a",
	"eaplane1",
	"eapod1",
	"ebadele1",
	"ebadele2",
	"ebadele3",
	"ebadele5",
	"ebcont1",
	"ebcont2",
	"ebexit1",
	"ebexit2",
	"ebexit3",
	"ebexit4",
	"ebexit5",
	"ebexit6",
	"ebgate1",
	"ebgate1a",
	"ebgate2",
	"ebgate2a",
	"ebgate3",
	"ebgate3a",
	"ebgate4",
	"ebgate4a",
	"ebinhi1",
	"ebinhi1a",
	"ebinlow1",
	"ebinlow2",
	"ebinmid1",
	"ebinmid4",
	"ebinmid2",
	"ebinmid5",
	"ebinmid3",
	"ebinmid6",
	"ebinto1",
	"ebinto2",
	"ebinto3",
	"ebroad11",
	"ebroad12",
	"ebroad13",
	"ebroad21",
	"ebroad22",
	"ebroad23",
	"ebroad31",
	"ebroad32",
	"ebroad33",
	"ebroad41",
	"ebroad42",
	"ebroad43",
	"ebroad5",
	"ebroad6",
	"ebroad6a",
	"ebroad7",
	"ebroad7a",
	"ebroad8",
	"ebroad8a",
	"ebroad9",
	"ebroad9a",
	"eccway11",
	"eccway15",
	"eccway12",
	"eccway16",
	"eccway13",
	"eccway14",
	"eccway21",
	"eccway22",
	"eccway23",
	"eccway31",
	"eccway32",
	"eccway33",
	"eccway41",
	"eccway42",
	"eccway43",
	"ecenc1",
	"ecenc2",
	"ecenc3",
	"ecenter1",
	"ecenter4",
	"ecenter2",
	"ecenter5",
	"ecenter3",
	"eciway11",
	"eciway15",
	"eciway12",
	"eciway16",
	"eciway13",
	"eciway14",
	"ecmall1",
	"ecmall1a",
	"ecmall1b",
	"ecmview1",
	"ecmview2",
	"ecmview3",
	"ecmway1",
	"ecmway1a",
	"ecmway1b",
	"ecopen1",
	"ecopen1a",
	"ecopen1b",
	"ecopen2",
	"ecopen2a",
	"ecopen2b",
	"ecopen3",
	"ecopen3a",
	"ecopen3b",
	"ecopen4",
	"ecopen4a",
	"ecopen4b",
	"ecoway1",
	"ecoway1a",
	"ecoway1b",
	"ecoway2",
	"ecoway2a",
	"ecoway2b",
	"ecoway3",
	"ecoway3a",
	"ecoway3b",
	"ecpview1",
	"ecpview2",
	"ecpview3",
	"ecpway1",
	"ecpway1a",
	"ecpway1b",
	"ectake1",
	"ectake2",
	"ectake3",
	"edlabo1",
	"edlabo1a",
	"edlabo1b",
	"edmoor1",
	"edview1",
	"edview1a",
	"edview1b",
	"edview2",
	"eein1",
	"eein11",
	"eein12",
	"eein3",
	"eein31",
	"eein32",
	"eeview1",
	"eeview2",
	"eeview3",
	"efbig1",
	"efenter1",
	"efenter2",
	"efenter3",
	"efpod1",
	"efpod1a",
	"efpod1b",
	"efview1",
	"efview1a",
	"efview1b",
	"efview2",
	"ehback1",
	"ehback2",
	"ehblan1",
	"ehblan2",
	"ehblan3",
	"ehdrug1",
	"ehenter1",
	"ehenter2",
	"ehhana1",
	"ehnoki1",
	"ehroom1",
	"ehsea1",
	"ehsea2",
	"elroad1",
	"elroad2",
	"elroad3",
	"elstop1",
	"elview1",
	"elview2",
	"elwall1",
	"elwall2",
	"elwall3",
	"elwall4",
	"embind1",
	"embind1a",
	"embind2",
	"emlabo1",
	"emlabo1a",
	"emlabo1b",
	"emlabo2",
	"emlobby1",
	"emlobby3",
	"emlobby2",
	"emlobby4",
	"ephall1",
	"ephall2",
	"epmeet1",
	"eproad1",
	"eproad2",
	"epwork1",
	"epwork2",
	"epwork3",
	"escont1",
	"escouse1",
	"escouse2",
	"esform1",
	"esfreez1",
	"esview1",
	"esview2",
	"etsta1",
	"etsta2",
	"ewbrdg1",
	"ewdoor1",
	"ewele1",
	"ewele2",
	"ewele3",
	"ewpanel1",
	"ewpanel2",
	"fe2f1",
	"feart1f1",
	"feart1f2",
	"feart2f1",
	"febarac1",
	"febrdg1",
	"feclock1",
	"feclock2",
	"feclock3",
	"feclock4",
	"feclock5",
	"feclock6",
	"fegate1",
	"fehall1",
	"fehall2",
	"fein1",
	"fejail1",
	"felast1",
	"felfst1",
	"felrele1",
	"feopen1",
	"feopen2",
	"feout1",
	"fepic1",
	"fepic2",
	"fepic3",
	"ferfst1",
	"feroad1",
	"feroad2",
	"ferrst1",
	"feteras1",
	"fetre1",
	"feware1",
	"fewater1",
	"fewater2",
	"fewater3",
	"fewine1",
	"fewor1",
	"fewor2",
	"feyard1",
	"ffbrdg1",
	"ffhill1",
	"ffhole1",
	"ffseed1",
	"fhbrdg1",
	"fhdeck1",
	"fhdeck2",
	"fhdeck3",
	"fhdeck4",
	"fhdeck4a",
	"fhdeck5",
	"fhdeck6",
	"fhdeck7",
	"fhdeck7a",
	"fhedge1",
	"fhedge11",
	"fhedge2",
	"fhfish1",
	"fhform1",
	"fhhtl1",
	"fhhtr1",
	"fhmin1",
	"fhpanel1",
	"fhpara11",
	"fhpara12",
	"fhparar1",
	"fhparar2",
	"fhrail2",
	"fhrail3",
	"fhroof1",
	"fhtown1",
	"fhtown21",
	"fhtown22",
	"fhtown23",
	"fhview1",
	"fhwater1",
	"fhwise11",
	"fhwise12",
	"fhwise13",
	"fhwise15",
	"fhwisef1",
	"fhwisef2",
	"gdsand1",
	"gdsand2",
	"gdsand3",
	"gdsta1",
	"gdtrain1",
	"gfcar1",
	"gfcross1",
	"gfcross2",
	"gfelone1",
	"gfelone3",
	"gfelone2",
	"gfelone4",
	"gfhtl1",
	"gfhtl1a",
	"gfhtr1",
	"gfhtr1a",
	"gflain1",
	"gflain1a",
	"gflain11",
	"gflain2",
	"gflain2a",
	"gfmin1",
	"gfmin1a",
	"gfmin2",
	"gfmin2a",
	"gfrich1",
	"gfrich1a",
	"gfview1",
	"gfview1a",
	"gfvill1",
	"gfvill1a",
	"gfvill21",
	"gfvill24",
	"gfvill22",
	"gfvill23",
	"gfvill31",
	"gfvill32",
	"ggback1",
	"ggele1",
	"gggate1",
	"gggate2",
	"gggate3",
	"gggro1",
	"gggroen1",
	"gggroen2",
	"gggym1",
	"gggym2",
	"gghall1",
	"gghall2",
	"ggkodo1",
	"ggkodo2",
	"ggkodo4",
	"ggroad1",
	"ggroad2",
	"ggroad3",
	"ggroad5",
	"ggroad6",
	"ggroad7",
	"ggroad8",
	"ggroad8a",
	"ggroad8b",
	"ggroad9",
	"ggroad9a",
	"ggroad9b",
	"ggroom1",
	"ggroom2",
	"ggroom3",
	"ggroom4",
	"ggroom6",
	"ggroom7",
	"ggsta1",
	"ggstaen1",
	"ggstaen3",
	"ggstand1",
	"ggview1",
	"ggview2",
	"ggwitch1",
	"ggwitch2",
	"glclock1",
	"glclub1",
	"glclub3",
	"glclub4",
	"glform1",
	"glfurin1",
	"glfurin4",
	"glfurin5",
	"glfurin2",
	"glfurin3",
	"glfury1",
	"glfuryb1",
	"glgate1",
	"glgate2",
	"glgate2a",
	"glgate3",
	"glgate3a",
	"glgateb1",
	"glgatei1",
	"glgatei2",
	"glhtl1",
	"glhtr1",
	"glhtr1a",
	"glkara1",
	"glkara2",
	"glmall1",
	"glmall2",
	"glprefr1",
	"glprefr2",
	"glprefr3",
	"glprein1",
	"glpreo1",
	"glpreo2",
	"glpreo3",
	"glrent1",
	"glroad1",
	"glsta1",
	"glsta2",
	"glstage1",
	"glstage3",
	"glstaup1",
	"glstaup4",
	"glstaup2",
	"glstaup5",
	"glstaup3",
	"gltown1",
	"glwater1",
	"glwater2",
	"glwater3",
	"glwater4",
	"glwater5",
	"glwitch1",
	"glyagu1",
	"gmcont1",
	"gmcont2",
	"gmden1",
	"gmhouse1",
	"gmmoni1",
	"gmout1",
	"gmpark1",
	"gmpark2",
	"gmshoot1",
	"gmtika1",
	"gmtika2",
	"gmtika3",
	"gmtika4",
	"gmtika5",
	"gnroad1",
	"gnroad2",
	"gnroad3",
	"gnroad4",
	"gnroad5",
	"gnroom1",
	"gnroom2",
	"gnroom3",
	"gnroom4",
	"gnview1",
	"gparm1",
	"gpbig1",
	"gpbig1a",
	"gpbig2",
	"gpbig2a",
	"gpbig3",
	"gpbigin1",
	"gpbigin3",
	"gpbigin2",
	"gpbigin4",
	"gpbigin5",
	"gpcell1",
	"gpcont1",
	"gpcont2",
	"gpescap1",
	"gpexit1",
	"gpexit2",
	"gpgmn1",
	"gpgmn1a",
	"gpgmn2",
	"gpgmn3",
	"gppark1",
	"gproof1",
	"gproof2",
	"gwbrook1",
	"gwenter1",
	"gwgrass1",
	"gwpool1",
	"gwpool2",
	"gwroad1",
	"rgair1",
	"rgair2",
	"rgair3",
	"rgcock1",
	"rgcock2",
	"rgcock3",
	"rgexit1",
	"rgexit2",
	"rgguest1",
	"rgguest2",
	"rgguest3",
	"rgguest4",
	"rgguest5",
	"rghang1",
	"rghang11",
	"rghang2",
	"rghatch1",
	"rgroad1",
	"rgroad11",
	"rgroad2",
	"rgroad21",
	"rgroad3",
	"rgroad31",
	"sdcore1",
	"sdcore2",
	"sdisle1",
	"seback1",
	"seback2",
	"secont1",
	"secont2",
	"sefront1",
	"sefront2",
	"sefront3",
	"sefront4",
	"seroom1",
	"seroom2",
	"ssadel1",
	"ssadel2",
	"ssblock1",
	"sscont1",
	"sscont2",
	"ssdock1",
	"sselone1",
	"sslock1",
	"ssmedi1",
	"ssmedi2",
	"sspack1",
	"sspod1",
	"sspod2",
	"sspod3",
	"ssroad1",
	"ssroad2",
	"ssroad3",
	"ssspace1",
	"ssspace2",
	"ssspace3",
	"tgcourt1",
	"tgcourt5",
	"tgcourt2",
	"tgcourt3",
	"tgcourt4",
	"tgfront1",
	"tggara1",
	"tggate1",
	"tggrave1",
	"tgroom1",
	"tgroom2",
	"tgstage1",
	"tgview1",
	"tiagit1",
	"tiagit2",
	"tiagit3",
	"tiagit4",
	"tiagit5",
	"tiback1",
	"tiback2",
	"tigate1",
	"tihtl1",
	"tihtr1",
	"tilink1",
	"tilink2",
	"timania1",
	"timania2",
	"timania3",
	"timania4",
	"timania5",
	"timin1",
	"timin21",
	"timin22",
	"tipub1",
	"tistud1",
	"tistud21",
	"tistud22",
	"titown1",
	"titown2",
	"titown3",
	"titown4",
	"titown51",
	"titown52",
	"titown6",
	"titown7",
	"titown8",
	"titrain1",
	"titv1",
	"titvout1",
	"tivisi1",
	"tivisi2",
	"tiyane1",
	"tiyane2",
	"tiyane3",
	"tmdome1",
	"tmdome2",
	"tmelder1",
	"tmele1",
	"tmgate1",
	"tmhtl1",
	"tmhtr1",
	"tmkobo1",
	"tmkobo2",
	"tmmin1",
	"tmmura1",
	"tmmura2",
	"tmsand1",
	"tvglen1",
	"tvglen2",
	"tvglen3",
	"tvglen4",
	"tvglen5",
	"laguna01",
	"laguna02",
	"laguna03",
	"laguna04",
	"laguna05",
	"laguna06",
	"laguna07",
	"laguna08",
	"laguna09",
	"laguna10",
	"laguna11",
	"laguna12",
	"laguna13",
	"laguna14",
	"gpbigin6",
	"fhtown24",
	"rgcock4",
	"rgcock5",
	"ffhole1a",
	"ehblan1a",
	"ehenter3",
	"ehroom1a",
	"eproad1a",
	"fewhite1",
	"feblack1",
	"glwitch3",
	"ehback1a",
	"ehblan1b",
	"ehenter4",
	"ehroom1b",
	"ehsea1a"
};

const char *Data::musicList[100] =
{
    "none", "nothing", "oa", "ob", "dun2", "guitar2", "fanfare", "makoro", "bat",
    "fiddle", "kurai", "chu", "ketc", "earis", "ta", "tb", "sato",
    "parade", "comical", "yume", "mati", "sido", "siera", "walz", "corneo",
    "horror", "canyon", "red", "seto", "ayasi", "sinra", "sinraslo", "dokubo",
    "bokujo", "tm", "tifa", "costa", "rocket", "earislo", "chase", "rukei",
    "cephiros", "barret", "corel", "boo", "elec", "rhythm", "fan2", "hiku",
    "cannon", "date", "cintro", "cinco", "chu2", "yufi", "aseri", "gold1",
    "mura1", "yado", "over2", "crwin", "crlost", "odds", "geki", "junon",
    "tender", "wind", "vincent", "bee", "jukai", "sadbar", "aseri2", "kita",
    "sid2", "sadsid", "iseki", "hen", "utai", "snow", "yufi2", "mekyu",
    "condor", "lb2", "gun", "weapon", "pj", "sea", "ld", "lb1",
    "sensui", "ro", "jyro", "nointro", "riku", "si", "mogu", "pre",
    "fin", "heart", "roll"
};

const char *Data::musicList2[100] =
{
    "none", "nothing", "Opening - Bombing Mission", "Bombing Mission",
    "Chasing The Black-Caped Man", "On The Other Side Of The Mountain",
    "Fanfare (intro)", "Mako Reactor", "Fighting", "Fiddle De Chocobo",
    "Anxious Heart", "Still More Fighting", "Cait Sith's Theme", "Aerith's Theme",
    "Final Fantasy VII Main Theme", "Final Fantasy VII Main Theme B", "sato",
    "Rufus' Welcoming Ceremony", "comical", "Who Are You", "Ahead on Our Way",
    "It's Difficult to Stand on Both Feet, Isn't It", "If You Open Your Heart",
    "Waltz de Chocobo", "Don of the Slums", "Trail Of Blood", "Cosmo Canyon",
    "Red XIII's Theme", "Great Warrior", "Lurking in the Darkness",
    "Shinra Company", "Infiltrating Shinra Tower", "Underneath the Rotting Pizza",
    "Farm Boy", "On That Day, Five Years Ago", "Tifa's Theme", "Costa Del Sol",
    "Oppressed People", "Flowers Blooming in the Church", "Crazy Motorcycle",
    "Sandy Badlands", "Those Chosen by the Planet", "Barret's Theme", "Mining Town",
    "Life Stream", "Electric de Chocobo", "Turk's Theme", "Fanfare",
    "Highwind Takes To The Skies", "The Makou Cannon Is Fired ~ Shinra Explodes A",
    "Interrupted By Fireworks", "Those Chosen By The Planet (Intro)", "Cinco de Chocobo",
    "J-E-N-O-V-A", "Descendant Of Shinobi", "Hurry!", "Gold Saucer",
    "Parochial Town", "Good Night, Until Tomorrow", "Continue", "A Great Success",
    "Tango Of Tears", "Racing Chocobo ~ Place Your Bets", "Debut",
    "Off The Edge Of Despair", "Holding My Thoughts In My Heart", "wind",
    "The Nightmare's Beginning", "Honeybee Manor", "Forest Temple",
    "Mark of the Traitor", "Hurry Faster!", "The Great Northern Cave",
    "Cid's Theme", "Sending a Dream Into the Universe", "You Can Hear the Cry of the Planet",
    "Who Am I", "Utai", "Buried in the Snow", "Stolen Materia", "Reunion",
    "Fortress Of The Condor", "One-Winged Angel", "Shinra Army Wages A Full-Scale Attack",
    "Weapon Raid", "Jenova Absolute", "A Secret, Sleeping in the Deep Sea",
    "Judgment Day", "The Birth of God", "sensui", "The Countdown Begins",
    "Steal The Tiny Bronco!", "Those Chosen By The Planet (no intro)",
    "The Makou Cannon Is Fired ~ Shinra Explodes B",
    "The Makou Cannon Is Fired ~ Shinra Explodes C", "Highwind Takes to the Skies",
    "The Prelude", "World Crisis", "heart", "Staff Roll"
};
