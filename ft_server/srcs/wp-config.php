<?php
/**
* The base configuration for WordPress
*
* The wp-config.php creation script uses this file during the
* installation. You don't have to use the web site, you can
* copy this file to "wp-config.php" and fill in the values.
*
* This file contains the following configurations:
*
* * MySQL settings
* * Secret keys
* * Database table prefix
* * ABSPATH
*
* @link https://wordpress.org/support/article/editing-wp-conf..
*
* @package WordPress
*/

// ** MySQL settings - You can get this info from your web host ** //
/** The name of the database for WordPress */
define( 'DB_NAME', 'ft_database' );

/** MySQL database username */
define( 'DB_USER', 'tredtusk' );

/** MySQL database password */
define( 'DB_PASSWORD', 'tredtusk42' );

/** MySQL hostname */
define( 'DB_HOST', 'localhost' );

/** Database Charset to use in creating database tables. */
define( 'DB_CHARSET', 'utf8' );

/** The Database Collate type. Don't change this if in doubt. */
define( 'DB_COLLATE', '' );

/**#@+
* Authentication Unique Keys and Salts.
*
* Change these to different unique phrases!
* You can generate these using the {@link https://api.wordpress.org/secret-key/1.1/salt/ WordPress.org secret-key service}
* You can change these at any point in time to invalidate all existing cookies. This will force all users to have to log in again.
*
* @since 2.6.0
*/

define('AUTH_KEY',         '6u3oteYH3BnPQVnDwO&-V|g(Sh]Va8FA^|&<p] `Q [^=*c/u/z&[-C>L0,-{|-+');
define('SECURE_AUTH_KEY',  '?{&Se|B<uy+m1}=-ok;;;b_l8@E^UaqH@/%V+^-k##Jw2s$GD~W}>Jj+b@>L:|hJ');
define('LOGGED_IN_KEY',    'p^;f>w6-9cYN5[~,d/!%0!a4CIP{SD/v!6_NL}j]r||us?jb`o7SWrHg0L6Hu<GL');
define('NONCE_KEY',        'Q|U;*lr-VF_jsk>(h`L|.|SF4>WZN_*4j&-RFm-7>9kK{tCG/uu_-2 GUJ-j}c;%');
define('AUTH_SALT',        'k(.udkxo?8p1p!MV!PameDx|x=hMX-,vK,,DR @1a[v^&FHiYb2`?]tC.l_od}i;');
define('SECURE_AUTH_SALT', 'G#8AGq 4]<$P)tOiu?.W);C{|ec[;6YJ=%m`I[:|+hEcz7+O&p;.wxw0$A~R[;wk');
define('LOGGED_IN_SALT',   'b. 4b-SM,|x.fIa2(lp-fl  *|1kl]=3Pz{C#Jq*kI>5@iKpB9QPm{c&6sz|I`o)');
define('NONCE_SALT',       '<q?SVcgOx=Fv<+c::r31}.x/1%/q]|CuN~C14DH&eb4O)>6Q~u51xH6l|U|(MotT');

/**#@-*/

/**
* WordPress Database Table prefix.
*
* You can have multiple installations in one database if you give each
* a unique prefix. Only numbers, letters, and underscores please!
*/
$table_prefix = 'wp_';

/**
* For developers: WordPress debugging mode.
*
* Change this to true to enable the display of notices during development.
* It is strongly recommended that plugin and theme developers use WP_DEBUG
* in their development environments.
*
* For information on other constants that can be used for debugging,
* visit the documentation.
*
* @link https://wordpress.org/support/article/debugging-in-wo..
*/
define( 'WP_DEBUG', false );

/* That's all, stop editing! Happy publishing. */

/** Absolute path to the WordPress directory. */
if ( ! defined( 'ABSPATH' ) ) {
define( 'ABSPATH', __DIR__ . '/' );
}

/** Sets up WordPress vars and included files. */
require_once ABSPATH . 'wp-settings.php';
