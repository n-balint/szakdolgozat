#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#ifdef _MSC_VER
#pragma optimize("", off)
#elif defined(__clang__)
#pragma clang optimize off
#elif defined(__GNUC__)
#pragma GCC optimize ("O0")
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 961
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 316
#define ALIAS_COUNT 30
#define TOKEN_COUNT 147
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 19
#define PRODUCTION_ID_COUNT 67

enum ts_symbol_identifiers {
  anon_sym_SEMI = 1,
  aux_sym_select_statement_token1 = 2,
  aux_sym_select_statement_token2 = 3,
  aux_sym_select_statement_token3 = 4,
  aux_sym_select_statement_token4 = 5,
  aux_sym_select_statement_token5 = 6,
  aux_sym_limit_spec_token1 = 7,
  anon_sym_STAR = 8,
  anon_sym_COMMA = 9,
  aux_sym_select_element_token1 = 10,
  anon_sym_LPAREN = 11,
  anon_sym_RPAREN = 12,
  aux_sym_constant_token1 = 13,
  aux_sym_constant_token2 = 14,
  aux_sym_constant_token3 = 15,
  anon_sym_QMARK = 16,
  anon_sym_COLON = 17,
  sym__string_literal = 18,
  aux_sym__decimal_literal_token1 = 19,
  sym__float_literal = 20,
  sym__boolean_literal = 21,
  sym__code_block = 22,
  aux_sym_from_spec_token1 = 23,
  aux_sym_where_spec_token1 = 24,
  aux_sym_relation_elements_token1 = 25,
  anon_sym_LT = 26,
  anon_sym_LT_EQ = 27,
  anon_sym_LT_GT = 28,
  anon_sym_EQ = 29,
  anon_sym_GT = 30,
  anon_sym_GT_EQ = 31,
  aux_sym_relation_element_token1 = 32,
  aux_sym_relation_contains_key_token1 = 33,
  aux_sym_relation_contains_key_token2 = 34,
  aux_sym_order_spec_token1 = 35,
  aux_sym_order_spec_token2 = 36,
  aux_sym_order_spec_token3 = 37,
  aux_sym_order_spec_token4 = 38,
  aux_sym_delete_statement_token1 = 39,
  aux_sym_delete_statement_token2 = 40,
  aux_sym_delete_statement_token3 = 41,
  aux_sym_begin_batch_token1 = 42,
  aux_sym_begin_batch_token2 = 43,
  aux_sym_begin_batch_token3 = 44,
  aux_sym_begin_batch_token4 = 45,
  aux_sym_begin_batch_token5 = 46,
  anon_sym_LBRACK = 47,
  anon_sym_RBRACK = 48,
  aux_sym_using_timestamp_spec_token1 = 49,
  aux_sym_using_timestamp_spec_token2 = 50,
  aux_sym_insert_statement_token1 = 51,
  aux_sym_insert_statement_token2 = 52,
  aux_sym_insert_statement_token3 = 53,
  aux_sym_insert_values_spec_token1 = 54,
  anon_sym_LBRACE = 55,
  anon_sym_RBRACE = 56,
  aux_sym_using_ttl_timestamp_token1 = 57,
  aux_sym_truncate_token1 = 58,
  aux_sym_truncate_token2 = 59,
  aux_sym_create_index_token1 = 60,
  aux_sym_create_index_token2 = 61,
  aux_sym_create_index_token3 = 62,
  aux_sym_index_keys_spec_token1 = 63,
  aux_sym_index_entries_s_spec_token1 = 64,
  aux_sym_index_full_spec_token1 = 65,
  aux_sym_drop_index_token1 = 66,
  aux_sym_update_token1 = 67,
  aux_sym_update_assignments_token1 = 68,
  anon_sym_PLUS = 69,
  anon_sym_DASH = 70,
  aux_sym_use_token1 = 71,
  aux_sym_grant_token1 = 72,
  aux_sym_grant_token2 = 73,
  aux_sym_revoke_token1 = 74,
  aux_sym_privilege_token1 = 75,
  aux_sym_privilege_token2 = 76,
  aux_sym_privilege_token3 = 77,
  aux_sym_privilege_token4 = 78,
  aux_sym_privilege_token5 = 79,
  aux_sym_privilege_token6 = 80,
  aux_sym_privilege_token7 = 81,
  aux_sym_resource_token1 = 82,
  aux_sym_resource_token2 = 83,
  aux_sym_resource_token3 = 84,
  aux_sym_resource_token4 = 85,
  aux_sym_resource_token5 = 86,
  anon_sym_DOT = 87,
  aux_sym_resource_token6 = 88,
  aux_sym_list_roles_token1 = 89,
  aux_sym_list_roles_token2 = 90,
  aux_sym_list_roles_token3 = 91,
  aux_sym_drop_aggregate_token1 = 92,
  aux_sym_drop_materialized_view_token1 = 93,
  aux_sym_drop_materialized_view_token2 = 94,
  aux_sym_drop_trigger_token1 = 95,
  aux_sym_drop_type_token1 = 96,
  aux_sym_drop_user_token1 = 97,
  aux_sym_create_aggregate_token1 = 98,
  aux_sym_create_aggregate_token2 = 99,
  aux_sym_create_aggregate_token3 = 100,
  aux_sym_create_aggregate_token4 = 101,
  aux_sym_create_aggregate_token5 = 102,
  aux_sym_create_aggregate_token6 = 103,
  aux_sym_column_not_null_token1 = 104,
  aux_sym_create_function_token1 = 105,
  aux_sym_create_function_token2 = 106,
  aux_sym_native_type_token1 = 107,
  aux_sym_native_type_token2 = 108,
  aux_sym_native_type_token3 = 109,
  aux_sym_native_type_token4 = 110,
  aux_sym_native_type_token5 = 111,
  aux_sym_native_type_token6 = 112,
  aux_sym_native_type_token7 = 113,
  aux_sym_native_type_token8 = 114,
  aux_sym_native_type_token9 = 115,
  aux_sym_native_type_token10 = 116,
  aux_sym_native_type_token11 = 117,
  aux_sym_native_type_token12 = 118,
  aux_sym_native_type_token13 = 119,
  aux_sym_native_type_token14 = 120,
  aux_sym_native_type_token15 = 121,
  aux_sym_native_type_token16 = 122,
  aux_sym_native_type_token17 = 123,
  aux_sym_native_type_token18 = 124,
  aux_sym_native_type_token19 = 125,
  aux_sym_collection_type_token1 = 126,
  aux_sym_tuple_type_token1 = 127,
  aux_sym_frozen_type_token1 = 128,
  aux_sym_return_mode_token1 = 129,
  aux_sym_return_mode_token2 = 130,
  aux_sym_create_keyspace_token1 = 131,
  aux_sym_create_keyspace_token2 = 132,
  aux_sym_durable_writes_token1 = 133,
  aux_sym_role_with_option_token1 = 134,
  aux_sym_role_with_option_token2 = 135,
  aux_sym_role_with_option_token3 = 136,
  aux_sym_role_with_option_token4 = 137,
  aux_sym_primary_key_column_token1 = 138,
  aux_sym_compact_storage_token1 = 139,
  aux_sym_compact_storage_token2 = 140,
  aux_sym_clustering_order_token1 = 141,
  aux_sym_user_super_user_token1 = 142,
  aux_sym_alter_table_add_token1 = 143,
  aux_sym_alter_table_rename_token1 = 144,
  aux_sym_apply_batch_token1 = 145,
  sym_object_name = 146,
  sym_source_file = 147,
  sym__statement = 148,
  sym_select_statement = 149,
  sym_limit_spec = 150,
  sym_select_elements = 151,
  sym_select_element = 152,
  sym_function_call = 153,
  sym_function_args = 154,
  sym_constant = 155,
  sym_bind_marker = 156,
  sym__value_marker = 157,
  sym__decimal_literal = 158,
  sym_from_spec = 159,
  sym_where_spec = 160,
  sym_relation_elements = 161,
  sym_relation_element = 162,
  sym_relation_contains_key = 163,
  sym_relation_contains = 164,
  sym_order_spec = 165,
  sym_delete_statement = 166,
  sym_begin_batch = 167,
  sym_delete_column_list = 168,
  sym_delete_column_item = 169,
  sym_using_timestamp_spec = 170,
  sym_if_spec = 171,
  sym_insert_statement = 172,
  sym_insert_column_spec = 173,
  sym_column_list = 174,
  sym_insert_values_spec = 175,
  sym_expression_list = 176,
  sym_expression = 177,
  sym_assignment_map = 178,
  sym_assignment_set = 179,
  sym_assignment_list = 180,
  sym_assignment_tuple = 181,
  sym_using_ttl_timestamp = 182,
  sym_truncate = 183,
  sym_create_index = 184,
  sym_index_column_spec = 185,
  sym_index_keys_spec = 186,
  sym_index_entries_s_spec = 187,
  sym_index_full_spec = 188,
  sym_drop_index = 189,
  sym_update = 190,
  sym_update_assignments = 191,
  sym_assignment_element = 192,
  sym_indexed_column = 193,
  sym_use = 194,
  sym_grant = 195,
  sym_revoke = 196,
  sym_privilege = 197,
  sym_resource = 198,
  sym_list_roles = 199,
  sym_list_permissions = 200,
  sym_drop_aggregate = 201,
  sym_drop_materialized_view = 202,
  sym_drop_function = 203,
  sym_drop_keyspace = 204,
  sym_drop_role = 205,
  sym_drop_table = 206,
  sym_drop_trigger = 207,
  sym_drop_type = 208,
  sym_drop_user = 209,
  sym_create_aggregate = 210,
  sym_init_cond_definition = 211,
  sym_init_cond_list = 212,
  sym_init_cond_nested_list = 213,
  sym_init_cond_hash = 214,
  sym_init_cond_hash_item = 215,
  sym_create_materialized_view = 216,
  sym_materialized_view_where = 217,
  sym_column_not_null = 218,
  sym_create_function = 219,
  sym_data_type = 220,
  sym_cql_type = 221,
  sym_user_defined_type = 222,
  sym_udt_name = 223,
  sym_native_type = 224,
  sym_collection_type = 225,
  sym_tuple_type = 226,
  sym_frozen_type = 227,
  sym_return_mode = 228,
  sym_create_keyspace = 229,
  sym_replication_list_item = 230,
  sym_durable_writes = 231,
  sym_create_role = 232,
  sym_role_with = 233,
  sym_role_with_option = 234,
  sym_option_hash = 235,
  sym_option_hash_item = 236,
  sym_create_table = 237,
  sym_column_definition_list = 238,
  sym_column_definition = 239,
  sym_primary_key_column = 240,
  sym_primary_key_element = 241,
  sym_primary_key_definition = 242,
  sym_compound_key = 243,
  sym_clustering_key_list = 244,
  sym_composite_key = 245,
  sym_partition_key_list = 246,
  sym_with_element = 247,
  sym_table_options = 248,
  sym_table_option_item = 249,
  sym_table_option_name = 250,
  sym_table_option_value = 251,
  sym_compact_storage = 252,
  sym_clustering_order = 253,
  sym_create_trigger = 254,
  sym_trigger_class = 255,
  sym_create_type = 256,
  sym_typed_name = 257,
  sym_create_user = 258,
  sym_user_with = 259,
  sym_user_password = 260,
  sym_user_super_user = 261,
  sym_alter_materialized_view = 262,
  sym_alter_keyspace = 263,
  sym_replication_list = 264,
  sym_alter_role = 265,
  sym_alter_table = 266,
  sym_alter_table_operation = 267,
  sym_alter_table_add = 268,
  sym_alter_table_drop_columns = 269,
  sym_alter_table_drop_compact_storage = 270,
  sym_alter_table_rename = 271,
  sym_alter_type = 272,
  sym_alter_type_operation = 273,
  sym_alter_type_alter_type = 274,
  sym_alter_type_add = 275,
  sym_alter_type_rename = 276,
  sym_alter_type_rename_item = 277,
  sym_alter_user = 278,
  sym_apply_batch = 279,
  sym_aggregate_name = 280,
  sym_function_name = 281,
  sym_short_index_name = 282,
  sym_index_name = 283,
  sym_keyspace_name = 284,
  sym_materialized_view_name = 285,
  sym_role_name = 286,
  sym_table_name = 287,
  sym_trigger_name = 288,
  sym_type_name = 289,
  sym_user_name = 290,
  aux_sym_source_file_repeat1 = 291,
  aux_sym_select_elements_repeat1 = 292,
  aux_sym_function_args_repeat1 = 293,
  aux_sym_relation_elements_repeat1 = 294,
  aux_sym_relation_element_repeat1 = 295,
  aux_sym_relation_element_repeat2 = 296,
  aux_sym_delete_column_list_repeat1 = 297,
  aux_sym_expression_list_repeat1 = 298,
  aux_sym_assignment_map_repeat1 = 299,
  aux_sym_assignment_set_repeat1 = 300,
  aux_sym_update_assignments_repeat1 = 301,
  aux_sym_init_cond_list_repeat1 = 302,
  aux_sym_init_cond_nested_list_repeat1 = 303,
  aux_sym_init_cond_hash_repeat1 = 304,
  aux_sym_materialized_view_where_repeat1 = 305,
  aux_sym_create_function_repeat1 = 306,
  aux_sym_tuple_type_repeat1 = 307,
  aux_sym_role_with_repeat1 = 308,
  aux_sym_option_hash_repeat1 = 309,
  aux_sym_column_definition_list_repeat1 = 310,
  aux_sym_clustering_key_list_repeat1 = 311,
  aux_sym_table_options_repeat1 = 312,
  aux_sym_clustering_order_repeat1 = 313,
  aux_sym_replication_list_repeat1 = 314,
  aux_sym_alter_type_rename_repeat1 = 315,
  anon_alias_sym_aggregate = 316,
  anon_alias_sym_alias = 317,
  anon_alias_sym_assignment_operand = 318,
  anon_alias_sym_code_block = 319,
  anon_alias_sym_column = 320,
  anon_alias_sym_entry = 321,
  anon_alias_sym_finalfunc = 322,
  anon_alias_sym_full = 323,
  anon_alias_sym_function = 324,
  anon_alias_sym_function_name = 325,
  anon_alias_sym_hash_key = 326,
  anon_alias_sym_index = 327,
  anon_alias_sym_key = 328,
  anon_alias_sym_keyspace = 329,
  anon_alias_sym_language = 330,
  anon_alias_sym_limit_value = 331,
  anon_alias_sym_login = 332,
  anon_alias_sym_materialized_view = 333,
  anon_alias_sym_partition_key = 334,
  anon_alias_sym_password = 335,
  anon_alias_sym_primary_key = 336,
  anon_alias_sym_role = 337,
  anon_alias_sym_sfunc = 338,
  anon_alias_sym_table = 339,
  anon_alias_sym_time = 340,
  anon_alias_sym_trigger = 341,
  anon_alias_sym_ttl = 342,
  anon_alias_sym_type = 343,
  anon_alias_sym_user = 344,
  anon_alias_sym_value = 345,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [anon_sym_SEMI] = ";",
  [aux_sym_select_statement_token1] = "SELECT",
  [aux_sym_select_statement_token2] = "DISTINCT",
  [aux_sym_select_statement_token3] = "JSON",
  [aux_sym_select_statement_token4] = "ALLOW",
  [aux_sym_select_statement_token5] = "FILTERING",
  [aux_sym_limit_spec_token1] = "LIMIT",
  [anon_sym_STAR] = "*",
  [anon_sym_COMMA] = ",",
  [aux_sym_select_element_token1] = "AS",
  [anon_sym_LPAREN] = "(",
  [anon_sym_RPAREN] = ")",
  [aux_sym_constant_token1] = "constant_token1",
  [aux_sym_constant_token2] = "NULL",
  [aux_sym_constant_token3] = "constant_token3",
  [anon_sym_QMARK] = "\?",
  [anon_sym_COLON] = ":",
  [sym__string_literal] = "_string_literal",
  [aux_sym__decimal_literal_token1] = "_decimal_literal_token1",
  [sym__float_literal] = "_float_literal",
  [sym__boolean_literal] = "_boolean_literal",
  [sym__code_block] = "_code_block",
  [aux_sym_from_spec_token1] = "FROM",
  [aux_sym_where_spec_token1] = "WHERE",
  [aux_sym_relation_elements_token1] = "AND",
  [anon_sym_LT] = "<",
  [anon_sym_LT_EQ] = "<=",
  [anon_sym_LT_GT] = "<>",
  [anon_sym_EQ] = "=",
  [anon_sym_GT] = ">",
  [anon_sym_GT_EQ] = ">=",
  [aux_sym_relation_element_token1] = "IN",
  [aux_sym_relation_contains_key_token1] = "CONTAINS",
  [aux_sym_relation_contains_key_token2] = "KEY",
  [aux_sym_order_spec_token1] = "ORDER",
  [aux_sym_order_spec_token2] = "BY",
  [aux_sym_order_spec_token3] = "ASC",
  [aux_sym_order_spec_token4] = "DESC",
  [aux_sym_delete_statement_token1] = "DELETE",
  [aux_sym_delete_statement_token2] = "IF",
  [aux_sym_delete_statement_token3] = "EXISTS",
  [aux_sym_begin_batch_token1] = "BEGIN",
  [aux_sym_begin_batch_token2] = "LOGGED",
  [aux_sym_begin_batch_token3] = "UNLOGGED",
  [aux_sym_begin_batch_token4] = "COUNTER",
  [aux_sym_begin_batch_token5] = "BATCH",
  [anon_sym_LBRACK] = "[",
  [anon_sym_RBRACK] = "]",
  [aux_sym_using_timestamp_spec_token1] = "USING",
  [aux_sym_using_timestamp_spec_token2] = "TIMESTAMP",
  [aux_sym_insert_statement_token1] = "INSERT",
  [aux_sym_insert_statement_token2] = "INTO",
  [aux_sym_insert_statement_token3] = "NOT",
  [aux_sym_insert_values_spec_token1] = "VALUES",
  [anon_sym_LBRACE] = "{",
  [anon_sym_RBRACE] = "}",
  [aux_sym_using_ttl_timestamp_token1] = "TTL",
  [aux_sym_truncate_token1] = "TRUNCATE",
  [aux_sym_truncate_token2] = "TABLE",
  [aux_sym_create_index_token1] = "CREATE",
  [aux_sym_create_index_token2] = "INDEX",
  [aux_sym_create_index_token3] = "ON",
  [aux_sym_index_keys_spec_token1] = "KEYS",
  [aux_sym_index_entries_s_spec_token1] = "ENTRIES",
  [aux_sym_index_full_spec_token1] = "FULL",
  [aux_sym_drop_index_token1] = "DROP",
  [aux_sym_update_token1] = "UPDATE",
  [aux_sym_update_assignments_token1] = "SET",
  [anon_sym_PLUS] = "+",
  [anon_sym_DASH] = "-",
  [aux_sym_use_token1] = "USE",
  [aux_sym_grant_token1] = "GRANT",
  [aux_sym_grant_token2] = "TO",
  [aux_sym_revoke_token1] = "REVOKE",
  [aux_sym_privilege_token1] = "ALL",
  [aux_sym_privilege_token2] = "PERMISSIONS",
  [aux_sym_privilege_token3] = "ALTER",
  [aux_sym_privilege_token4] = "AUTHORIZE",
  [aux_sym_privilege_token5] = "DESCRIBE",
  [aux_sym_privilege_token6] = "EXECUTE",
  [aux_sym_privilege_token7] = "MODIFY",
  [aux_sym_resource_token1] = "FUNCTIONS",
  [aux_sym_resource_token2] = "KEYSPACE",
  [aux_sym_resource_token3] = "KEYSPACES",
  [aux_sym_resource_token4] = "ROLES",
  [aux_sym_resource_token5] = "FUNCTION",
  [anon_sym_DOT] = ".",
  [aux_sym_resource_token6] = "ROLE",
  [aux_sym_list_roles_token1] = "LIST",
  [aux_sym_list_roles_token2] = "OF",
  [aux_sym_list_roles_token3] = "NORECURSIVE",
  [aux_sym_drop_aggregate_token1] = "AGGREGATE",
  [aux_sym_drop_materialized_view_token1] = "MATERIALIZED",
  [aux_sym_drop_materialized_view_token2] = "VIEW",
  [aux_sym_drop_trigger_token1] = "TRIGGER",
  [aux_sym_drop_type_token1] = "TYPE",
  [aux_sym_drop_user_token1] = "USER",
  [aux_sym_create_aggregate_token1] = "OR",
  [aux_sym_create_aggregate_token2] = "REPLACE",
  [aux_sym_create_aggregate_token3] = "SFUNC",
  [aux_sym_create_aggregate_token4] = "STYPE",
  [aux_sym_create_aggregate_token5] = "FINALFUNC",
  [aux_sym_create_aggregate_token6] = "INITCOND",
  [aux_sym_column_not_null_token1] = "IS",
  [aux_sym_create_function_token1] = "RETURNS",
  [aux_sym_create_function_token2] = "LANGUAGE",
  [aux_sym_native_type_token1] = "ASCII",
  [aux_sym_native_type_token2] = "BIGINT",
  [aux_sym_native_type_token3] = "BLOB",
  [aux_sym_native_type_token4] = "BOOLEAN",
  [aux_sym_native_type_token5] = "DATE",
  [aux_sym_native_type_token6] = "DECIMAL",
  [aux_sym_native_type_token7] = "DOUBLE",
  [aux_sym_native_type_token8] = "DURATION",
  [aux_sym_native_type_token9] = "FLOAT",
  [aux_sym_native_type_token10] = "INET",
  [aux_sym_native_type_token11] = "INT",
  [aux_sym_native_type_token12] = "SMALLINT",
  [aux_sym_native_type_token13] = "TEXT",
  [aux_sym_native_type_token14] = "TIME",
  [aux_sym_native_type_token15] = "TIMEUUID",
  [aux_sym_native_type_token16] = "TINYINT",
  [aux_sym_native_type_token17] = "UUID",
  [aux_sym_native_type_token18] = "VARCHAR",
  [aux_sym_native_type_token19] = "VARINT",
  [aux_sym_collection_type_token1] = "MAP",
  [aux_sym_tuple_type_token1] = "TUPLE",
  [aux_sym_frozen_type_token1] = "FROZEN",
  [aux_sym_return_mode_token1] = "CALLED",
  [aux_sym_return_mode_token2] = "INPUT",
  [aux_sym_create_keyspace_token1] = "WITH",
  [aux_sym_create_keyspace_token2] = "REPLICATION",
  [aux_sym_durable_writes_token1] = "DURABLE_WRITES",
  [aux_sym_role_with_option_token1] = "PASSWORD",
  [aux_sym_role_with_option_token2] = "LOGIN",
  [aux_sym_role_with_option_token3] = "SUPERUSER",
  [aux_sym_role_with_option_token4] = "OPTIONS",
  [aux_sym_primary_key_column_token1] = "PRIMARY",
  [aux_sym_compact_storage_token1] = "COMPACT",
  [aux_sym_compact_storage_token2] = "STORAGE",
  [aux_sym_clustering_order_token1] = "CLUSTERING",
  [aux_sym_user_super_user_token1] = "NOSUPERUSER",
  [aux_sym_alter_table_add_token1] = "ADD",
  [aux_sym_alter_table_rename_token1] = "RENAME",
  [aux_sym_apply_batch_token1] = "APPLY",
  [sym_object_name] = "object_name",
  [sym_source_file] = "source_file",
  [sym__statement] = "_statement",
  [sym_select_statement] = "select_statement",
  [sym_limit_spec] = "limit_spec",
  [sym_select_elements] = "select_elements",
  [sym_select_element] = "select_element",
  [sym_function_call] = "function_call",
  [sym_function_args] = "function_args",
  [sym_constant] = "constant",
  [sym_bind_marker] = "bind_marker",
  [sym__value_marker] = "_value_marker",
  [sym__decimal_literal] = "_decimal_literal",
  [sym_from_spec] = "from_spec",
  [sym_where_spec] = "where_spec",
  [sym_relation_elements] = "relation_elements",
  [sym_relation_element] = "relation_element",
  [sym_relation_contains_key] = "relation_contains_key",
  [sym_relation_contains] = "relation_contains",
  [sym_order_spec] = "order_spec",
  [sym_delete_statement] = "delete_statement",
  [sym_begin_batch] = "begin_batch",
  [sym_delete_column_list] = "delete_column_list",
  [sym_delete_column_item] = "delete_column_item",
  [sym_using_timestamp_spec] = "using_timestamp_spec",
  [sym_if_spec] = "if_spec",
  [sym_insert_statement] = "insert_statement",
  [sym_insert_column_spec] = "insert_column_spec",
  [sym_column_list] = "column_list",
  [sym_insert_values_spec] = "insert_values_spec",
  [sym_expression_list] = "expression_list",
  [sym_expression] = "expression",
  [sym_assignment_map] = "assignment_map",
  [sym_assignment_set] = "assignment_set",
  [sym_assignment_list] = "assignment_list",
  [sym_assignment_tuple] = "assignment_tuple",
  [sym_using_ttl_timestamp] = "using_ttl_timestamp",
  [sym_truncate] = "truncate",
  [sym_create_index] = "create_index",
  [sym_index_column_spec] = "index_column_spec",
  [sym_index_keys_spec] = "index_keys_spec",
  [sym_index_entries_s_spec] = "index_entries_s_spec",
  [sym_index_full_spec] = "index_full_spec",
  [sym_drop_index] = "drop_index",
  [sym_update] = "update",
  [sym_update_assignments] = "update_assignments",
  [sym_assignment_element] = "assignment_element",
  [sym_indexed_column] = "indexed_column",
  [sym_use] = "use",
  [sym_grant] = "grant",
  [sym_revoke] = "revoke",
  [sym_privilege] = "privilege",
  [sym_resource] = "resource",
  [sym_list_roles] = "list_roles",
  [sym_list_permissions] = "list_permissions",
  [sym_drop_aggregate] = "drop_aggregate",
  [sym_drop_materialized_view] = "drop_materialized_view",
  [sym_drop_function] = "drop_function",
  [sym_drop_keyspace] = "drop_keyspace",
  [sym_drop_role] = "drop_role",
  [sym_drop_table] = "drop_table",
  [sym_drop_trigger] = "drop_trigger",
  [sym_drop_type] = "drop_type",
  [sym_drop_user] = "drop_user",
  [sym_create_aggregate] = "create_aggregate",
  [sym_init_cond_definition] = "init_cond_definition",
  [sym_init_cond_list] = "init_cond_list",
  [sym_init_cond_nested_list] = "init_cond_nested_list",
  [sym_init_cond_hash] = "init_cond_hash",
  [sym_init_cond_hash_item] = "init_cond_hash_item",
  [sym_create_materialized_view] = "create_materialized_view",
  [sym_materialized_view_where] = "materialized_view_where",
  [sym_column_not_null] = "column_not_null",
  [sym_create_function] = "create_function",
  [sym_data_type] = "data_type",
  [sym_cql_type] = "cql_type",
  [sym_user_defined_type] = "user_defined_type",
  [sym_udt_name] = "udt_name",
  [sym_native_type] = "native_type",
  [sym_collection_type] = "collection_type",
  [sym_tuple_type] = "tuple_type",
  [sym_frozen_type] = "frozen_type",
  [sym_return_mode] = "return_mode",
  [sym_create_keyspace] = "create_keyspace",
  [sym_replication_list_item] = "replication_list_item",
  [sym_durable_writes] = "durable_writes",
  [sym_create_role] = "create_role",
  [sym_role_with] = "role_with",
  [sym_role_with_option] = "role_with_option",
  [sym_option_hash] = "option_hash",
  [sym_option_hash_item] = "option_hash_item",
  [sym_create_table] = "create_table",
  [sym_column_definition_list] = "column_definition_list",
  [sym_column_definition] = "column_definition",
  [sym_primary_key_column] = "primary_key_column",
  [sym_primary_key_element] = "primary_key_element",
  [sym_primary_key_definition] = "primary_key_definition",
  [sym_compound_key] = "compound_key",
  [sym_clustering_key_list] = "clustering_key_list",
  [sym_composite_key] = "composite_key",
  [sym_partition_key_list] = "partition_key_list",
  [sym_with_element] = "with_element",
  [sym_table_options] = "table_options",
  [sym_table_option_item] = "table_option_item",
  [sym_table_option_name] = "table_option_name",
  [sym_table_option_value] = "table_option_value",
  [sym_compact_storage] = "compact_storage",
  [sym_clustering_order] = "clustering_order",
  [sym_create_trigger] = "create_trigger",
  [sym_trigger_class] = "trigger_class",
  [sym_create_type] = "create_type",
  [sym_typed_name] = "typed_name",
  [sym_create_user] = "create_user",
  [sym_user_with] = "user_with",
  [sym_user_password] = "user_password",
  [sym_user_super_user] = "user_super_user",
  [sym_alter_materialized_view] = "alter_materialized_view",
  [sym_alter_keyspace] = "alter_keyspace",
  [sym_replication_list] = "replication_list",
  [sym_alter_role] = "alter_role",
  [sym_alter_table] = "alter_table",
  [sym_alter_table_operation] = "alter_table_operation",
  [sym_alter_table_add] = "alter_table_add",
  [sym_alter_table_drop_columns] = "alter_table_drop_columns",
  [sym_alter_table_drop_compact_storage] = "alter_table_drop_compact_storage",
  [sym_alter_table_rename] = "alter_table_rename",
  [sym_alter_type] = "alter_type",
  [sym_alter_type_operation] = "alter_type_operation",
  [sym_alter_type_alter_type] = "alter_type_alter_type",
  [sym_alter_type_add] = "alter_type_add",
  [sym_alter_type_rename] = "alter_type_rename",
  [sym_alter_type_rename_item] = "alter_type_rename_item",
  [sym_alter_user] = "alter_user",
  [sym_apply_batch] = "apply_batch",
  [sym_aggregate_name] = "aggregate_name",
  [sym_function_name] = "function_name",
  [sym_short_index_name] = "short_index_name",
  [sym_index_name] = "index_name",
  [sym_keyspace_name] = "keyspace_name",
  [sym_materialized_view_name] = "materialized_view_name",
  [sym_role_name] = "role_name",
  [sym_table_name] = "table_name",
  [sym_trigger_name] = "trigger_name",
  [sym_type_name] = "type_name",
  [sym_user_name] = "user_name",
  [aux_sym_source_file_repeat1] = "source_file_repeat1",
  [aux_sym_select_elements_repeat1] = "select_elements_repeat1",
  [aux_sym_function_args_repeat1] = "function_args_repeat1",
  [aux_sym_relation_elements_repeat1] = "relation_elements_repeat1",
  [aux_sym_relation_element_repeat1] = "relation_element_repeat1",
  [aux_sym_relation_element_repeat2] = "relation_element_repeat2",
  [aux_sym_delete_column_list_repeat1] = "delete_column_list_repeat1",
  [aux_sym_expression_list_repeat1] = "expression_list_repeat1",
  [aux_sym_assignment_map_repeat1] = "assignment_map_repeat1",
  [aux_sym_assignment_set_repeat1] = "assignment_set_repeat1",
  [aux_sym_update_assignments_repeat1] = "update_assignments_repeat1",
  [aux_sym_init_cond_list_repeat1] = "init_cond_list_repeat1",
  [aux_sym_init_cond_nested_list_repeat1] = "init_cond_nested_list_repeat1",
  [aux_sym_init_cond_hash_repeat1] = "init_cond_hash_repeat1",
  [aux_sym_materialized_view_where_repeat1] = "materialized_view_where_repeat1",
  [aux_sym_create_function_repeat1] = "create_function_repeat1",
  [aux_sym_tuple_type_repeat1] = "tuple_type_repeat1",
  [aux_sym_role_with_repeat1] = "role_with_repeat1",
  [aux_sym_option_hash_repeat1] = "option_hash_repeat1",
  [aux_sym_column_definition_list_repeat1] = "column_definition_list_repeat1",
  [aux_sym_clustering_key_list_repeat1] = "clustering_key_list_repeat1",
  [aux_sym_table_options_repeat1] = "table_options_repeat1",
  [aux_sym_clustering_order_repeat1] = "clustering_order_repeat1",
  [aux_sym_replication_list_repeat1] = "replication_list_repeat1",
  [aux_sym_alter_type_rename_repeat1] = "alter_type_rename_repeat1",
  [anon_alias_sym_aggregate] = "aggregate",
  [anon_alias_sym_alias] = "alias",
  [anon_alias_sym_assignment_operand] = "assignment_operand",
  [anon_alias_sym_code_block] = "code_block",
  [anon_alias_sym_column] = "column",
  [anon_alias_sym_entry] = "entry",
  [anon_alias_sym_finalfunc] = "finalfunc",
  [anon_alias_sym_full] = "full",
  [anon_alias_sym_function] = "function",
  [anon_alias_sym_function_name] = "function_name",
  [anon_alias_sym_hash_key] = "hash_key",
  [anon_alias_sym_index] = "index",
  [anon_alias_sym_key] = "key",
  [anon_alias_sym_keyspace] = "keyspace",
  [anon_alias_sym_language] = "language",
  [anon_alias_sym_limit_value] = "limit_value",
  [anon_alias_sym_login] = "login",
  [anon_alias_sym_materialized_view] = "materialized_view",
  [anon_alias_sym_partition_key] = "partition_key",
  [anon_alias_sym_password] = "password",
  [anon_alias_sym_primary_key] = "primary_key",
  [anon_alias_sym_role] = "role",
  [anon_alias_sym_sfunc] = "sfunc",
  [anon_alias_sym_table] = "table",
  [anon_alias_sym_time] = "time",
  [anon_alias_sym_trigger] = "trigger",
  [anon_alias_sym_ttl] = "ttl",
  [anon_alias_sym_type] = "type",
  [anon_alias_sym_user] = "user",
  [anon_alias_sym_value] = "value",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [anon_sym_SEMI] = anon_sym_SEMI,
  [aux_sym_select_statement_token1] = aux_sym_select_statement_token1,
  [aux_sym_select_statement_token2] = aux_sym_select_statement_token2,
  [aux_sym_select_statement_token3] = aux_sym_select_statement_token3,
  [aux_sym_select_statement_token4] = aux_sym_select_statement_token4,
  [aux_sym_select_statement_token5] = aux_sym_select_statement_token5,
  [aux_sym_limit_spec_token1] = aux_sym_limit_spec_token1,
  [anon_sym_STAR] = anon_sym_STAR,
  [anon_sym_COMMA] = anon_sym_COMMA,
  [aux_sym_select_element_token1] = aux_sym_select_element_token1,
  [anon_sym_LPAREN] = anon_sym_LPAREN,
  [anon_sym_RPAREN] = anon_sym_RPAREN,
  [aux_sym_constant_token1] = aux_sym_constant_token1,
  [aux_sym_constant_token2] = aux_sym_constant_token2,
  [aux_sym_constant_token3] = aux_sym_constant_token3,
  [anon_sym_QMARK] = anon_sym_QMARK,
  [anon_sym_COLON] = anon_sym_COLON,
  [sym__string_literal] = sym__string_literal,
  [aux_sym__decimal_literal_token1] = aux_sym__decimal_literal_token1,
  [sym__float_literal] = sym__float_literal,
  [sym__boolean_literal] = sym__boolean_literal,
  [sym__code_block] = sym__code_block,
  [aux_sym_from_spec_token1] = aux_sym_from_spec_token1,
  [aux_sym_where_spec_token1] = aux_sym_where_spec_token1,
  [aux_sym_relation_elements_token1] = aux_sym_relation_elements_token1,
  [anon_sym_LT] = anon_sym_LT,
  [anon_sym_LT_EQ] = anon_sym_LT_EQ,
  [anon_sym_LT_GT] = anon_sym_LT_GT,
  [anon_sym_EQ] = anon_sym_EQ,
  [anon_sym_GT] = anon_sym_GT,
  [anon_sym_GT_EQ] = anon_sym_GT_EQ,
  [aux_sym_relation_element_token1] = aux_sym_relation_element_token1,
  [aux_sym_relation_contains_key_token1] = aux_sym_relation_contains_key_token1,
  [aux_sym_relation_contains_key_token2] = aux_sym_relation_contains_key_token2,
  [aux_sym_order_spec_token1] = aux_sym_order_spec_token1,
  [aux_sym_order_spec_token2] = aux_sym_order_spec_token2,
  [aux_sym_order_spec_token3] = aux_sym_order_spec_token3,
  [aux_sym_order_spec_token4] = aux_sym_order_spec_token4,
  [aux_sym_delete_statement_token1] = aux_sym_delete_statement_token1,
  [aux_sym_delete_statement_token2] = aux_sym_delete_statement_token2,
  [aux_sym_delete_statement_token3] = aux_sym_delete_statement_token3,
  [aux_sym_begin_batch_token1] = aux_sym_begin_batch_token1,
  [aux_sym_begin_batch_token2] = aux_sym_begin_batch_token2,
  [aux_sym_begin_batch_token3] = aux_sym_begin_batch_token3,
  [aux_sym_begin_batch_token4] = aux_sym_begin_batch_token4,
  [aux_sym_begin_batch_token5] = aux_sym_begin_batch_token5,
  [anon_sym_LBRACK] = anon_sym_LBRACK,
  [anon_sym_RBRACK] = anon_sym_RBRACK,
  [aux_sym_using_timestamp_spec_token1] = aux_sym_using_timestamp_spec_token1,
  [aux_sym_using_timestamp_spec_token2] = aux_sym_using_timestamp_spec_token2,
  [aux_sym_insert_statement_token1] = aux_sym_insert_statement_token1,
  [aux_sym_insert_statement_token2] = aux_sym_insert_statement_token2,
  [aux_sym_insert_statement_token3] = aux_sym_insert_statement_token3,
  [aux_sym_insert_values_spec_token1] = aux_sym_insert_values_spec_token1,
  [anon_sym_LBRACE] = anon_sym_LBRACE,
  [anon_sym_RBRACE] = anon_sym_RBRACE,
  [aux_sym_using_ttl_timestamp_token1] = aux_sym_using_ttl_timestamp_token1,
  [aux_sym_truncate_token1] = aux_sym_truncate_token1,
  [aux_sym_truncate_token2] = aux_sym_truncate_token2,
  [aux_sym_create_index_token1] = aux_sym_create_index_token1,
  [aux_sym_create_index_token2] = aux_sym_create_index_token2,
  [aux_sym_create_index_token3] = aux_sym_create_index_token3,
  [aux_sym_index_keys_spec_token1] = aux_sym_index_keys_spec_token1,
  [aux_sym_index_entries_s_spec_token1] = aux_sym_index_entries_s_spec_token1,
  [aux_sym_index_full_spec_token1] = aux_sym_index_full_spec_token1,
  [aux_sym_drop_index_token1] = aux_sym_drop_index_token1,
  [aux_sym_update_token1] = aux_sym_update_token1,
  [aux_sym_update_assignments_token1] = aux_sym_update_assignments_token1,
  [anon_sym_PLUS] = anon_sym_PLUS,
  [anon_sym_DASH] = anon_sym_DASH,
  [aux_sym_use_token1] = aux_sym_use_token1,
  [aux_sym_grant_token1] = aux_sym_grant_token1,
  [aux_sym_grant_token2] = aux_sym_grant_token2,
  [aux_sym_revoke_token1] = aux_sym_revoke_token1,
  [aux_sym_privilege_token1] = aux_sym_privilege_token1,
  [aux_sym_privilege_token2] = aux_sym_privilege_token2,
  [aux_sym_privilege_token3] = aux_sym_privilege_token3,
  [aux_sym_privilege_token4] = aux_sym_privilege_token4,
  [aux_sym_privilege_token5] = aux_sym_privilege_token5,
  [aux_sym_privilege_token6] = aux_sym_privilege_token6,
  [aux_sym_privilege_token7] = aux_sym_privilege_token7,
  [aux_sym_resource_token1] = aux_sym_resource_token1,
  [aux_sym_resource_token2] = aux_sym_resource_token2,
  [aux_sym_resource_token3] = aux_sym_resource_token3,
  [aux_sym_resource_token4] = aux_sym_resource_token4,
  [aux_sym_resource_token5] = aux_sym_resource_token5,
  [anon_sym_DOT] = anon_sym_DOT,
  [aux_sym_resource_token6] = aux_sym_resource_token6,
  [aux_sym_list_roles_token1] = aux_sym_list_roles_token1,
  [aux_sym_list_roles_token2] = aux_sym_list_roles_token2,
  [aux_sym_list_roles_token3] = aux_sym_list_roles_token3,
  [aux_sym_drop_aggregate_token1] = aux_sym_drop_aggregate_token1,
  [aux_sym_drop_materialized_view_token1] = aux_sym_drop_materialized_view_token1,
  [aux_sym_drop_materialized_view_token2] = aux_sym_drop_materialized_view_token2,
  [aux_sym_drop_trigger_token1] = aux_sym_drop_trigger_token1,
  [aux_sym_drop_type_token1] = aux_sym_drop_type_token1,
  [aux_sym_drop_user_token1] = aux_sym_drop_user_token1,
  [aux_sym_create_aggregate_token1] = aux_sym_create_aggregate_token1,
  [aux_sym_create_aggregate_token2] = aux_sym_create_aggregate_token2,
  [aux_sym_create_aggregate_token3] = aux_sym_create_aggregate_token3,
  [aux_sym_create_aggregate_token4] = aux_sym_create_aggregate_token4,
  [aux_sym_create_aggregate_token5] = aux_sym_create_aggregate_token5,
  [aux_sym_create_aggregate_token6] = aux_sym_create_aggregate_token6,
  [aux_sym_column_not_null_token1] = aux_sym_column_not_null_token1,
  [aux_sym_create_function_token1] = aux_sym_create_function_token1,
  [aux_sym_create_function_token2] = aux_sym_create_function_token2,
  [aux_sym_native_type_token1] = aux_sym_native_type_token1,
  [aux_sym_native_type_token2] = aux_sym_native_type_token2,
  [aux_sym_native_type_token3] = aux_sym_native_type_token3,
  [aux_sym_native_type_token4] = aux_sym_native_type_token4,
  [aux_sym_native_type_token5] = aux_sym_native_type_token5,
  [aux_sym_native_type_token6] = aux_sym_native_type_token6,
  [aux_sym_native_type_token7] = aux_sym_native_type_token7,
  [aux_sym_native_type_token8] = aux_sym_native_type_token8,
  [aux_sym_native_type_token9] = aux_sym_native_type_token9,
  [aux_sym_native_type_token10] = aux_sym_native_type_token10,
  [aux_sym_native_type_token11] = aux_sym_native_type_token11,
  [aux_sym_native_type_token12] = aux_sym_native_type_token12,
  [aux_sym_native_type_token13] = aux_sym_native_type_token13,
  [aux_sym_native_type_token14] = aux_sym_native_type_token14,
  [aux_sym_native_type_token15] = aux_sym_native_type_token15,
  [aux_sym_native_type_token16] = aux_sym_native_type_token16,
  [aux_sym_native_type_token17] = aux_sym_native_type_token17,
  [aux_sym_native_type_token18] = aux_sym_native_type_token18,
  [aux_sym_native_type_token19] = aux_sym_native_type_token19,
  [aux_sym_collection_type_token1] = aux_sym_collection_type_token1,
  [aux_sym_tuple_type_token1] = aux_sym_tuple_type_token1,
  [aux_sym_frozen_type_token1] = aux_sym_frozen_type_token1,
  [aux_sym_return_mode_token1] = aux_sym_return_mode_token1,
  [aux_sym_return_mode_token2] = aux_sym_return_mode_token2,
  [aux_sym_create_keyspace_token1] = aux_sym_create_keyspace_token1,
  [aux_sym_create_keyspace_token2] = aux_sym_create_keyspace_token2,
  [aux_sym_durable_writes_token1] = aux_sym_durable_writes_token1,
  [aux_sym_role_with_option_token1] = aux_sym_role_with_option_token1,
  [aux_sym_role_with_option_token2] = aux_sym_role_with_option_token2,
  [aux_sym_role_with_option_token3] = aux_sym_role_with_option_token3,
  [aux_sym_role_with_option_token4] = aux_sym_role_with_option_token4,
  [aux_sym_primary_key_column_token1] = aux_sym_primary_key_column_token1,
  [aux_sym_compact_storage_token1] = aux_sym_compact_storage_token1,
  [aux_sym_compact_storage_token2] = aux_sym_compact_storage_token2,
  [aux_sym_clustering_order_token1] = aux_sym_clustering_order_token1,
  [aux_sym_user_super_user_token1] = aux_sym_user_super_user_token1,
  [aux_sym_alter_table_add_token1] = aux_sym_alter_table_add_token1,
  [aux_sym_alter_table_rename_token1] = aux_sym_alter_table_rename_token1,
  [aux_sym_apply_batch_token1] = aux_sym_apply_batch_token1,
  [sym_object_name] = sym_object_name,
  [sym_source_file] = sym_source_file,
  [sym__statement] = sym__statement,
  [sym_select_statement] = sym_select_statement,
  [sym_limit_spec] = sym_limit_spec,
  [sym_select_elements] = sym_select_elements,
  [sym_select_element] = sym_select_element,
  [sym_function_call] = sym_function_call,
  [sym_function_args] = sym_function_args,
  [sym_constant] = sym_constant,
  [sym_bind_marker] = sym_bind_marker,
  [sym__value_marker] = sym__value_marker,
  [sym__decimal_literal] = sym__decimal_literal,
  [sym_from_spec] = sym_from_spec,
  [sym_where_spec] = sym_where_spec,
  [sym_relation_elements] = sym_relation_elements,
  [sym_relation_element] = sym_relation_element,
  [sym_relation_contains_key] = sym_relation_contains_key,
  [sym_relation_contains] = sym_relation_contains,
  [sym_order_spec] = sym_order_spec,
  [sym_delete_statement] = sym_delete_statement,
  [sym_begin_batch] = sym_begin_batch,
  [sym_delete_column_list] = sym_delete_column_list,
  [sym_delete_column_item] = sym_delete_column_item,
  [sym_using_timestamp_spec] = sym_using_timestamp_spec,
  [sym_if_spec] = sym_if_spec,
  [sym_insert_statement] = sym_insert_statement,
  [sym_insert_column_spec] = sym_insert_column_spec,
  [sym_column_list] = sym_column_list,
  [sym_insert_values_spec] = sym_insert_values_spec,
  [sym_expression_list] = sym_expression_list,
  [sym_expression] = sym_expression,
  [sym_assignment_map] = sym_assignment_map,
  [sym_assignment_set] = sym_assignment_set,
  [sym_assignment_list] = sym_assignment_list,
  [sym_assignment_tuple] = sym_assignment_tuple,
  [sym_using_ttl_timestamp] = sym_using_ttl_timestamp,
  [sym_truncate] = sym_truncate,
  [sym_create_index] = sym_create_index,
  [sym_index_column_spec] = sym_index_column_spec,
  [sym_index_keys_spec] = sym_index_keys_spec,
  [sym_index_entries_s_spec] = sym_index_entries_s_spec,
  [sym_index_full_spec] = sym_index_full_spec,
  [sym_drop_index] = sym_drop_index,
  [sym_update] = sym_update,
  [sym_update_assignments] = sym_update_assignments,
  [sym_assignment_element] = sym_assignment_element,
  [sym_indexed_column] = sym_indexed_column,
  [sym_use] = sym_use,
  [sym_grant] = sym_grant,
  [sym_revoke] = sym_revoke,
  [sym_privilege] = sym_privilege,
  [sym_resource] = sym_resource,
  [sym_list_roles] = sym_list_roles,
  [sym_list_permissions] = sym_list_permissions,
  [sym_drop_aggregate] = sym_drop_aggregate,
  [sym_drop_materialized_view] = sym_drop_materialized_view,
  [sym_drop_function] = sym_drop_function,
  [sym_drop_keyspace] = sym_drop_keyspace,
  [sym_drop_role] = sym_drop_role,
  [sym_drop_table] = sym_drop_table,
  [sym_drop_trigger] = sym_drop_trigger,
  [sym_drop_type] = sym_drop_type,
  [sym_drop_user] = sym_drop_user,
  [sym_create_aggregate] = sym_create_aggregate,
  [sym_init_cond_definition] = sym_init_cond_definition,
  [sym_init_cond_list] = sym_init_cond_list,
  [sym_init_cond_nested_list] = sym_init_cond_nested_list,
  [sym_init_cond_hash] = sym_init_cond_hash,
  [sym_init_cond_hash_item] = sym_init_cond_hash_item,
  [sym_create_materialized_view] = sym_create_materialized_view,
  [sym_materialized_view_where] = sym_materialized_view_where,
  [sym_column_not_null] = sym_column_not_null,
  [sym_create_function] = sym_create_function,
  [sym_data_type] = sym_data_type,
  [sym_cql_type] = sym_cql_type,
  [sym_user_defined_type] = sym_user_defined_type,
  [sym_udt_name] = sym_udt_name,
  [sym_native_type] = sym_native_type,
  [sym_collection_type] = sym_collection_type,
  [sym_tuple_type] = sym_tuple_type,
  [sym_frozen_type] = sym_frozen_type,
  [sym_return_mode] = sym_return_mode,
  [sym_create_keyspace] = sym_create_keyspace,
  [sym_replication_list_item] = sym_replication_list_item,
  [sym_durable_writes] = sym_durable_writes,
  [sym_create_role] = sym_create_role,
  [sym_role_with] = sym_role_with,
  [sym_role_with_option] = sym_role_with_option,
  [sym_option_hash] = sym_option_hash,
  [sym_option_hash_item] = sym_option_hash_item,
  [sym_create_table] = sym_create_table,
  [sym_column_definition_list] = sym_column_definition_list,
  [sym_column_definition] = sym_column_definition,
  [sym_primary_key_column] = sym_primary_key_column,
  [sym_primary_key_element] = sym_primary_key_element,
  [sym_primary_key_definition] = sym_primary_key_definition,
  [sym_compound_key] = sym_compound_key,
  [sym_clustering_key_list] = sym_clustering_key_list,
  [sym_composite_key] = sym_composite_key,
  [sym_partition_key_list] = sym_partition_key_list,
  [sym_with_element] = sym_with_element,
  [sym_table_options] = sym_table_options,
  [sym_table_option_item] = sym_table_option_item,
  [sym_table_option_name] = sym_table_option_name,
  [sym_table_option_value] = sym_table_option_value,
  [sym_compact_storage] = sym_compact_storage,
  [sym_clustering_order] = sym_clustering_order,
  [sym_create_trigger] = sym_create_trigger,
  [sym_trigger_class] = sym_trigger_class,
  [sym_create_type] = sym_create_type,
  [sym_typed_name] = sym_typed_name,
  [sym_create_user] = sym_create_user,
  [sym_user_with] = sym_user_with,
  [sym_user_password] = sym_user_password,
  [sym_user_super_user] = sym_user_super_user,
  [sym_alter_materialized_view] = sym_alter_materialized_view,
  [sym_alter_keyspace] = sym_alter_keyspace,
  [sym_replication_list] = sym_replication_list,
  [sym_alter_role] = sym_alter_role,
  [sym_alter_table] = sym_alter_table,
  [sym_alter_table_operation] = sym_alter_table_operation,
  [sym_alter_table_add] = sym_alter_table_add,
  [sym_alter_table_drop_columns] = sym_alter_table_drop_columns,
  [sym_alter_table_drop_compact_storage] = sym_alter_table_drop_compact_storage,
  [sym_alter_table_rename] = sym_alter_table_rename,
  [sym_alter_type] = sym_alter_type,
  [sym_alter_type_operation] = sym_alter_type_operation,
  [sym_alter_type_alter_type] = sym_alter_type_alter_type,
  [sym_alter_type_add] = sym_alter_type_add,
  [sym_alter_type_rename] = sym_alter_type_rename,
  [sym_alter_type_rename_item] = sym_alter_type_rename_item,
  [sym_alter_user] = sym_alter_user,
  [sym_apply_batch] = sym_apply_batch,
  [sym_aggregate_name] = sym_aggregate_name,
  [sym_function_name] = sym_function_name,
  [sym_short_index_name] = sym_short_index_name,
  [sym_index_name] = sym_index_name,
  [sym_keyspace_name] = sym_keyspace_name,
  [sym_materialized_view_name] = sym_materialized_view_name,
  [sym_role_name] = sym_role_name,
  [sym_table_name] = sym_table_name,
  [sym_trigger_name] = sym_trigger_name,
  [sym_type_name] = sym_type_name,
  [sym_user_name] = sym_user_name,
  [aux_sym_source_file_repeat1] = aux_sym_source_file_repeat1,
  [aux_sym_select_elements_repeat1] = aux_sym_select_elements_repeat1,
  [aux_sym_function_args_repeat1] = aux_sym_function_args_repeat1,
  [aux_sym_relation_elements_repeat1] = aux_sym_relation_elements_repeat1,
  [aux_sym_relation_element_repeat1] = aux_sym_relation_element_repeat1,
  [aux_sym_relation_element_repeat2] = aux_sym_relation_element_repeat2,
  [aux_sym_delete_column_list_repeat1] = aux_sym_delete_column_list_repeat1,
  [aux_sym_expression_list_repeat1] = aux_sym_expression_list_repeat1,
  [aux_sym_assignment_map_repeat1] = aux_sym_assignment_map_repeat1,
  [aux_sym_assignment_set_repeat1] = aux_sym_assignment_set_repeat1,
  [aux_sym_update_assignments_repeat1] = aux_sym_update_assignments_repeat1,
  [aux_sym_init_cond_list_repeat1] = aux_sym_init_cond_list_repeat1,
  [aux_sym_init_cond_nested_list_repeat1] = aux_sym_init_cond_nested_list_repeat1,
  [aux_sym_init_cond_hash_repeat1] = aux_sym_init_cond_hash_repeat1,
  [aux_sym_materialized_view_where_repeat1] = aux_sym_materialized_view_where_repeat1,
  [aux_sym_create_function_repeat1] = aux_sym_create_function_repeat1,
  [aux_sym_tuple_type_repeat1] = aux_sym_tuple_type_repeat1,
  [aux_sym_role_with_repeat1] = aux_sym_role_with_repeat1,
  [aux_sym_option_hash_repeat1] = aux_sym_option_hash_repeat1,
  [aux_sym_column_definition_list_repeat1] = aux_sym_column_definition_list_repeat1,
  [aux_sym_clustering_key_list_repeat1] = aux_sym_clustering_key_list_repeat1,
  [aux_sym_table_options_repeat1] = aux_sym_table_options_repeat1,
  [aux_sym_clustering_order_repeat1] = aux_sym_clustering_order_repeat1,
  [aux_sym_replication_list_repeat1] = aux_sym_replication_list_repeat1,
  [aux_sym_alter_type_rename_repeat1] = aux_sym_alter_type_rename_repeat1,
  [anon_alias_sym_aggregate] = anon_alias_sym_aggregate,
  [anon_alias_sym_alias] = anon_alias_sym_alias,
  [anon_alias_sym_assignment_operand] = anon_alias_sym_assignment_operand,
  [anon_alias_sym_code_block] = anon_alias_sym_code_block,
  [anon_alias_sym_column] = anon_alias_sym_column,
  [anon_alias_sym_entry] = anon_alias_sym_entry,
  [anon_alias_sym_finalfunc] = anon_alias_sym_finalfunc,
  [anon_alias_sym_full] = anon_alias_sym_full,
  [anon_alias_sym_function] = anon_alias_sym_function,
  [anon_alias_sym_function_name] = anon_alias_sym_function_name,
  [anon_alias_sym_hash_key] = anon_alias_sym_hash_key,
  [anon_alias_sym_index] = anon_alias_sym_index,
  [anon_alias_sym_key] = anon_alias_sym_key,
  [anon_alias_sym_keyspace] = anon_alias_sym_keyspace,
  [anon_alias_sym_language] = anon_alias_sym_language,
  [anon_alias_sym_limit_value] = anon_alias_sym_limit_value,
  [anon_alias_sym_login] = anon_alias_sym_login,
  [anon_alias_sym_materialized_view] = anon_alias_sym_materialized_view,
  [anon_alias_sym_partition_key] = anon_alias_sym_partition_key,
  [anon_alias_sym_password] = anon_alias_sym_password,
  [anon_alias_sym_primary_key] = anon_alias_sym_primary_key,
  [anon_alias_sym_role] = anon_alias_sym_role,
  [anon_alias_sym_sfunc] = anon_alias_sym_sfunc,
  [anon_alias_sym_table] = anon_alias_sym_table,
  [anon_alias_sym_time] = anon_alias_sym_time,
  [anon_alias_sym_trigger] = anon_alias_sym_trigger,
  [anon_alias_sym_ttl] = anon_alias_sym_ttl,
  [anon_alias_sym_type] = anon_alias_sym_type,
  [anon_alias_sym_user] = anon_alias_sym_user,
  [anon_alias_sym_value] = anon_alias_sym_value,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [anon_sym_SEMI] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_select_statement_token1] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_select_statement_token2] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_select_statement_token3] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_select_statement_token4] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_select_statement_token5] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_limit_spec_token1] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_STAR] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COMMA] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_select_element_token1] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RPAREN] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_constant_token1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_constant_token2] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_constant_token3] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_QMARK] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COLON] = {
    .visible = true,
    .named = false,
  },
  [sym__string_literal] = {
    .visible = false,
    .named = true,
  },
  [aux_sym__decimal_literal_token1] = {
    .visible = false,
    .named = false,
  },
  [sym__float_literal] = {
    .visible = false,
    .named = true,
  },
  [sym__boolean_literal] = {
    .visible = false,
    .named = true,
  },
  [sym__code_block] = {
    .visible = false,
    .named = true,
  },
  [aux_sym_from_spec_token1] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_where_spec_token1] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_relation_elements_token1] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LT_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LT_GT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_GT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_GT_EQ] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_relation_element_token1] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_relation_contains_key_token1] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_relation_contains_key_token2] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_order_spec_token1] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_order_spec_token2] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_order_spec_token3] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_order_spec_token4] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_delete_statement_token1] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_delete_statement_token2] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_delete_statement_token3] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_begin_batch_token1] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_begin_batch_token2] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_begin_batch_token3] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_begin_batch_token4] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_begin_batch_token5] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LBRACK] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACK] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_using_timestamp_spec_token1] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_using_timestamp_spec_token2] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_insert_statement_token1] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_insert_statement_token2] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_insert_statement_token3] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_insert_values_spec_token1] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACE] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_using_ttl_timestamp_token1] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_truncate_token1] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_truncate_token2] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_create_index_token1] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_create_index_token2] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_create_index_token3] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_index_keys_spec_token1] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_index_entries_s_spec_token1] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_index_full_spec_token1] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_drop_index_token1] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_update_token1] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_update_assignments_token1] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PLUS] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DASH] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_use_token1] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_grant_token1] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_grant_token2] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_revoke_token1] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_privilege_token1] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_privilege_token2] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_privilege_token3] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_privilege_token4] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_privilege_token5] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_privilege_token6] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_privilege_token7] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_resource_token1] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_resource_token2] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_resource_token3] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_resource_token4] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_resource_token5] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DOT] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_resource_token6] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_list_roles_token1] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_list_roles_token2] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_list_roles_token3] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_drop_aggregate_token1] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_drop_materialized_view_token1] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_drop_materialized_view_token2] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_drop_trigger_token1] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_drop_type_token1] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_drop_user_token1] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_create_aggregate_token1] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_create_aggregate_token2] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_create_aggregate_token3] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_create_aggregate_token4] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_create_aggregate_token5] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_create_aggregate_token6] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_column_not_null_token1] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_create_function_token1] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_create_function_token2] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_native_type_token1] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_native_type_token2] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_native_type_token3] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_native_type_token4] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_native_type_token5] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_native_type_token6] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_native_type_token7] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_native_type_token8] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_native_type_token9] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_native_type_token10] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_native_type_token11] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_native_type_token12] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_native_type_token13] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_native_type_token14] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_native_type_token15] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_native_type_token16] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_native_type_token17] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_native_type_token18] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_native_type_token19] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_collection_type_token1] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_tuple_type_token1] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_frozen_type_token1] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_return_mode_token1] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_return_mode_token2] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_create_keyspace_token1] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_create_keyspace_token2] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_durable_writes_token1] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_role_with_option_token1] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_role_with_option_token2] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_role_with_option_token3] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_role_with_option_token4] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_primary_key_column_token1] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_compact_storage_token1] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_compact_storage_token2] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_clustering_order_token1] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_user_super_user_token1] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_alter_table_add_token1] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_alter_table_rename_token1] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_apply_batch_token1] = {
    .visible = true,
    .named = false,
  },
  [sym_object_name] = {
    .visible = true,
    .named = true,
  },
  [sym_source_file] = {
    .visible = true,
    .named = true,
  },
  [sym__statement] = {
    .visible = false,
    .named = true,
  },
  [sym_select_statement] = {
    .visible = true,
    .named = true,
  },
  [sym_limit_spec] = {
    .visible = true,
    .named = true,
  },
  [sym_select_elements] = {
    .visible = true,
    .named = true,
  },
  [sym_select_element] = {
    .visible = true,
    .named = true,
  },
  [sym_function_call] = {
    .visible = true,
    .named = true,
  },
  [sym_function_args] = {
    .visible = true,
    .named = true,
  },
  [sym_constant] = {
    .visible = true,
    .named = true,
  },
  [sym_bind_marker] = {
    .visible = true,
    .named = true,
  },
  [sym__value_marker] = {
    .visible = false,
    .named = true,
  },
  [sym__decimal_literal] = {
    .visible = false,
    .named = true,
  },
  [sym_from_spec] = {
    .visible = true,
    .named = true,
  },
  [sym_where_spec] = {
    .visible = true,
    .named = true,
  },
  [sym_relation_elements] = {
    .visible = true,
    .named = true,
  },
  [sym_relation_element] = {
    .visible = true,
    .named = true,
  },
  [sym_relation_contains_key] = {
    .visible = true,
    .named = true,
  },
  [sym_relation_contains] = {
    .visible = true,
    .named = true,
  },
  [sym_order_spec] = {
    .visible = true,
    .named = true,
  },
  [sym_delete_statement] = {
    .visible = true,
    .named = true,
  },
  [sym_begin_batch] = {
    .visible = true,
    .named = true,
  },
  [sym_delete_column_list] = {
    .visible = true,
    .named = true,
  },
  [sym_delete_column_item] = {
    .visible = true,
    .named = true,
  },
  [sym_using_timestamp_spec] = {
    .visible = true,
    .named = true,
  },
  [sym_if_spec] = {
    .visible = true,
    .named = true,
  },
  [sym_insert_statement] = {
    .visible = true,
    .named = true,
  },
  [sym_insert_column_spec] = {
    .visible = true,
    .named = true,
  },
  [sym_column_list] = {
    .visible = true,
    .named = true,
  },
  [sym_insert_values_spec] = {
    .visible = true,
    .named = true,
  },
  [sym_expression_list] = {
    .visible = true,
    .named = true,
  },
  [sym_expression] = {
    .visible = true,
    .named = true,
  },
  [sym_assignment_map] = {
    .visible = true,
    .named = true,
  },
  [sym_assignment_set] = {
    .visible = true,
    .named = true,
  },
  [sym_assignment_list] = {
    .visible = true,
    .named = true,
  },
  [sym_assignment_tuple] = {
    .visible = true,
    .named = true,
  },
  [sym_using_ttl_timestamp] = {
    .visible = true,
    .named = true,
  },
  [sym_truncate] = {
    .visible = true,
    .named = true,
  },
  [sym_create_index] = {
    .visible = true,
    .named = true,
  },
  [sym_index_column_spec] = {
    .visible = true,
    .named = true,
  },
  [sym_index_keys_spec] = {
    .visible = true,
    .named = true,
  },
  [sym_index_entries_s_spec] = {
    .visible = true,
    .named = true,
  },
  [sym_index_full_spec] = {
    .visible = true,
    .named = true,
  },
  [sym_drop_index] = {
    .visible = true,
    .named = true,
  },
  [sym_update] = {
    .visible = true,
    .named = true,
  },
  [sym_update_assignments] = {
    .visible = true,
    .named = true,
  },
  [sym_assignment_element] = {
    .visible = true,
    .named = true,
  },
  [sym_indexed_column] = {
    .visible = true,
    .named = true,
  },
  [sym_use] = {
    .visible = true,
    .named = true,
  },
  [sym_grant] = {
    .visible = true,
    .named = true,
  },
  [sym_revoke] = {
    .visible = true,
    .named = true,
  },
  [sym_privilege] = {
    .visible = true,
    .named = true,
  },
  [sym_resource] = {
    .visible = true,
    .named = true,
  },
  [sym_list_roles] = {
    .visible = true,
    .named = true,
  },
  [sym_list_permissions] = {
    .visible = true,
    .named = true,
  },
  [sym_drop_aggregate] = {
    .visible = true,
    .named = true,
  },
  [sym_drop_materialized_view] = {
    .visible = true,
    .named = true,
  },
  [sym_drop_function] = {
    .visible = true,
    .named = true,
  },
  [sym_drop_keyspace] = {
    .visible = true,
    .named = true,
  },
  [sym_drop_role] = {
    .visible = true,
    .named = true,
  },
  [sym_drop_table] = {
    .visible = true,
    .named = true,
  },
  [sym_drop_trigger] = {
    .visible = true,
    .named = true,
  },
  [sym_drop_type] = {
    .visible = true,
    .named = true,
  },
  [sym_drop_user] = {
    .visible = true,
    .named = true,
  },
  [sym_create_aggregate] = {
    .visible = true,
    .named = true,
  },
  [sym_init_cond_definition] = {
    .visible = true,
    .named = true,
  },
  [sym_init_cond_list] = {
    .visible = true,
    .named = true,
  },
  [sym_init_cond_nested_list] = {
    .visible = true,
    .named = true,
  },
  [sym_init_cond_hash] = {
    .visible = true,
    .named = true,
  },
  [sym_init_cond_hash_item] = {
    .visible = true,
    .named = true,
  },
  [sym_create_materialized_view] = {
    .visible = true,
    .named = true,
  },
  [sym_materialized_view_where] = {
    .visible = true,
    .named = true,
  },
  [sym_column_not_null] = {
    .visible = true,
    .named = true,
  },
  [sym_create_function] = {
    .visible = true,
    .named = true,
  },
  [sym_data_type] = {
    .visible = true,
    .named = true,
  },
  [sym_cql_type] = {
    .visible = true,
    .named = true,
  },
  [sym_user_defined_type] = {
    .visible = true,
    .named = true,
  },
  [sym_udt_name] = {
    .visible = true,
    .named = true,
  },
  [sym_native_type] = {
    .visible = true,
    .named = true,
  },
  [sym_collection_type] = {
    .visible = true,
    .named = true,
  },
  [sym_tuple_type] = {
    .visible = true,
    .named = true,
  },
  [sym_frozen_type] = {
    .visible = true,
    .named = true,
  },
  [sym_return_mode] = {
    .visible = true,
    .named = true,
  },
  [sym_create_keyspace] = {
    .visible = true,
    .named = true,
  },
  [sym_replication_list_item] = {
    .visible = true,
    .named = true,
  },
  [sym_durable_writes] = {
    .visible = true,
    .named = true,
  },
  [sym_create_role] = {
    .visible = true,
    .named = true,
  },
  [sym_role_with] = {
    .visible = true,
    .named = true,
  },
  [sym_role_with_option] = {
    .visible = true,
    .named = true,
  },
  [sym_option_hash] = {
    .visible = true,
    .named = true,
  },
  [sym_option_hash_item] = {
    .visible = true,
    .named = true,
  },
  [sym_create_table] = {
    .visible = true,
    .named = true,
  },
  [sym_column_definition_list] = {
    .visible = true,
    .named = true,
  },
  [sym_column_definition] = {
    .visible = true,
    .named = true,
  },
  [sym_primary_key_column] = {
    .visible = true,
    .named = true,
  },
  [sym_primary_key_element] = {
    .visible = true,
    .named = true,
  },
  [sym_primary_key_definition] = {
    .visible = true,
    .named = true,
  },
  [sym_compound_key] = {
    .visible = true,
    .named = true,
  },
  [sym_clustering_key_list] = {
    .visible = true,
    .named = true,
  },
  [sym_composite_key] = {
    .visible = true,
    .named = true,
  },
  [sym_partition_key_list] = {
    .visible = true,
    .named = true,
  },
  [sym_with_element] = {
    .visible = true,
    .named = true,
  },
  [sym_table_options] = {
    .visible = true,
    .named = true,
  },
  [sym_table_option_item] = {
    .visible = true,
    .named = true,
  },
  [sym_table_option_name] = {
    .visible = true,
    .named = true,
  },
  [sym_table_option_value] = {
    .visible = true,
    .named = true,
  },
  [sym_compact_storage] = {
    .visible = true,
    .named = true,
  },
  [sym_clustering_order] = {
    .visible = true,
    .named = true,
  },
  [sym_create_trigger] = {
    .visible = true,
    .named = true,
  },
  [sym_trigger_class] = {
    .visible = true,
    .named = true,
  },
  [sym_create_type] = {
    .visible = true,
    .named = true,
  },
  [sym_typed_name] = {
    .visible = true,
    .named = true,
  },
  [sym_create_user] = {
    .visible = true,
    .named = true,
  },
  [sym_user_with] = {
    .visible = true,
    .named = true,
  },
  [sym_user_password] = {
    .visible = true,
    .named = true,
  },
  [sym_user_super_user] = {
    .visible = true,
    .named = true,
  },
  [sym_alter_materialized_view] = {
    .visible = true,
    .named = true,
  },
  [sym_alter_keyspace] = {
    .visible = true,
    .named = true,
  },
  [sym_replication_list] = {
    .visible = true,
    .named = true,
  },
  [sym_alter_role] = {
    .visible = true,
    .named = true,
  },
  [sym_alter_table] = {
    .visible = true,
    .named = true,
  },
  [sym_alter_table_operation] = {
    .visible = true,
    .named = true,
  },
  [sym_alter_table_add] = {
    .visible = true,
    .named = true,
  },
  [sym_alter_table_drop_columns] = {
    .visible = true,
    .named = true,
  },
  [sym_alter_table_drop_compact_storage] = {
    .visible = true,
    .named = true,
  },
  [sym_alter_table_rename] = {
    .visible = true,
    .named = true,
  },
  [sym_alter_type] = {
    .visible = true,
    .named = true,
  },
  [sym_alter_type_operation] = {
    .visible = true,
    .named = true,
  },
  [sym_alter_type_alter_type] = {
    .visible = true,
    .named = true,
  },
  [sym_alter_type_add] = {
    .visible = true,
    .named = true,
  },
  [sym_alter_type_rename] = {
    .visible = true,
    .named = true,
  },
  [sym_alter_type_rename_item] = {
    .visible = true,
    .named = true,
  },
  [sym_alter_user] = {
    .visible = true,
    .named = true,
  },
  [sym_apply_batch] = {
    .visible = true,
    .named = true,
  },
  [sym_aggregate_name] = {
    .visible = true,
    .named = true,
  },
  [sym_function_name] = {
    .visible = true,
    .named = true,
  },
  [sym_short_index_name] = {
    .visible = true,
    .named = true,
  },
  [sym_index_name] = {
    .visible = true,
    .named = true,
  },
  [sym_keyspace_name] = {
    .visible = true,
    .named = true,
  },
  [sym_materialized_view_name] = {
    .visible = true,
    .named = true,
  },
  [sym_role_name] = {
    .visible = true,
    .named = true,
  },
  [sym_table_name] = {
    .visible = true,
    .named = true,
  },
  [sym_trigger_name] = {
    .visible = true,
    .named = true,
  },
  [sym_type_name] = {
    .visible = true,
    .named = true,
  },
  [sym_user_name] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_source_file_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_select_elements_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_function_args_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_relation_elements_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_relation_element_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_relation_element_repeat2] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_delete_column_list_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_expression_list_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_assignment_map_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_assignment_set_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_update_assignments_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_init_cond_list_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_init_cond_nested_list_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_init_cond_hash_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_materialized_view_where_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_create_function_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_tuple_type_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_role_with_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_option_hash_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_column_definition_list_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_clustering_key_list_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_table_options_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_clustering_order_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_replication_list_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_alter_type_rename_repeat1] = {
    .visible = false,
    .named = false,
  },
  [anon_alias_sym_aggregate] = {
    .visible = true,
    .named = false,
  },
  [anon_alias_sym_alias] = {
    .visible = true,
    .named = false,
  },
  [anon_alias_sym_assignment_operand] = {
    .visible = true,
    .named = false,
  },
  [anon_alias_sym_code_block] = {
    .visible = true,
    .named = false,
  },
  [anon_alias_sym_column] = {
    .visible = true,
    .named = false,
  },
  [anon_alias_sym_entry] = {
    .visible = true,
    .named = false,
  },
  [anon_alias_sym_finalfunc] = {
    .visible = true,
    .named = false,
  },
  [anon_alias_sym_full] = {
    .visible = true,
    .named = false,
  },
  [anon_alias_sym_function] = {
    .visible = true,
    .named = false,
  },
  [anon_alias_sym_function_name] = {
    .visible = true,
    .named = false,
  },
  [anon_alias_sym_hash_key] = {
    .visible = true,
    .named = false,
  },
  [anon_alias_sym_index] = {
    .visible = true,
    .named = false,
  },
  [anon_alias_sym_key] = {
    .visible = true,
    .named = false,
  },
  [anon_alias_sym_keyspace] = {
    .visible = true,
    .named = false,
  },
  [anon_alias_sym_language] = {
    .visible = true,
    .named = false,
  },
  [anon_alias_sym_limit_value] = {
    .visible = true,
    .named = false,
  },
  [anon_alias_sym_login] = {
    .visible = true,
    .named = false,
  },
  [anon_alias_sym_materialized_view] = {
    .visible = true,
    .named = false,
  },
  [anon_alias_sym_partition_key] = {
    .visible = true,
    .named = false,
  },
  [anon_alias_sym_password] = {
    .visible = true,
    .named = false,
  },
  [anon_alias_sym_primary_key] = {
    .visible = true,
    .named = false,
  },
  [anon_alias_sym_role] = {
    .visible = true,
    .named = false,
  },
  [anon_alias_sym_sfunc] = {
    .visible = true,
    .named = false,
  },
  [anon_alias_sym_table] = {
    .visible = true,
    .named = false,
  },
  [anon_alias_sym_time] = {
    .visible = true,
    .named = false,
  },
  [anon_alias_sym_trigger] = {
    .visible = true,
    .named = false,
  },
  [anon_alias_sym_ttl] = {
    .visible = true,
    .named = false,
  },
  [anon_alias_sym_type] = {
    .visible = true,
    .named = false,
  },
  [anon_alias_sym_user] = {
    .visible = true,
    .named = false,
  },
  [anon_alias_sym_value] = {
    .visible = true,
    .named = false,
  },
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
  [1] = {
    [0] = anon_alias_sym_column,
  },
  [2] = {
    [0] = anon_alias_sym_table,
  },
  [3] = {
    [1] = anon_alias_sym_keyspace,
  },
  [4] = {
    [0] = anon_alias_sym_index,
  },
  [5] = {
    [0] = anon_alias_sym_keyspace,
  },
  [6] = {
    [0] = anon_alias_sym_function,
  },
  [7] = {
    [0] = anon_alias_sym_role,
  },
  [8] = {
    [0] = anon_alias_sym_aggregate,
  },
  [9] = {
    [0] = anon_alias_sym_trigger,
  },
  [10] = {
    [0] = anon_alias_sym_type,
  },
  [11] = {
    [0] = anon_alias_sym_user,
  },
  [12] = {
    [0] = anon_alias_sym_column,
    [2] = anon_alias_sym_alias,
  },
  [13] = {
    [2] = anon_alias_sym_alias,
  },
  [14] = {
    [0] = anon_alias_sym_keyspace,
    [2] = anon_alias_sym_table,
  },
  [15] = {
    [0] = anon_alias_sym_materialized_view,
  },
  [16] = {
    [3] = anon_alias_sym_role,
  },
  [17] = {
    [0] = anon_alias_sym_function_name,
  },
  [18] = {
    [1] = anon_alias_sym_limit_value,
  },
  [19] = {
    [0] = anon_alias_sym_column,
    [2] = anon_alias_sym_index,
  },
  [20] = {
    [2] = anon_alias_sym_time,
  },
  [21] = {
    [0] = anon_alias_sym_keyspace,
    [2] = anon_alias_sym_function,
  },
  [22] = {
    [0] = anon_alias_sym_keyspace,
    [2] = anon_alias_sym_aggregate,
  },
  [23] = {
    [0] = anon_alias_sym_keyspace,
    [2] = anon_alias_sym_trigger,
  },
  [24] = {
    [0] = anon_alias_sym_keyspace,
    [2] = anon_alias_sym_type,
  },
  [25] = {
    [0] = anon_alias_sym_keyspace,
    [2] = anon_alias_sym_index,
  },
  [26] = {
    [2] = anon_alias_sym_ttl,
  },
  [27] = {
    [1] = anon_alias_sym_table,
  },
  [28] = {
    [1] = anon_alias_sym_function,
  },
  [29] = {
    [1] = anon_alias_sym_role,
  },
  [30] = {
    [0] = anon_alias_sym_keyspace,
    [2] = anon_alias_sym_materialized_view,
  },
  [31] = {
    [1] = anon_alias_sym_password,
  },
  [32] = {
    [5] = anon_alias_sym_role,
  },
  [33] = {
    [1] = anon_alias_sym_column,
  },
  [34] = {
    [2] = anon_alias_sym_password,
  },
  [35] = {
    [2] = anon_alias_sym_login,
  },
  [36] = {
    [2] = anon_alias_sym_user,
  },
  [37] = {
    [2] = anon_alias_sym_index,
  },
  [38] = {
    [1] = anon_alias_sym_keyspace,
    [3] = anon_alias_sym_table,
  },
  [39] = {
    [1] = anon_alias_sym_keyspace,
    [3] = anon_alias_sym_function,
  },
  [40] = {
    [1] = anon_alias_sym_column,
    [3] = anon_alias_sym_column,
  },
  [41] = {
    [0] = anon_alias_sym_column,
    [2] = anon_alias_sym_column,
  },
  [42] = {
    [2] = anon_alias_sym_time,
    [5] = anon_alias_sym_ttl,
  },
  [43] = {
    [2] = anon_alias_sym_ttl,
    [5] = anon_alias_sym_time,
  },
  [44] = {
    [4] = anon_alias_sym_assignment_operand,
  },
  [45] = {
    [4] = anon_alias_sym_keyspace,
  },
  [46] = {
    [2] = anon_alias_sym_key,
  },
  [47] = {
    [2] = anon_alias_sym_entry,
  },
  [48] = {
    [2] = anon_alias_sym_full,
  },
  [49] = {
    [0] = anon_alias_sym_primary_key,
  },
  [50] = {
    [0] = anon_alias_sym_key,
    [2] = anon_alias_sym_value,
  },
  [51] = {
    [4] = anon_alias_sym_column,
  },
  [52] = {
    [2] = anon_alias_sym_value,
  },
  [53] = {
    [0] = anon_alias_sym_partition_key,
  },
  [54] = {
    [9] = anon_alias_sym_language,
    [11] = anon_alias_sym_code_block,
  },
  [55] = {
    [10] = anon_alias_sym_language,
    [12] = anon_alias_sym_code_block,
  },
  [56] = {
    [11] = anon_alias_sym_language,
    [13] = anon_alias_sym_code_block,
  },
  [57] = {
    [7] = anon_alias_sym_sfunc,
    [11] = anon_alias_sym_finalfunc,
  },
  [58] = {
    [12] = anon_alias_sym_language,
    [14] = anon_alias_sym_code_block,
  },
  [59] = {
    [13] = anon_alias_sym_language,
    [15] = anon_alias_sym_code_block,
  },
  [60] = {
    [9] = anon_alias_sym_sfunc,
    [13] = anon_alias_sym_finalfunc,
  },
  [61] = {
    [14] = anon_alias_sym_language,
    [16] = anon_alias_sym_code_block,
  },
  [62] = {
    [10] = anon_alias_sym_sfunc,
    [14] = anon_alias_sym_finalfunc,
  },
  [63] = {
    [0] = anon_alias_sym_hash_key,
  },
  [64] = {
    [15] = anon_alias_sym_language,
    [17] = anon_alias_sym_code_block,
  },
  [65] = {
    [16] = anon_alias_sym_language,
    [18] = anon_alias_sym_code_block,
  },
  [66] = {
    [12] = anon_alias_sym_sfunc,
    [16] = anon_alias_sym_finalfunc,
  },
};

static const uint16_t ts_non_terminal_alias_map[] = {
  sym__decimal_literal, 5,
    sym__decimal_literal,
    anon_alias_sym_assignment_operand,
    anon_alias_sym_index,
    anon_alias_sym_limit_value,
    anon_alias_sym_value,
  sym_function_name, 3,
    sym_function_name,
    anon_alias_sym_finalfunc,
    anon_alias_sym_sfunc,
  0,
};

static const TSStateId ts_primary_state_ids[STATE_COUNT] = {
  [0] = 0,
  [1] = 1,
  [2] = 2,
  [3] = 3,
  [4] = 4,
  [5] = 5,
  [6] = 6,
  [7] = 7,
  [8] = 8,
  [9] = 9,
  [10] = 10,
  [11] = 11,
  [12] = 12,
  [13] = 13,
  [14] = 14,
  [15] = 15,
  [16] = 16,
  [17] = 17,
  [18] = 18,
  [19] = 19,
  [20] = 20,
  [21] = 21,
  [22] = 22,
  [23] = 23,
  [24] = 24,
  [25] = 25,
  [26] = 26,
  [27] = 27,
  [28] = 28,
  [29] = 29,
  [30] = 30,
  [31] = 31,
  [32] = 32,
  [33] = 33,
  [34] = 34,
  [35] = 35,
  [36] = 36,
  [37] = 37,
  [38] = 38,
  [39] = 39,
  [40] = 40,
  [41] = 41,
  [42] = 42,
  [43] = 43,
  [44] = 44,
  [45] = 45,
  [46] = 46,
  [47] = 47,
  [48] = 48,
  [49] = 49,
  [50] = 50,
  [51] = 51,
  [52] = 52,
  [53] = 53,
  [54] = 54,
  [55] = 55,
  [56] = 56,
  [57] = 57,
  [58] = 58,
  [59] = 59,
  [60] = 60,
  [61] = 61,
  [62] = 62,
  [63] = 63,
  [64] = 64,
  [65] = 65,
  [66] = 66,
  [67] = 67,
  [68] = 68,
  [69] = 69,
  [70] = 70,
  [71] = 71,
  [72] = 72,
  [73] = 73,
  [74] = 74,
  [75] = 75,
  [76] = 76,
  [77] = 77,
  [78] = 78,
  [79] = 79,
  [80] = 80,
  [81] = 81,
  [82] = 82,
  [83] = 83,
  [84] = 84,
  [85] = 85,
  [86] = 86,
  [87] = 87,
  [88] = 88,
  [89] = 89,
  [90] = 90,
  [91] = 91,
  [92] = 92,
  [93] = 93,
  [94] = 94,
  [95] = 95,
  [96] = 96,
  [97] = 97,
  [98] = 98,
  [99] = 99,
  [100] = 100,
  [101] = 101,
  [102] = 102,
  [103] = 103,
  [104] = 104,
  [105] = 105,
  [106] = 106,
  [107] = 107,
  [108] = 108,
  [109] = 109,
  [110] = 110,
  [111] = 111,
  [112] = 112,
  [113] = 113,
  [114] = 114,
  [115] = 115,
  [116] = 116,
  [117] = 117,
  [118] = 118,
  [119] = 119,
  [120] = 120,
  [121] = 121,
  [122] = 122,
  [123] = 123,
  [124] = 124,
  [125] = 125,
  [126] = 126,
  [127] = 127,
  [128] = 128,
  [129] = 129,
  [130] = 130,
  [131] = 131,
  [132] = 132,
  [133] = 133,
  [134] = 134,
  [135] = 135,
  [136] = 136,
  [137] = 137,
  [138] = 138,
  [139] = 139,
  [140] = 140,
  [141] = 141,
  [142] = 142,
  [143] = 143,
  [144] = 144,
  [145] = 145,
  [146] = 146,
  [147] = 147,
  [148] = 148,
  [149] = 149,
  [150] = 150,
  [151] = 151,
  [152] = 152,
  [153] = 153,
  [154] = 154,
  [155] = 155,
  [156] = 156,
  [157] = 157,
  [158] = 158,
  [159] = 159,
  [160] = 160,
  [161] = 161,
  [162] = 162,
  [163] = 163,
  [164] = 164,
  [165] = 165,
  [166] = 166,
  [167] = 167,
  [168] = 168,
  [169] = 169,
  [170] = 170,
  [171] = 171,
  [172] = 172,
  [173] = 173,
  [174] = 174,
  [175] = 175,
  [176] = 176,
  [177] = 177,
  [178] = 178,
  [179] = 179,
  [180] = 180,
  [181] = 181,
  [182] = 182,
  [183] = 183,
  [184] = 184,
  [185] = 185,
  [186] = 186,
  [187] = 187,
  [188] = 188,
  [189] = 189,
  [190] = 190,
  [191] = 191,
  [192] = 192,
  [193] = 193,
  [194] = 194,
  [195] = 195,
  [196] = 196,
  [197] = 197,
  [198] = 198,
  [199] = 199,
  [200] = 200,
  [201] = 201,
  [202] = 202,
  [203] = 203,
  [204] = 204,
  [205] = 205,
  [206] = 206,
  [207] = 207,
  [208] = 208,
  [209] = 209,
  [210] = 210,
  [211] = 211,
  [212] = 212,
  [213] = 213,
  [214] = 214,
  [215] = 215,
  [216] = 216,
  [217] = 217,
  [218] = 218,
  [219] = 219,
  [220] = 220,
  [221] = 221,
  [222] = 222,
  [223] = 223,
  [224] = 224,
  [225] = 225,
  [226] = 226,
  [227] = 227,
  [228] = 228,
  [229] = 229,
  [230] = 230,
  [231] = 231,
  [232] = 232,
  [233] = 233,
  [234] = 234,
  [235] = 235,
  [236] = 236,
  [237] = 237,
  [238] = 238,
  [239] = 239,
  [240] = 240,
  [241] = 241,
  [242] = 242,
  [243] = 243,
  [244] = 244,
  [245] = 245,
  [246] = 246,
  [247] = 247,
  [248] = 248,
  [249] = 249,
  [250] = 250,
  [251] = 251,
  [252] = 252,
  [253] = 253,
  [254] = 254,
  [255] = 255,
  [256] = 256,
  [257] = 257,
  [258] = 258,
  [259] = 259,
  [260] = 260,
  [261] = 261,
  [262] = 262,
  [263] = 263,
  [264] = 264,
  [265] = 265,
  [266] = 266,
  [267] = 267,
  [268] = 268,
  [269] = 269,
  [270] = 270,
  [271] = 271,
  [272] = 272,
  [273] = 273,
  [274] = 274,
  [275] = 275,
  [276] = 276,
  [277] = 277,
  [278] = 278,
  [279] = 279,
  [280] = 280,
  [281] = 281,
  [282] = 282,
  [283] = 283,
  [284] = 284,
  [285] = 285,
  [286] = 286,
  [287] = 287,
  [288] = 288,
  [289] = 289,
  [290] = 290,
  [291] = 291,
  [292] = 292,
  [293] = 293,
  [294] = 294,
  [295] = 295,
  [296] = 296,
  [297] = 297,
  [298] = 298,
  [299] = 299,
  [300] = 300,
  [301] = 301,
  [302] = 302,
  [303] = 303,
  [304] = 304,
  [305] = 305,
  [306] = 306,
  [307] = 307,
  [308] = 308,
  [309] = 309,
  [310] = 310,
  [311] = 311,
  [312] = 312,
  [313] = 313,
  [314] = 314,
  [315] = 315,
  [316] = 316,
  [317] = 317,
  [318] = 318,
  [319] = 319,
  [320] = 320,
  [321] = 321,
  [322] = 322,
  [323] = 323,
  [324] = 324,
  [325] = 325,
  [326] = 326,
  [327] = 327,
  [328] = 328,
  [329] = 329,
  [330] = 330,
  [331] = 331,
  [332] = 332,
  [333] = 333,
  [334] = 334,
  [335] = 335,
  [336] = 336,
  [337] = 337,
  [338] = 338,
  [339] = 339,
  [340] = 340,
  [341] = 341,
  [342] = 342,
  [343] = 343,
  [344] = 344,
  [345] = 345,
  [346] = 346,
  [347] = 347,
  [348] = 348,
  [349] = 349,
  [350] = 350,
  [351] = 351,
  [352] = 352,
  [353] = 353,
  [354] = 354,
  [355] = 355,
  [356] = 356,
  [357] = 357,
  [358] = 358,
  [359] = 359,
  [360] = 360,
  [361] = 361,
  [362] = 362,
  [363] = 363,
  [364] = 364,
  [365] = 365,
  [366] = 366,
  [367] = 367,
  [368] = 368,
  [369] = 369,
  [370] = 370,
  [371] = 371,
  [372] = 372,
  [373] = 373,
  [374] = 374,
  [375] = 375,
  [376] = 376,
  [377] = 377,
  [378] = 378,
  [379] = 379,
  [380] = 380,
  [381] = 381,
  [382] = 382,
  [383] = 383,
  [384] = 384,
  [385] = 385,
  [386] = 386,
  [387] = 387,
  [388] = 388,
  [389] = 389,
  [390] = 390,
  [391] = 391,
  [392] = 392,
  [393] = 393,
  [394] = 394,
  [395] = 395,
  [396] = 396,
  [397] = 397,
  [398] = 398,
  [399] = 399,
  [400] = 400,
  [401] = 401,
  [402] = 402,
  [403] = 403,
  [404] = 404,
  [405] = 405,
  [406] = 406,
  [407] = 407,
  [408] = 408,
  [409] = 409,
  [410] = 410,
  [411] = 411,
  [412] = 412,
  [413] = 413,
  [414] = 414,
  [415] = 415,
  [416] = 416,
  [417] = 417,
  [418] = 418,
  [419] = 419,
  [420] = 420,
  [421] = 421,
  [422] = 422,
  [423] = 423,
  [424] = 424,
  [425] = 425,
  [426] = 426,
  [427] = 427,
  [428] = 428,
  [429] = 429,
  [430] = 430,
  [431] = 431,
  [432] = 432,
  [433] = 433,
  [434] = 434,
  [435] = 435,
  [436] = 436,
  [437] = 437,
  [438] = 438,
  [439] = 439,
  [440] = 440,
  [441] = 441,
  [442] = 442,
  [443] = 443,
  [444] = 444,
  [445] = 445,
  [446] = 446,
  [447] = 447,
  [448] = 448,
  [449] = 449,
  [450] = 450,
  [451] = 451,
  [452] = 452,
  [453] = 453,
  [454] = 454,
  [455] = 455,
  [456] = 456,
  [457] = 457,
  [458] = 458,
  [459] = 459,
  [460] = 460,
  [461] = 461,
  [462] = 462,
  [463] = 463,
  [464] = 464,
  [465] = 465,
  [466] = 466,
  [467] = 467,
  [468] = 468,
  [469] = 469,
  [470] = 470,
  [471] = 471,
  [472] = 472,
  [473] = 473,
  [474] = 474,
  [475] = 475,
  [476] = 476,
  [477] = 477,
  [478] = 478,
  [479] = 479,
  [480] = 480,
  [481] = 481,
  [482] = 482,
  [483] = 483,
  [484] = 484,
  [485] = 485,
  [486] = 486,
  [487] = 487,
  [488] = 488,
  [489] = 489,
  [490] = 490,
  [491] = 491,
  [492] = 492,
  [493] = 493,
  [494] = 494,
  [495] = 495,
  [496] = 496,
  [497] = 497,
  [498] = 498,
  [499] = 499,
  [500] = 500,
  [501] = 501,
  [502] = 502,
  [503] = 503,
  [504] = 504,
  [505] = 505,
  [506] = 506,
  [507] = 507,
  [508] = 508,
  [509] = 509,
  [510] = 510,
  [511] = 511,
  [512] = 512,
  [513] = 513,
  [514] = 514,
  [515] = 515,
  [516] = 516,
  [517] = 517,
  [518] = 518,
  [519] = 519,
  [520] = 520,
  [521] = 521,
  [522] = 522,
  [523] = 523,
  [524] = 524,
  [525] = 525,
  [526] = 526,
  [527] = 527,
  [528] = 528,
  [529] = 529,
  [530] = 530,
  [531] = 531,
  [532] = 532,
  [533] = 533,
  [534] = 534,
  [535] = 535,
  [536] = 536,
  [537] = 537,
  [538] = 538,
  [539] = 539,
  [540] = 540,
  [541] = 541,
  [542] = 542,
  [543] = 543,
  [544] = 544,
  [545] = 545,
  [546] = 546,
  [547] = 547,
  [548] = 548,
  [549] = 549,
  [550] = 550,
  [551] = 551,
  [552] = 552,
  [553] = 553,
  [554] = 554,
  [555] = 555,
  [556] = 556,
  [557] = 557,
  [558] = 558,
  [559] = 559,
  [560] = 560,
  [561] = 561,
  [562] = 562,
  [563] = 563,
  [564] = 564,
  [565] = 565,
  [566] = 566,
  [567] = 567,
  [568] = 568,
  [569] = 569,
  [570] = 570,
  [571] = 571,
  [572] = 572,
  [573] = 573,
  [574] = 574,
  [575] = 575,
  [576] = 576,
  [577] = 577,
  [578] = 578,
  [579] = 579,
  [580] = 580,
  [581] = 581,
  [582] = 582,
  [583] = 583,
  [584] = 584,
  [585] = 585,
  [586] = 586,
  [587] = 587,
  [588] = 588,
  [589] = 589,
  [590] = 590,
  [591] = 591,
  [592] = 592,
  [593] = 593,
  [594] = 594,
  [595] = 595,
  [596] = 596,
  [597] = 597,
  [598] = 598,
  [599] = 599,
  [600] = 600,
  [601] = 601,
  [602] = 602,
  [603] = 603,
  [604] = 604,
  [605] = 605,
  [606] = 606,
  [607] = 607,
  [608] = 608,
  [609] = 609,
  [610] = 610,
  [611] = 611,
  [612] = 612,
  [613] = 613,
  [614] = 614,
  [615] = 615,
  [616] = 616,
  [617] = 617,
  [618] = 618,
  [619] = 619,
  [620] = 620,
  [621] = 621,
  [622] = 622,
  [623] = 623,
  [624] = 624,
  [625] = 625,
  [626] = 626,
  [627] = 627,
  [628] = 628,
  [629] = 629,
  [630] = 630,
  [631] = 631,
  [632] = 632,
  [633] = 633,
  [634] = 634,
  [635] = 635,
  [636] = 636,
  [637] = 637,
  [638] = 638,
  [639] = 639,
  [640] = 640,
  [641] = 641,
  [642] = 642,
  [643] = 643,
  [644] = 644,
  [645] = 645,
  [646] = 646,
  [647] = 647,
  [648] = 648,
  [649] = 649,
  [650] = 650,
  [651] = 651,
  [652] = 652,
  [653] = 653,
  [654] = 654,
  [655] = 655,
  [656] = 656,
  [657] = 657,
  [658] = 658,
  [659] = 659,
  [660] = 660,
  [661] = 661,
  [662] = 662,
  [663] = 663,
  [664] = 664,
  [665] = 665,
  [666] = 666,
  [667] = 667,
  [668] = 668,
  [669] = 669,
  [670] = 670,
  [671] = 671,
  [672] = 672,
  [673] = 673,
  [674] = 674,
  [675] = 675,
  [676] = 676,
  [677] = 677,
  [678] = 678,
  [679] = 679,
  [680] = 680,
  [681] = 681,
  [682] = 682,
  [683] = 683,
  [684] = 684,
  [685] = 685,
  [686] = 686,
  [687] = 687,
  [688] = 688,
  [689] = 689,
  [690] = 690,
  [691] = 691,
  [692] = 692,
  [693] = 693,
  [694] = 694,
  [695] = 695,
  [696] = 696,
  [697] = 697,
  [698] = 698,
  [699] = 699,
  [700] = 700,
  [701] = 701,
  [702] = 702,
  [703] = 703,
  [704] = 704,
  [705] = 705,
  [706] = 706,
  [707] = 707,
  [708] = 708,
  [709] = 709,
  [710] = 710,
  [711] = 711,
  [712] = 712,
  [713] = 713,
  [714] = 714,
  [715] = 715,
  [716] = 716,
  [717] = 717,
  [718] = 718,
  [719] = 719,
  [720] = 720,
  [721] = 721,
  [722] = 722,
  [723] = 723,
  [724] = 724,
  [725] = 725,
  [726] = 726,
  [727] = 727,
  [728] = 728,
  [729] = 729,
  [730] = 730,
  [731] = 731,
  [732] = 732,
  [733] = 733,
  [734] = 734,
  [735] = 735,
  [736] = 736,
  [737] = 737,
  [738] = 738,
  [739] = 739,
  [740] = 740,
  [741] = 741,
  [742] = 742,
  [743] = 743,
  [744] = 744,
  [745] = 745,
  [746] = 746,
  [747] = 747,
  [748] = 748,
  [749] = 749,
  [750] = 750,
  [751] = 751,
  [752] = 752,
  [753] = 753,
  [754] = 754,
  [755] = 755,
  [756] = 756,
  [757] = 757,
  [758] = 758,
  [759] = 759,
  [760] = 760,
  [761] = 761,
  [762] = 762,
  [763] = 763,
  [764] = 764,
  [765] = 765,
  [766] = 766,
  [767] = 767,
  [768] = 768,
  [769] = 769,
  [770] = 770,
  [771] = 771,
  [772] = 772,
  [773] = 773,
  [774] = 774,
  [775] = 775,
  [776] = 776,
  [777] = 777,
  [778] = 778,
  [779] = 779,
  [780] = 780,
  [781] = 781,
  [782] = 782,
  [783] = 783,
  [784] = 784,
  [785] = 785,
  [786] = 786,
  [787] = 787,
  [788] = 788,
  [789] = 789,
  [790] = 790,
  [791] = 791,
  [792] = 792,
  [793] = 793,
  [794] = 794,
  [795] = 795,
  [796] = 796,
  [797] = 797,
  [798] = 798,
  [799] = 799,
  [800] = 800,
  [801] = 801,
  [802] = 802,
  [803] = 803,
  [804] = 804,
  [805] = 805,
  [806] = 806,
  [807] = 807,
  [808] = 808,
  [809] = 809,
  [810] = 810,
  [811] = 811,
  [812] = 812,
  [813] = 813,
  [814] = 814,
  [815] = 815,
  [816] = 816,
  [817] = 817,
  [818] = 818,
  [819] = 819,
  [820] = 820,
  [821] = 821,
  [822] = 822,
  [823] = 823,
  [824] = 824,
  [825] = 825,
  [826] = 826,
  [827] = 827,
  [828] = 828,
  [829] = 829,
  [830] = 830,
  [831] = 831,
  [832] = 832,
  [833] = 833,
  [834] = 834,
  [835] = 835,
  [836] = 836,
  [837] = 837,
  [838] = 838,
  [839] = 839,
  [840] = 840,
  [841] = 841,
  [842] = 842,
  [843] = 843,
  [844] = 844,
  [845] = 845,
  [846] = 846,
  [847] = 847,
  [848] = 848,
  [849] = 849,
  [850] = 850,
  [851] = 851,
  [852] = 852,
  [853] = 853,
  [854] = 854,
  [855] = 855,
  [856] = 856,
  [857] = 857,
  [858] = 858,
  [859] = 859,
  [860] = 860,
  [861] = 861,
  [862] = 862,
  [863] = 863,
  [864] = 864,
  [865] = 865,
  [866] = 866,
  [867] = 867,
  [868] = 868,
  [869] = 869,
  [870] = 870,
  [871] = 871,
  [872] = 872,
  [873] = 873,
  [874] = 874,
  [875] = 875,
  [876] = 876,
  [877] = 877,
  [878] = 878,
  [879] = 879,
  [880] = 880,
  [881] = 881,
  [882] = 882,
  [883] = 883,
  [884] = 884,
  [885] = 885,
  [886] = 886,
  [887] = 887,
  [888] = 888,
  [889] = 889,
  [890] = 890,
  [891] = 891,
  [892] = 892,
  [893] = 893,
  [894] = 894,
  [895] = 895,
  [896] = 896,
  [897] = 897,
  [898] = 898,
  [899] = 899,
  [900] = 900,
  [901] = 901,
  [902] = 902,
  [903] = 903,
  [904] = 904,
  [905] = 905,
  [906] = 906,
  [907] = 907,
  [908] = 908,
  [909] = 909,
  [910] = 910,
  [911] = 911,
  [912] = 912,
  [913] = 913,
  [914] = 914,
  [915] = 915,
  [916] = 916,
  [917] = 917,
  [918] = 918,
  [919] = 919,
  [920] = 920,
  [921] = 921,
  [922] = 922,
  [923] = 923,
  [924] = 924,
  [925] = 925,
  [926] = 926,
  [927] = 927,
  [928] = 928,
  [929] = 929,
  [930] = 930,
  [931] = 931,
  [932] = 932,
  [933] = 933,
  [934] = 934,
  [935] = 935,
  [936] = 936,
  [937] = 937,
  [938] = 938,
  [939] = 939,
  [940] = 940,
  [941] = 941,
  [942] = 942,
  [943] = 943,
  [944] = 944,
  [945] = 945,
  [946] = 946,
  [947] = 947,
  [948] = 948,
  [949] = 949,
  [950] = 950,
  [951] = 951,
  [952] = 952,
  [953] = 953,
  [954] = 954,
  [955] = 955,
  [956] = 956,
  [957] = 957,
  [958] = 958,
  [959] = 959,
  [960] = 960,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(559);
      ADVANCE_MAP(
        '$', 18,
        '\'', 25,
        '(', 572,
        ')', 573,
        '*', 569,
        '+', 665,
        ',', 570,
        '-', 666,
        '.', 686,
        '0', 34,
        ':', 579,
        ';', 560,
        '<', 610,
        '=', 613,
        '>', 614,
        '?', 578,
        '[', 636,
        ']', 637,
        '{', 645,
        '}', 646,
        'A', 100,
        'a', 100,
        'B', 45,
        'b', 45,
        'C', 36,
        'c', 36,
        'D', 48,
        'd', 48,
        'E', 310,
        'e', 310,
        'F', 46,
        'f', 46,
        'G', 378,
        'g', 378,
        'I', 194,
        'i', 194,
        'J', 426,
        'j', 426,
        'K', 116,
        'k', 116,
        'L', 37,
        'l', 37,
        'M', 38,
        'm', 38,
        'N', 337,
        'n', 337,
        'O', 197,
        'o', 197,
        'P', 47,
        'p', 47,
        'R', 117,
        'r', 117,
        'S', 152,
        's', 152,
        'T', 39,
        't', 39,
        'U', 312,
        'u', 312,
        'V', 41,
        'v', 41,
        'W', 220,
        'w', 220,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(0);
      END_STATE();
    case 1:
      ADVANCE_MAP(
        '"', 554,
        '$', 18,
        '\'', 23,
        '(', 572,
        '*', 569,
        '-', 518,
        '0', 585,
        ':', 579,
        '?', 578,
        '[', 636,
        '{', 645,
        'F', 776,
        'f', 776,
        'N', 944,
        'n', 944,
        'T', 901,
        't', 901,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(1);
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(593);
      if (('A' <= lookahead && lookahead <= 'E') ||
          ('a' <= lookahead && lookahead <= 'e')) ADVANCE(959);
      if (('G' <= lookahead && lookahead <= 'Z') ||
          ('g' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 2:
      if (lookahead == '"') ADVANCE(554);
      if (lookahead == '\'') ADVANCE(25);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(819);
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(870);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(2);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 3:
      if (lookahead == '"') ADVANCE(554);
      if (lookahead == '\'') ADVANCE(25);
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(870);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(3);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 4:
      ADVANCE_MAP(
        '"', 554,
        '\'', 23,
        '-', 518,
        '[', 636,
        '{', 645,
        'A', 906,
        'a', 906,
        'B', 823,
        'b', 823,
        'C', 883,
        'c', 883,
        'D', 774,
        'd', 774,
        'F', 848,
        'f', 848,
        'I', 864,
        'i', 864,
        'L', 827,
        'l', 827,
        'M', 775,
        'm', 775,
        'S', 810,
        's', 810,
        'T', 801,
        't', 801,
        'U', 938,
        'u', 938,
        'V', 778,
        'v', 778,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(4);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(586);
      if (('E' <= lookahead && lookahead <= 'Z') ||
          ('e' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 5:
      if (lookahead == '"') ADVANCE(554);
      if (lookahead == '(') ADVANCE(572);
      if (lookahead == ')') ADVANCE(573);
      if (lookahead == '*') ADVANCE(569);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(5);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 6:
      if (lookahead == '"') ADVANCE(554);
      if (lookahead == '(') ADVANCE(572);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(947);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(6);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 7:
      if (lookahead == '"') ADVANCE(554);
      if (lookahead == '*') ADVANCE(569);
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(837);
      if (lookahead == 'J' ||
          lookahead == 'j') ADVANCE(916);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(7);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 8:
      if (lookahead == '"') ADVANCE(554);
      if (lookahead == '*') ADVANCE(569);
      if (lookahead == 'J' ||
          lookahead == 'j') ADVANCE(916);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(8);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 9:
      ADVANCE_MAP(
        '"', 554,
        'A', 853,
        'a', 853,
        'F', 941,
        'f', 941,
        'K', 817,
        'k', 817,
        'R', 890,
        'r', 890,
        'T', 788,
        't', 788,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(9);
      if (('B' <= lookahead && lookahead <= 'Z') ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 10:
      if (lookahead == '"') ADVANCE(554);
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(851);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(10);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 11:
      if (lookahead == '"') ADVANCE(554);
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(888);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(11);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 12:
      if (lookahead == '"') ADVANCE(554);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(876);
      if (lookahead == 'F' ||
          lookahead == 'f') ADVANCE(945);
      if (lookahead == 'K' ||
          lookahead == 'k') ADVANCE(811);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(12);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 13:
      if (lookahead == '"') ADVANCE(554);
      if (lookahead == 'F' ||
          lookahead == 'f') ADVANCE(902);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(13);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 14:
      if (lookahead == '"') ADVANCE(554);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(819);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(14);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 15:
      if (lookahead == '"') ADVANCE(554);
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(905);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(15);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 16:
      if (lookahead == '"') ADVANCE(554);
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(788);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(16);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 17:
      if (lookahead == '"') ADVANCE(772);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(17);
      END_STATE();
    case 18:
      if (lookahead == '$') ADVANCE(19);
      END_STATE();
    case 19:
      if (lookahead == '$') ADVANCE(556);
      if (lookahead != 0) ADVANCE(21);
      END_STATE();
    case 20:
      if (lookahead == '$') ADVANCE(605);
      if (lookahead != 0) ADVANCE(21);
      END_STATE();
    case 21:
      if (lookahead == '$') ADVANCE(20);
      if (lookahead != 0) ADVANCE(21);
      END_STATE();
    case 22:
      if (lookahead == '\'') ADVANCE(580);
      if (lookahead == '+') ADVANCE(596);
      if (lookahead == '-') ADVANCE(24);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(597);
      if (lookahead != 0) ADVANCE(25);
      END_STATE();
    case 23:
      if (lookahead == '\'') ADVANCE(580);
      if (lookahead == '-') ADVANCE(26);
      if (lookahead != 0) ADVANCE(25);
      END_STATE();
    case 24:
      if (lookahead == '\'') ADVANCE(580);
      if (lookahead == '+' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(597);
      if (lookahead != 0) ADVANCE(25);
      END_STATE();
    case 25:
      if (lookahead == '\'') ADVANCE(580);
      if (lookahead != 0) ADVANCE(25);
      END_STATE();
    case 26:
      if (lookahead == '\'') ADVANCE(582);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(598);
      if (lookahead != 0) ADVANCE(25);
      END_STATE();
    case 27:
      if (lookahead == '\'') ADVANCE(581);
      if (lookahead != 0) ADVANCE(25);
      END_STATE();
    case 28:
      if (lookahead == '\'') ADVANCE(600);
      END_STATE();
    case 29:
      if (lookahead == '+') ADVANCE(602);
      if (lookahead == '-') ADVANCE(521);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(595);
      END_STATE();
    case 30:
      if (lookahead == '-') ADVANCE(537);
      END_STATE();
    case 31:
      if (lookahead == '-') ADVANCE(543);
      END_STATE();
    case 32:
      if (lookahead == '-') ADVANCE(553);
      END_STATE();
    case 33:
      if (lookahead == '-') ADVANCE(548);
      END_STATE();
    case 34:
      if (lookahead == 'X') ADVANCE(522);
      if (lookahead == 'x') ADVANCE(522);
      END_STATE();
    case 35:
      if (lookahead == '_') ADVANCE(503);
      END_STATE();
    case 36:
      ADVANCE_MAP(
        'A', 288,
        'a', 288,
        'L', 487,
        'l', 487,
        'O', 292,
        'o', 292,
        'R', 156,
        'r', 156,
      );
      END_STATE();
    case 37:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(309);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(294);
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(201);
      END_STATE();
    case 38:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(364);
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(112);
      END_STATE();
    case 39:
      ADVANCE_MAP(
        'A', 76,
        'a', 76,
        'E', 505,
        'e', 505,
        'I', 297,
        'i', 297,
        'O', 669,
        'o', 669,
        'R', 231,
        'r', 231,
        'T', 258,
        't', 258,
        'U', 375,
        'u', 375,
        'Y', 373,
        'y', 373,
      );
      END_STATE();
    case 40:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(76);
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(230);
      if (lookahead == 'Y' ||
          lookahead == 'y') ADVANCE(373);
      END_STATE();
    case 41:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(271);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(120);
      END_STATE();
    case 42:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(78);
      END_STATE();
    case 43:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(267);
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(348);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('B' <= lookahead && lookahead <= 'F') ||
          ('b' <= lookahead && lookahead <= 'f')) ADVANCE(534);
      END_STATE();
    case 44:
      ADVANCE_MAP(
        'A', 256,
        'a', 256,
        'C', 390,
        'c', 390,
        'D', 180,
        'd', 180,
        'E', 506,
        'e', 506,
        'K', 193,
        'k', 193,
        'M', 343,
        'm', 343,
        'R', 362,
        'r', 362,
        'S', 190,
        's', 190,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(44);
      END_STATE();
    case 45:
      ADVANCE_MAP(
        'A', 441,
        'a', 441,
        'E', 206,
        'e', 206,
        'I', 208,
        'i', 208,
        'L', 342,
        'l', 342,
        'O', 356,
        'o', 356,
        'Y', 622,
        'y', 622,
      );
      END_STATE();
    case 46:
      ADVANCE_MAP(
        'A', 266,
        'a', 266,
        'I', 286,
        'i', 286,
        'L', 349,
        'l', 349,
        'R', 339,
        'r', 339,
        'U', 270,
        'u', 270,
      );
      END_STATE();
    case 47:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(425);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(380);
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(227);
      END_STATE();
    case 48:
      ADVANCE_MAP(
        'A', 461,
        'a', 461,
        'E', 96,
        'e', 96,
        'I', 427,
        'i', 427,
        'O', 494,
        'o', 494,
        'R', 346,
        'r', 346,
        'U', 391,
        'u', 391,
      );
      END_STATE();
    case 49:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(298);
      END_STATE();
    case 50:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(293);
      END_STATE();
    case 51:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(91);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(87);
      END_STATE();
    case 52:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(304);
      END_STATE();
    case 53:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(392);
      END_STATE();
    case 54:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(263);
      END_STATE();
    case 55:
      ADVANCE_MAP(
        'A', 200,
        'a', 200,
        'F', 496,
        'f', 496,
        'I', 327,
        'i', 327,
        'K', 193,
        'k', 193,
        'M', 72,
        'm', 72,
        'O', 388,
        'o', 388,
        'R', 344,
        'r', 344,
        'T', 40,
        't', 40,
        'U', 435,
        'u', 435,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(55);
      END_STATE();
    case 56:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(261);
      END_STATE();
    case 57:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(445);
      END_STATE();
    case 58:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(287);
      END_STATE();
    case 59:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(385);
      END_STATE();
    case 60:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(328);
      END_STATE();
    case 61:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(213);
      END_STATE();
    case 62:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(92);
      END_STATE();
    case 63:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(274);
      END_STATE();
    case 64:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(249);
      END_STATE();
    case 65:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(89);
      END_STATE();
    case 66:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(93);
      END_STATE();
    case 67:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(467);
      END_STATE();
    case 68:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(215);
      END_STATE();
    case 69:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(469);
      END_STATE();
    case 70:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(471);
      END_STATE();
    case 71:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(472);
      END_STATE();
    case 72:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(464);
      END_STATE();
    case 73:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(476);
      END_STATE();
    case 74:
      if (lookahead == 'B' ||
          lookahead == 'b') ADVANCE(712);
      END_STATE();
    case 75:
      if (lookahead == 'B' ||
          lookahead == 'b') ADVANCE(150);
      END_STATE();
    case 76:
      if (lookahead == 'B' ||
          lookahead == 'b') ADVANCE(281);
      END_STATE();
    case 77:
      if (lookahead == 'B' ||
          lookahead == 'b') ADVANCE(283);
      END_STATE();
    case 78:
      if (lookahead == 'B' ||
          lookahead == 'b') ADVANCE(284);
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(236);
      END_STATE();
    case 79:
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(624);
      END_STATE();
    case 80:
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(702);
      END_STATE();
    case 81:
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(704);
      END_STATE();
    case 82:
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(623);
      END_STATE();
    case 83:
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(219);
      END_STATE();
    case 84:
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(222);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(331);
      END_STATE();
    case 85:
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(493);
      END_STATE();
    case 86:
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(351);
      END_STATE();
    case 87:
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(73);
      END_STATE();
    case 88:
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(451);
      END_STATE();
    case 89:
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(453);
      END_STATE();
    case 90:
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(455);
      END_STATE();
    case 91:
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(139);
      END_STATE();
    case 92:
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(141);
      END_STATE();
    case 93:
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(179);
      END_STATE();
    case 94:
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(483);
      END_STATE();
    case 95:
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(404);
      END_STATE();
    case 96:
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(242);
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(188);
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(79);
      END_STATE();
    case 97:
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(475);
      END_STATE();
    case 98:
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(70);
      END_STATE();
    case 99:
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(478);
      END_STATE();
    case 100:
      ADVANCE_MAP(
        'D', 102,
        'd', 102,
        'G', 205,
        'g', 205,
        'L', 257,
        'l', 257,
        'N', 103,
        'n', 103,
        'P', 369,
        'p', 369,
        'S', 571,
        's', 571,
        'U', 440,
        'u', 440,
      );
      END_STATE();
    case 101:
      ADVANCE_MAP(
        'D', 102,
        'd', 102,
        'L', 278,
        'l', 278,
        'N', 103,
        'n', 103,
        'P', 369,
        'p', 369,
        'S', 571,
        's', 571,
      );
      END_STATE();
    case 102:
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(769);
      END_STATE();
    case 103:
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(609);
      END_STATE();
    case 104:
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(740);
      END_STATE();
    case 105:
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(752);
      END_STATE();
    case 106:
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(631);
      END_STATE();
    case 107:
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(705);
      END_STATE();
    case 108:
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(757);
      END_STATE();
    case 109:
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(736);
      END_STATE();
    case 110:
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(632);
      END_STATE();
    case 111:
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(694);
      END_STATE();
    case 112:
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(224);
      END_STATE();
    case 113:
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(154);
      END_STATE();
    case 114:
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(163);
      END_STATE();
    case 115:
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(69);
      END_STATE();
    case 116:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(507);
      END_STATE();
    case 117:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(316);
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(275);
      END_STATE();
    case 118:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(667);
      END_STATE();
    case 119:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(667);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(315);
      END_STATE();
    case 120:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(500);
      END_STATE();
    case 121:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(716);
      END_STATE();
    case 122:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(687);
      END_STATE();
    case 123:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(735);
      END_STATE();
    case 124:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(603);
      END_STATE();
    case 125:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(603);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(98);
      END_STATE();
    case 126:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(697);
      END_STATE();
    case 127:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(703);
      END_STATE();
    case 128:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(649);
      END_STATE();
    case 129:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(748);
      END_STATE();
    case 130:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(608);
      END_STATE();
    case 131:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(651);
      END_STATE();
    case 132:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(625);
      END_STATE();
    case 133:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(720);
      END_STATE();
    case 134:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(770);
      END_STATE();
    case 135:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(670);
      END_STATE();
    case 136:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(662);
      END_STATE();
    case 137:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(35);
      END_STATE();
    case 138:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(677);
      END_STATE();
    case 139:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(701);
      END_STATE();
    case 140:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(765);
      END_STATE();
    case 141:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(680);
      END_STATE();
    case 142:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(708);
      END_STATE();
    case 143:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(648);
      END_STATE();
    case 144:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(693);
      END_STATE();
    case 145:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(675);
      END_STATE();
    case 146:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(692);
      END_STATE();
    case 147:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(317);
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(285);
      END_STATE();
    case 148:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(207);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(534);
      END_STATE();
    case 149:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(269);
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(346);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(534);
      END_STATE();
    case 150:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(676);
      END_STATE();
    case 151:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(206);
      END_STATE();
    case 152:
      ADVANCE_MAP(
        'E', 277,
        'e', 277,
        'F', 481,
        'f', 481,
        'M', 63,
        'm', 63,
        'T', 357,
        't', 357,
        'U', 372,
        'u', 372,
      );
      END_STATE();
    case 153:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(277);
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(513);
      END_STATE();
    case 154:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(504);
      END_STATE();
    case 155:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(498);
      END_STATE();
    case 156:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(67);
      END_STATE();
    case 157:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(85);
      END_STATE();
    case 158:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(85);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(429);
      END_STATE();
    case 159:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(381);
      END_STATE();
    case 160:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(406);
      END_STATE();
    case 161:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(105);
      END_STATE();
    case 162:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(512);
      END_STATE();
    case 163:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(382);
      END_STATE();
    case 164:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(414);
      END_STATE();
    case 165:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(106);
      END_STATE();
    case 166:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(303);
      END_STATE();
    case 167:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(415);
      END_STATE();
    case 168:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(217);
      END_STATE();
    case 169:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(511);
      END_STATE();
    case 170:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(408);
      END_STATE();
    case 171:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(383);
      END_STATE();
    case 172:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(110);
      END_STATE();
    case 173:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(111);
      END_STATE();
    case 174:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(384);
      END_STATE();
    case 175:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(420);
      END_STATE();
    case 176:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(386);
      END_STATE();
    case 177:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(387);
      END_STATE();
    case 178:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(421);
      END_STATE();
    case 179:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(423);
      END_STATE();
    case 180:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(430);
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(346);
      END_STATE();
    case 181:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(389);
      END_STATE();
    case 182:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(52);
      END_STATE();
    case 183:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(407);
      END_STATE();
    case 184:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(94);
      END_STATE();
    case 185:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(395);
      END_STATE();
    case 186:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(88);
      END_STATE();
    case 187:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(399);
      END_STATE();
    case 188:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(468);
      END_STATE();
    case 189:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(268);
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(346);
      END_STATE();
    case 190:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(276);
      END_STATE();
    case 191:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(410);
      END_STATE();
    case 192:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(411);
      END_STATE();
    case 193:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(515);
      END_STATE();
    case 194:
      if (lookahead == 'F' ||
          lookahead == 'f') ADVANCE(626);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(616);
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(706);
      END_STATE();
    case 195:
      if (lookahead == 'F' ||
          lookahead == 'f') ADVANCE(626);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(233);
      END_STATE();
    case 196:
      if (lookahead == 'F' ||
          lookahead == 'f') ADVANCE(691);
      END_STATE();
    case 197:
      ADVANCE_MAP(
        'F', 691,
        'f', 691,
        'N', 653,
        'n', 653,
        'P', 462,
        'p', 462,
        'R', 700,
        'r', 700,
      );
      END_STATE();
    case 198:
      if (lookahead == 'F' ||
          lookahead == 'f') ADVANCE(509);
      END_STATE();
    case 199:
      if (lookahead == 'F' ||
          lookahead == 'f') ADVANCE(491);
      END_STATE();
    case 200:
      if (lookahead == 'G' ||
          lookahead == 'g') ADVANCE(205);
      END_STATE();
    case 201:
      if (lookahead == 'G' ||
          lookahead == 'g') ADVANCE(211);
      END_STATE();
    case 202:
      if (lookahead == 'G' ||
          lookahead == 'g') ADVANCE(638);
      END_STATE();
    case 203:
      if (lookahead == 'G' ||
          lookahead == 'g') ADVANCE(567);
      END_STATE();
    case 204:
      if (lookahead == 'G' ||
          lookahead == 'g') ADVANCE(766);
      END_STATE();
    case 205:
      if (lookahead == 'G' ||
          lookahead == 'g') ADVANCE(405);
      END_STATE();
    case 206:
      if (lookahead == 'G' ||
          lookahead == 'g') ADVANCE(232);
      END_STATE();
    case 207:
      if (lookahead == 'G' ||
          lookahead == 'g') ADVANCE(232);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(531);
      END_STATE();
    case 208:
      if (lookahead == 'G' ||
          lookahead == 'g') ADVANCE(247);
      END_STATE();
    case 209:
      if (lookahead == 'G' ||
          lookahead == 'g') ADVANCE(212);
      END_STATE();
    case 210:
      if (lookahead == 'G' ||
          lookahead == 'g') ADVANCE(495);
      END_STATE();
    case 211:
      if (lookahead == 'G' ||
          lookahead == 'g') ADVANCE(165);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(302);
      END_STATE();
    case 212:
      if (lookahead == 'G' ||
          lookahead == 'g') ADVANCE(174);
      END_STATE();
    case 213:
      if (lookahead == 'G' ||
          lookahead == 'g') ADVANCE(140);
      END_STATE();
    case 214:
      if (lookahead == 'G' ||
          lookahead == 'g') ADVANCE(172);
      END_STATE();
    case 215:
      if (lookahead == 'G' ||
          lookahead == 'g') ADVANCE(142);
      END_STATE();
    case 216:
      if (lookahead == 'G' ||
          lookahead == 'g') ADVANCE(214);
      END_STATE();
    case 217:
      if (lookahead == 'G' ||
          lookahead == 'g') ADVANCE(71);
      END_STATE();
    case 218:
      if (lookahead == 'H' ||
          lookahead == 'h') ADVANCE(754);
      END_STATE();
    case 219:
      if (lookahead == 'H' ||
          lookahead == 'h') ADVANCE(635);
      END_STATE();
    case 220:
      if (lookahead == 'H' ||
          lookahead == 'h') ADVANCE(183);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(457);
      END_STATE();
    case 221:
      if (lookahead == 'H' ||
          lookahead == 'h') ADVANCE(358);
      END_STATE();
    case 222:
      if (lookahead == 'H' ||
          lookahead == 'h') ADVANCE(59);
      END_STATE();
    case 223:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(294);
      END_STATE();
    case 224:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(198);
      END_STATE();
    case 225:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(516);
      END_STATE();
    case 226:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(499);
      END_STATE();
    case 227:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(296);
      END_STATE();
    case 228:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(75);
      END_STATE();
    case 229:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(104);
      END_STATE();
    case 230:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(209);
      END_STATE();
    case 231:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(209);
      if (lookahead == 'U' ||
          lookahead == 'u') ADVANCE(125);
      END_STATE();
    case 232:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(301);
      END_STATE();
    case 233:
      ADVANCE_MAP(
        'I', 459,
        'i', 459,
        'P', 484,
        'p', 484,
        'S', 160,
        's', 160,
        'T', 340,
        't', 340,
      );
      END_STATE();
    case 234:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(109);
      END_STATE();
    case 235:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(350);
      END_STATE();
    case 236:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(352);
      END_STATE();
    case 237:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(353);
      END_STATE();
    case 238:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(355);
      END_STATE();
    case 239:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(448);
      END_STATE();
    case 240:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(167);
      END_STATE();
    case 241:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(517);
      END_STATE();
    case 242:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(299);
      END_STATE();
    case 243:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(428);
      END_STATE();
    case 244:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(335);
      END_STATE();
    case 245:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(359);
      END_STATE();
    case 246:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(321);
      END_STATE();
    case 247:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(329);
      END_STATE();
    case 248:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(58);
      END_STATE();
    case 249:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(325);
      END_STATE();
    case 250:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(322);
      END_STATE();
    case 251:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(332);
      END_STATE();
    case 252:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(333);
      END_STATE();
    case 253:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(473);
      END_STATE();
    case 254:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(360);
      END_STATE();
    case 255:
      if (lookahead == 'K' ||
          lookahead == 'k') ADVANCE(135);
      END_STATE();
    case 256:
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(257);
      if (lookahead == 'U' ||
          lookahead == 'u') ADVANCE(440);
      END_STATE();
    case 257:
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(671);
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(159);
      END_STATE();
    case 258:
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(647);
      END_STATE();
    case 259:
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(659);
      END_STATE();
    case 260:
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(575);
      END_STATE();
    case 261:
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(718);
      END_STATE();
    case 262:
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(51);
      END_STATE();
    case 263:
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(199);
      END_STATE();
    case 264:
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(278);
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(369);
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(82);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(534);
      END_STATE();
    case 265:
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(508);
      END_STATE();
    case 266:
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(432);
      END_STATE();
    case 267:
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(432);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(531);
      END_STATE();
    case 268:
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(188);
      END_STATE();
    case 269:
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(188);
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(79);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(531);
      END_STATE();
    case 270:
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(259);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(97);
      END_STATE();
    case 271:
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(485);
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(84);
      END_STATE();
    case 272:
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(363);
      END_STATE();
    case 273:
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(260);
      END_STATE();
    case 274:
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(289);
      END_STATE();
    case 275:
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(122);
      END_STATE();
    case 276:
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(186);
      END_STATE();
    case 277:
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(186);
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(663);
      END_STATE();
    case 278:
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(347);
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(159);
      END_STATE();
    case 279:
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(182);
      END_STATE();
    case 280:
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(161);
      END_STATE();
    case 281:
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(128);
      END_STATE();
    case 282:
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(129);
      END_STATE();
    case 283:
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(133);
      END_STATE();
    case 284:
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(137);
      END_STATE();
    case 285:
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(178);
      END_STATE();
    case 286:
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(477);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(54);
      END_STATE();
    case 287:
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(241);
      END_STATE();
    case 288:
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(280);
      END_STATE();
    case 289:
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(252);
      END_STATE();
    case 290:
      if (lookahead == 'M' ||
          lookahead == 'm') ADVANCE(606);
      END_STATE();
    case 291:
      if (lookahead == 'M' ||
          lookahead == 'm') ADVANCE(606);
      if (lookahead == 'Z' ||
          lookahead == 'z') ADVANCE(166);
      END_STATE();
    case 292:
      if (lookahead == 'M' ||
          lookahead == 'm') ADVANCE(370);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(463);
      if (lookahead == 'U' ||
          lookahead == 'u') ADVANCE(334);
      END_STATE();
    case 293:
      if (lookahead == 'M' ||
          lookahead == 'm') ADVANCE(366);
      END_STATE();
    case 294:
      if (lookahead == 'M' ||
          lookahead == 'm') ADVANCE(239);
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(443);
      END_STATE();
    case 295:
      if (lookahead == 'M' ||
          lookahead == 'm') ADVANCE(243);
      END_STATE();
    case 296:
      if (lookahead == 'M' ||
          lookahead == 'm') ADVANCE(53);
      END_STATE();
    case 297:
      if (lookahead == 'M' ||
          lookahead == 'm') ADVANCE(123);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(514);
      END_STATE();
    case 298:
      if (lookahead == 'M' ||
          lookahead == 'm') ADVANCE(134);
      END_STATE();
    case 299:
      if (lookahead == 'M' ||
          lookahead == 'm') ADVANCE(56);
      END_STATE();
    case 300:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(564);
      END_STATE();
    case 301:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(630);
      END_STATE();
    case 302:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(758);
      END_STATE();
    case 303:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(750);
      END_STATE();
    case 304:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(714);
      END_STATE();
    case 305:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(722);
      END_STATE();
    case 306:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(684);
      END_STATE();
    case 307:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(755);
      END_STATE();
    case 308:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(617);
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(706);
      END_STATE();
    case 309:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(210);
      END_STATE();
    case 310:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(458);
      if (lookahead == 'X' ||
          lookahead == 'x') ADVANCE(158);
      END_STATE();
    case 311:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(97);
      END_STATE();
    case 312:
      ADVANCE_MAP(
        'N', 272,
        'n', 272,
        'P', 115,
        'p', 115,
        'S', 119,
        's', 119,
        'U', 229,
        'u', 229,
      );
      END_STATE();
    case 313:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(463);
      END_STATE();
    case 314:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(80);
      END_STATE();
    case 315:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(202);
      END_STATE();
    case 316:
      ADVANCE_MAP(
        'N', 49,
        'n', 49,
        'P', 262,
        'p', 262,
        'T', 482,
        't', 482,
        'V', 341,
        'v', 341,
      );
      END_STATE();
    case 317:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(49);
      if (lookahead == 'V' ||
          lookahead == 'v') ADVANCE(341);
      END_STATE();
    case 318:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(98);
      END_STATE();
    case 319:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(107);
      END_STATE();
    case 320:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(416);
      END_STATE();
    case 321:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(203);
      END_STATE();
    case 322:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(204);
      END_STATE();
    case 323:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(81);
      END_STATE();
    case 324:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(417);
      END_STATE();
    case 325:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(418);
      END_STATE();
    case 326:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(419);
      END_STATE();
    case 327:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(113);
      END_STATE();
    case 328:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(446);
      END_STATE();
    case 329:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(449);
      END_STATE();
    case 330:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(422);
      END_STATE();
    case 331:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(452);
      END_STATE();
    case 332:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(454);
      END_STATE();
    case 333:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(456);
      END_STATE();
    case 334:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(466);
      END_STATE();
    case 335:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(90);
      END_STATE();
    case 336:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(99);
      END_STATE();
    case 337:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(396);
      if (lookahead == 'U' ||
          lookahead == 'u') ADVANCE(273);
      END_STATE();
    case 338:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(669);
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(480);
      END_STATE();
    case 339:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(291);
      END_STATE();
    case 340:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(642);
      END_STATE();
    case 341:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(255);
      END_STATE();
    case 342:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(74);
      END_STATE();
    case 343:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(112);
      END_STATE();
    case 344:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(275);
      END_STATE();
    case 345:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(300);
      END_STATE();
    case 346:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(365);
      END_STATE();
    case 347:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(501);
      END_STATE();
    case 348:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(290);
      END_STATE();
    case 349:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(57);
      END_STATE();
    case 350:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(320);
      END_STATE();
    case 351:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(319);
      END_STATE();
    case 352:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(305);
      END_STATE();
    case 353:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(306);
      END_STATE();
    case 354:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(394);
      END_STATE();
    case 355:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(307);
      END_STATE();
    case 356:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(279);
      END_STATE();
    case 357:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(397);
      if (lookahead == 'Y' ||
          lookahead == 'y') ADVANCE(374);
      END_STATE();
    case 358:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(398);
      END_STATE();
    case 359:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(326);
      END_STATE();
    case 360:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(330);
      END_STATE();
    case 361:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(313);
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(156);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(534);
      END_STATE();
    case 362:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(285);
      END_STATE();
    case 363:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(216);
      END_STATE();
    case 364:
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(746);
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(185);
      END_STATE();
    case 365:
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(661);
      END_STATE();
    case 366:
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(639);
      END_STATE();
    case 367:
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(115);
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(119);
      END_STATE();
    case 368:
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(115);
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(118);
      END_STATE();
    case 369:
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(265);
      END_STATE();
    case 370:
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(65);
      END_STATE();
    case 371:
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(62);
      END_STATE();
    case 372:
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(170);
      END_STATE();
    case 373:
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(126);
      END_STATE();
    case 374:
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(127);
      END_STATE();
    case 375:
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(282);
      END_STATE();
    case 376:
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(66);
      END_STATE();
    case 377:
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(192);
      END_STATE();
    case 378:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(60);
      END_STATE();
    case 379:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(227);
      END_STATE();
    case 380:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(295);
      END_STATE();
    case 381:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(674);
      END_STATE();
    case 382:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(621);
      END_STATE();
    case 383:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(633);
      END_STATE();
    case 384:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(696);
      END_STATE();
    case 385:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(742);
      END_STATE();
    case 386:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(759);
      END_STATE();
    case 387:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(768);
      END_STATE();
    case 388:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(699);
      END_STATE();
    case 389:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(698);
      END_STATE();
    case 390:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(156);
      END_STATE();
    case 391:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(42);
      END_STATE();
    case 392:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(510);
      END_STATE();
    case 393:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(240);
      END_STATE();
    case 394:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(108);
      END_STATE();
    case 395:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(248);
      END_STATE();
    case 396:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(184);
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(497);
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(643);
      END_STATE();
    case 397:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(61);
      END_STATE();
    case 398:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(225);
      END_STATE();
    case 399:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(246);
      END_STATE();
    case 400:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(431);
      END_STATE();
    case 401:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(114);
      END_STATE();
    case 402:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(253);
      END_STATE();
    case 403:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(348);
      if (lookahead == 'U' ||
          lookahead == 'u') ADVANCE(336);
      END_STATE();
    case 404:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(228);
      END_STATE();
    case 405:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(168);
      END_STATE();
    case 406:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(450);
      END_STATE();
    case 407:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(130);
      END_STATE();
    case 408:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(489);
      END_STATE();
    case 409:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(324);
      END_STATE();
    case 410:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(250);
      END_STATE();
    case 411:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(490);
      END_STATE();
    case 412:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(492);
      END_STATE();
    case 413:
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(628);
      END_STATE();
    case 414:
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(644);
      END_STATE();
    case 415:
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(657);
      END_STATE();
    case 416:
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(760);
      END_STATE();
    case 417:
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(707);
      END_STATE();
    case 418:
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(618);
      END_STATE();
    case 419:
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(673);
      END_STATE();
    case 420:
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(756);
      END_STATE();
    case 421:
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(683);
      END_STATE();
    case 422:
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(679);
      END_STATE();
    case 423:
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(682);
      END_STATE();
    case 424:
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(502);
      END_STATE();
    case 425:
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(424);
      END_STATE();
    case 426:
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(345);
      END_STATE();
    case 427:
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(474);
      END_STATE();
    case 428:
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(437);
      END_STATE();
    case 429:
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(460);
      END_STATE();
    case 430:
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(95);
      END_STATE();
    case 431:
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(226);
      END_STATE();
    case 432:
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(124);
      END_STATE();
    case 433:
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(176);
      END_STATE();
    case 434:
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(177);
      END_STATE();
    case 435:
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(181);
      END_STATE();
    case 436:
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(376);
      END_STATE();
    case 437:
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(245);
      END_STATE();
    case 438:
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(371);
      END_STATE();
    case 439:
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(479);
      END_STATE();
    case 440:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(221);
      END_STATE();
    case 441:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(83);
      END_STATE();
    case 442:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(726);
      END_STATE();
    case 443:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(689);
      END_STATE();
    case 444:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(732);
      END_STATE();
    case 445:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(724);
      END_STATE();
    case 446:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(668);
      END_STATE();
    case 447:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(753);
      END_STATE();
    case 448:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(568);
      END_STATE();
    case 449:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(710);
      END_STATE();
    case 450:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(641);
      END_STATE();
    case 451:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(561);
      END_STATE();
    case 452:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(744);
      END_STATE();
    case 453:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(763);
      END_STATE();
    case 454:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(738);
      END_STATE();
    case 455:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(562);
      END_STATE();
    case 456:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(730);
      END_STATE();
    case 457:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(218);
      END_STATE();
    case 458:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(393);
      END_STATE();
    case 459:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(86);
      END_STATE();
    case 460:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(413);
      END_STATE();
    case 461:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(121);
      END_STATE();
    case 462:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(235);
      END_STATE();
    case 463:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(64);
      END_STATE();
    case 464:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(185);
      END_STATE();
    case 465:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(50);
      END_STATE();
    case 466:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(171);
      END_STATE();
    case 467:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(131);
      END_STATE();
    case 468:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(132);
      END_STATE();
    case 469:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(136);
      END_STATE();
    case 470:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(138);
      END_STATE();
    case 471:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(143);
      END_STATE();
    case 472:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(144);
      END_STATE();
    case 473:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(175);
      END_STATE();
    case 474:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(244);
      END_STATE();
    case 475:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(237);
      END_STATE();
    case 476:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(238);
      END_STATE();
    case 477:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(187);
      END_STATE();
    case 478:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(254);
      END_STATE();
    case 479:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(191);
      END_STATE();
    case 480:
      if (lookahead == 'U' ||
          lookahead == 'u') ADVANCE(125);
      END_STATE();
    case 481:
      if (lookahead == 'U' ||
          lookahead == 'u') ADVANCE(314);
      END_STATE();
    case 482:
      if (lookahead == 'U' ||
          lookahead == 'u') ADVANCE(409);
      END_STATE();
    case 483:
      if (lookahead == 'U' ||
          lookahead == 'u') ADVANCE(400);
      END_STATE();
    case 484:
      if (lookahead == 'U' ||
          lookahead == 'u') ADVANCE(447);
      END_STATE();
    case 485:
      if (lookahead == 'U' ||
          lookahead == 'u') ADVANCE(164);
      END_STATE();
    case 486:
      if (lookahead == 'U' ||
          lookahead == 'u') ADVANCE(273);
      END_STATE();
    case 487:
      if (lookahead == 'U' ||
          lookahead == 'u') ADVANCE(439);
      END_STATE();
    case 488:
      if (lookahead == 'U' ||
          lookahead == 'u') ADVANCE(234);
      END_STATE();
    case 489:
      if (lookahead == 'U' ||
          lookahead == 'u') ADVANCE(433);
      END_STATE();
    case 490:
      if (lookahead == 'U' ||
          lookahead == 'u') ADVANCE(434);
      END_STATE();
    case 491:
      if (lookahead == 'U' ||
          lookahead == 'u') ADVANCE(323);
      END_STATE();
    case 492:
      if (lookahead == 'U' ||
          lookahead == 'u') ADVANCE(318);
      END_STATE();
    case 493:
      if (lookahead == 'U' ||
          lookahead == 'u') ADVANCE(470);
      END_STATE();
    case 494:
      if (lookahead == 'U' ||
          lookahead == 'u') ADVANCE(77);
      END_STATE();
    case 495:
      if (lookahead == 'U' ||
          lookahead == 'u') ADVANCE(68);
      END_STATE();
    case 496:
      if (lookahead == 'U' ||
          lookahead == 'u') ADVANCE(311);
      END_STATE();
    case 497:
      if (lookahead == 'U' ||
          lookahead == 'u') ADVANCE(377);
      END_STATE();
    case 498:
      if (lookahead == 'V' ||
          lookahead == 'v') ADVANCE(341);
      END_STATE();
    case 499:
      if (lookahead == 'V' ||
          lookahead == 'v') ADVANCE(146);
      END_STATE();
    case 500:
      if (lookahead == 'W' ||
          lookahead == 'w') ADVANCE(695);
      END_STATE();
    case 501:
      if (lookahead == 'W' ||
          lookahead == 'w') ADVANCE(566);
      END_STATE();
    case 502:
      if (lookahead == 'W' ||
          lookahead == 'w') ADVANCE(354);
      END_STATE();
    case 503:
      if (lookahead == 'W' ||
          lookahead == 'w') ADVANCE(402);
      END_STATE();
    case 504:
      if (lookahead == 'X' ||
          lookahead == 'x') ADVANCE(652);
      END_STATE();
    case 505:
      if (lookahead == 'X' ||
          lookahead == 'x') ADVANCE(444);
      END_STATE();
    case 506:
      if (lookahead == 'X' ||
          lookahead == 'x') ADVANCE(157);
      END_STATE();
    case 507:
      if (lookahead == 'Y' ||
          lookahead == 'y') ADVANCE(620);
      END_STATE();
    case 508:
      if (lookahead == 'Y' ||
          lookahead == 'y') ADVANCE(771);
      END_STATE();
    case 509:
      if (lookahead == 'Y' ||
          lookahead == 'y') ADVANCE(678);
      END_STATE();
    case 510:
      if (lookahead == 'Y' ||
          lookahead == 'y') ADVANCE(761);
      END_STATE();
    case 511:
      if (lookahead == 'Y' ||
          lookahead == 'y') ADVANCE(619);
      END_STATE();
    case 512:
      if (lookahead == 'Y' ||
          lookahead == 'y') ADVANCE(436);
      END_STATE();
    case 513:
      if (lookahead == 'Y' ||
          lookahead == 'y') ADVANCE(374);
      END_STATE();
    case 514:
      if (lookahead == 'Y' ||
          lookahead == 'y') ADVANCE(251);
      END_STATE();
    case 515:
      if (lookahead == 'Y' ||
          lookahead == 'y') ADVANCE(438);
      END_STATE();
    case 516:
      if (lookahead == 'Z' ||
          lookahead == 'z') ADVANCE(145);
      END_STATE();
    case 517:
      if (lookahead == 'Z' ||
          lookahead == 'z') ADVANCE(173);
      END_STATE();
    case 518:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(586);
      END_STATE();
    case 519:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(601);
      END_STATE();
    case 520:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(594);
      END_STATE();
    case 521:
      if (lookahead == '+' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(595);
      END_STATE();
    case 522:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(574);
      END_STATE();
    case 523:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(33);
      END_STATE();
    case 524:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(577);
      END_STATE();
    case 525:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(523);
      END_STATE();
    case 526:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(524);
      END_STATE();
    case 527:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(525);
      END_STATE();
    case 528:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(526);
      END_STATE();
    case 529:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(527);
      END_STATE();
    case 530:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(528);
      END_STATE();
    case 531:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(529);
      END_STATE();
    case 532:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(530);
      END_STATE();
    case 533:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(32);
      END_STATE();
    case 534:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(531);
      END_STATE();
    case 535:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(533);
      END_STATE();
    case 536:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(535);
      END_STATE();
    case 537:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(536);
      END_STATE();
    case 538:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(532);
      END_STATE();
    case 539:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(30);
      END_STATE();
    case 540:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(534);
      END_STATE();
    case 541:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(539);
      END_STATE();
    case 542:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(541);
      END_STATE();
    case 543:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(542);
      END_STATE();
    case 544:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(538);
      END_STATE();
    case 545:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(31);
      END_STATE();
    case 546:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(545);
      END_STATE();
    case 547:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(546);
      END_STATE();
    case 548:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(547);
      END_STATE();
    case 549:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(544);
      END_STATE();
    case 550:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(549);
      END_STATE();
    case 551:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(550);
      END_STATE();
    case 552:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(551);
      END_STATE();
    case 553:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(552);
      END_STATE();
    case 554:
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(17);
      END_STATE();
    case 555:
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(28);
      END_STATE();
    case 556:
      if (lookahead != 0 &&
          lookahead != '$') ADVANCE(21);
      END_STATE();
    case 557:
      if (eof) ADVANCE(559);
      ADVANCE_MAP(
        '$', 18,
        '\'', 23,
        '(', 572,
        ')', 573,
        ',', 570,
        '-', 518,
        '0', 585,
        ':', 579,
        ';', 560,
        '<', 610,
        '=', 613,
        '>', 614,
        '?', 578,
        '[', 636,
        '{', 645,
        '}', 646,
        'A', 264,
        'a', 264,
        'B', 148,
        'b', 148,
        'C', 361,
        'c', 361,
        'D', 149,
        'd', 149,
        'E', 540,
        'e', 540,
        'F', 43,
        'f', 43,
        'G', 378,
        'g', 378,
        'I', 308,
        'i', 308,
        'K', 169,
        'k', 169,
        'L', 223,
        'l', 223,
        'N', 486,
        'n', 486,
        'O', 196,
        'o', 196,
        'R', 155,
        'r', 155,
        'S', 190,
        's', 190,
        'T', 338,
        't', 338,
        'U', 368,
        'u', 368,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(557);
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(593);
      END_STATE();
    case 558:
      if (eof) ADVANCE(559);
      ADVANCE_MAP(
        '\'', 25,
        '(', 572,
        ')', 573,
        ',', 570,
        '-', 520,
        '.', 686,
        ':', 579,
        ';', 560,
        '<', 610,
        '=', 613,
        '>', 614,
        ']', 637,
        '}', 646,
        'A', 101,
        'a', 101,
        'B', 151,
        'b', 151,
        'C', 390,
        'c', 390,
        'D', 189,
        'd', 189,
        'F', 403,
        'f', 403,
        'G', 378,
        'g', 378,
        'I', 195,
        'i', 195,
        'K', 162,
        'k', 162,
        'L', 223,
        'l', 223,
        'O', 401,
        'o', 401,
        'P', 379,
        'p', 379,
        'R', 147,
        'r', 147,
        'S', 153,
        's', 153,
        'T', 412,
        't', 412,
        'U', 367,
        'u', 367,
        'W', 220,
        'w', 220,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(558);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(594);
      END_STATE();
    case 559:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 560:
      ACCEPT_TOKEN(anon_sym_SEMI);
      END_STATE();
    case 561:
      ACCEPT_TOKEN(aux_sym_select_statement_token1);
      END_STATE();
    case 562:
      ACCEPT_TOKEN(aux_sym_select_statement_token2);
      END_STATE();
    case 563:
      ACCEPT_TOKEN(aux_sym_select_statement_token2);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 564:
      ACCEPT_TOKEN(aux_sym_select_statement_token3);
      END_STATE();
    case 565:
      ACCEPT_TOKEN(aux_sym_select_statement_token3);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 566:
      ACCEPT_TOKEN(aux_sym_select_statement_token4);
      END_STATE();
    case 567:
      ACCEPT_TOKEN(aux_sym_select_statement_token5);
      END_STATE();
    case 568:
      ACCEPT_TOKEN(aux_sym_limit_spec_token1);
      END_STATE();
    case 569:
      ACCEPT_TOKEN(anon_sym_STAR);
      END_STATE();
    case 570:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 571:
      ACCEPT_TOKEN(aux_sym_select_element_token1);
      END_STATE();
    case 572:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 573:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 574:
      ACCEPT_TOKEN(aux_sym_constant_token1);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(574);
      END_STATE();
    case 575:
      ACCEPT_TOKEN(aux_sym_constant_token2);
      END_STATE();
    case 576:
      ACCEPT_TOKEN(aux_sym_constant_token2);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 577:
      ACCEPT_TOKEN(aux_sym_constant_token3);
      END_STATE();
    case 578:
      ACCEPT_TOKEN(anon_sym_QMARK);
      END_STATE();
    case 579:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 580:
      ACCEPT_TOKEN(sym__string_literal);
      if (lookahead == '\'') ADVANCE(25);
      END_STATE();
    case 581:
      ACCEPT_TOKEN(sym__string_literal);
      if (lookahead == '\'') ADVANCE(25);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(29);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(600);
      END_STATE();
    case 582:
      ACCEPT_TOKEN(sym__string_literal);
      if (lookahead == '\'') ADVANCE(25);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(599);
      END_STATE();
    case 583:
      ACCEPT_TOKEN(sym__string_literal);
      if (lookahead == '\'') ADVANCE(27);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(28);
      END_STATE();
    case 584:
      ACCEPT_TOKEN(aux_sym__decimal_literal_token1);
      if (lookahead == '-') ADVANCE(548);
      if (lookahead == '.') ADVANCE(519);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(586);
      END_STATE();
    case 585:
      ACCEPT_TOKEN(aux_sym__decimal_literal_token1);
      if (lookahead == '.') ADVANCE(519);
      if (lookahead == 'X') ADVANCE(522);
      if (lookahead == 'x') ADVANCE(522);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(592);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(534);
      END_STATE();
    case 586:
      ACCEPT_TOKEN(aux_sym__decimal_literal_token1);
      if (lookahead == '.') ADVANCE(519);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(586);
      END_STATE();
    case 587:
      ACCEPT_TOKEN(aux_sym__decimal_literal_token1);
      if (lookahead == '.') ADVANCE(519);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(584);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(33);
      END_STATE();
    case 588:
      ACCEPT_TOKEN(aux_sym__decimal_literal_token1);
      if (lookahead == '.') ADVANCE(519);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(587);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(523);
      END_STATE();
    case 589:
      ACCEPT_TOKEN(aux_sym__decimal_literal_token1);
      if (lookahead == '.') ADVANCE(519);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(588);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(525);
      END_STATE();
    case 590:
      ACCEPT_TOKEN(aux_sym__decimal_literal_token1);
      if (lookahead == '.') ADVANCE(519);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(589);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(527);
      END_STATE();
    case 591:
      ACCEPT_TOKEN(aux_sym__decimal_literal_token1);
      if (lookahead == '.') ADVANCE(519);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(590);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(529);
      END_STATE();
    case 592:
      ACCEPT_TOKEN(aux_sym__decimal_literal_token1);
      if (lookahead == '.') ADVANCE(519);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(591);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(531);
      END_STATE();
    case 593:
      ACCEPT_TOKEN(aux_sym__decimal_literal_token1);
      if (lookahead == '.') ADVANCE(519);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(592);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(534);
      END_STATE();
    case 594:
      ACCEPT_TOKEN(aux_sym__decimal_literal_token1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(594);
      END_STATE();
    case 595:
      ACCEPT_TOKEN(sym__float_literal);
      END_STATE();
    case 596:
      ACCEPT_TOKEN(sym__float_literal);
      if (lookahead == '\'') ADVANCE(580);
      if (lookahead == '+' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(597);
      if (lookahead != 0) ADVANCE(25);
      END_STATE();
    case 597:
      ACCEPT_TOKEN(sym__float_literal);
      if (lookahead == '\'') ADVANCE(580);
      if (lookahead != 0) ADVANCE(25);
      END_STATE();
    case 598:
      ACCEPT_TOKEN(sym__float_literal);
      if (lookahead == '\'') ADVANCE(583);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(22);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(598);
      if (lookahead != 0) ADVANCE(25);
      END_STATE();
    case 599:
      ACCEPT_TOKEN(sym__float_literal);
      if (lookahead == '\'') ADVANCE(555);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(29);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(599);
      END_STATE();
    case 600:
      ACCEPT_TOKEN(sym__float_literal);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(29);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(600);
      END_STATE();
    case 601:
      ACCEPT_TOKEN(sym__float_literal);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(601);
      END_STATE();
    case 602:
      ACCEPT_TOKEN(sym__float_literal);
      if (lookahead == '+' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(595);
      END_STATE();
    case 603:
      ACCEPT_TOKEN(sym__boolean_literal);
      END_STATE();
    case 604:
      ACCEPT_TOKEN(sym__boolean_literal);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 605:
      ACCEPT_TOKEN(sym__code_block);
      END_STATE();
    case 606:
      ACCEPT_TOKEN(aux_sym_from_spec_token1);
      END_STATE();
    case 607:
      ACCEPT_TOKEN(aux_sym_from_spec_token1);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 608:
      ACCEPT_TOKEN(aux_sym_where_spec_token1);
      END_STATE();
    case 609:
      ACCEPT_TOKEN(aux_sym_relation_elements_token1);
      END_STATE();
    case 610:
      ACCEPT_TOKEN(anon_sym_LT);
      if (lookahead == '=') ADVANCE(611);
      if (lookahead == '>') ADVANCE(612);
      END_STATE();
    case 611:
      ACCEPT_TOKEN(anon_sym_LT_EQ);
      END_STATE();
    case 612:
      ACCEPT_TOKEN(anon_sym_LT_GT);
      END_STATE();
    case 613:
      ACCEPT_TOKEN(anon_sym_EQ);
      END_STATE();
    case 614:
      ACCEPT_TOKEN(anon_sym_GT);
      if (lookahead == '=') ADVANCE(615);
      END_STATE();
    case 615:
      ACCEPT_TOKEN(anon_sym_GT_EQ);
      END_STATE();
    case 616:
      ACCEPT_TOKEN(aux_sym_relation_element_token1);
      ADVANCE_MAP(
        'D', 154,
        'd', 154,
        'E', 442,
        'e', 442,
        'I', 459,
        'i', 459,
        'P', 484,
        'p', 484,
        'S', 160,
        's', 160,
        'T', 728,
        't', 728,
      );
      END_STATE();
    case 617:
      ACCEPT_TOKEN(aux_sym_relation_element_token1);
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(160);
      END_STATE();
    case 618:
      ACCEPT_TOKEN(aux_sym_relation_contains_key_token1);
      END_STATE();
    case 619:
      ACCEPT_TOKEN(aux_sym_relation_contains_key_token2);
      END_STATE();
    case 620:
      ACCEPT_TOKEN(aux_sym_relation_contains_key_token2);
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(655);
      END_STATE();
    case 621:
      ACCEPT_TOKEN(aux_sym_order_spec_token1);
      END_STATE();
    case 622:
      ACCEPT_TOKEN(aux_sym_order_spec_token2);
      END_STATE();
    case 623:
      ACCEPT_TOKEN(aux_sym_order_spec_token3);
      END_STATE();
    case 624:
      ACCEPT_TOKEN(aux_sym_order_spec_token4);
      END_STATE();
    case 625:
      ACCEPT_TOKEN(aux_sym_delete_statement_token1);
      END_STATE();
    case 626:
      ACCEPT_TOKEN(aux_sym_delete_statement_token2);
      END_STATE();
    case 627:
      ACCEPT_TOKEN(aux_sym_delete_statement_token2);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 628:
      ACCEPT_TOKEN(aux_sym_delete_statement_token3);
      END_STATE();
    case 629:
      ACCEPT_TOKEN(aux_sym_delete_statement_token3);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 630:
      ACCEPT_TOKEN(aux_sym_begin_batch_token1);
      END_STATE();
    case 631:
      ACCEPT_TOKEN(aux_sym_begin_batch_token2);
      END_STATE();
    case 632:
      ACCEPT_TOKEN(aux_sym_begin_batch_token3);
      END_STATE();
    case 633:
      ACCEPT_TOKEN(aux_sym_begin_batch_token4);
      END_STATE();
    case 634:
      ACCEPT_TOKEN(aux_sym_begin_batch_token4);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 635:
      ACCEPT_TOKEN(aux_sym_begin_batch_token5);
      END_STATE();
    case 636:
      ACCEPT_TOKEN(anon_sym_LBRACK);
      END_STATE();
    case 637:
      ACCEPT_TOKEN(anon_sym_RBRACK);
      END_STATE();
    case 638:
      ACCEPT_TOKEN(aux_sym_using_timestamp_spec_token1);
      END_STATE();
    case 639:
      ACCEPT_TOKEN(aux_sym_using_timestamp_spec_token2);
      END_STATE();
    case 640:
      ACCEPT_TOKEN(aux_sym_using_timestamp_spec_token2);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 641:
      ACCEPT_TOKEN(aux_sym_insert_statement_token1);
      END_STATE();
    case 642:
      ACCEPT_TOKEN(aux_sym_insert_statement_token2);
      END_STATE();
    case 643:
      ACCEPT_TOKEN(aux_sym_insert_statement_token3);
      END_STATE();
    case 644:
      ACCEPT_TOKEN(aux_sym_insert_values_spec_token1);
      END_STATE();
    case 645:
      ACCEPT_TOKEN(anon_sym_LBRACE);
      END_STATE();
    case 646:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    case 647:
      ACCEPT_TOKEN(aux_sym_using_ttl_timestamp_token1);
      END_STATE();
    case 648:
      ACCEPT_TOKEN(aux_sym_truncate_token1);
      END_STATE();
    case 649:
      ACCEPT_TOKEN(aux_sym_truncate_token2);
      END_STATE();
    case 650:
      ACCEPT_TOKEN(aux_sym_truncate_token2);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 651:
      ACCEPT_TOKEN(aux_sym_create_index_token1);
      END_STATE();
    case 652:
      ACCEPT_TOKEN(aux_sym_create_index_token2);
      END_STATE();
    case 653:
      ACCEPT_TOKEN(aux_sym_create_index_token3);
      END_STATE();
    case 654:
      ACCEPT_TOKEN(aux_sym_create_index_token3);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 655:
      ACCEPT_TOKEN(aux_sym_index_keys_spec_token1);
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(62);
      END_STATE();
    case 656:
      ACCEPT_TOKEN(aux_sym_index_keys_spec_token1);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 657:
      ACCEPT_TOKEN(aux_sym_index_entries_s_spec_token1);
      END_STATE();
    case 658:
      ACCEPT_TOKEN(aux_sym_index_entries_s_spec_token1);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 659:
      ACCEPT_TOKEN(aux_sym_index_full_spec_token1);
      END_STATE();
    case 660:
      ACCEPT_TOKEN(aux_sym_index_full_spec_token1);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 661:
      ACCEPT_TOKEN(aux_sym_drop_index_token1);
      END_STATE();
    case 662:
      ACCEPT_TOKEN(aux_sym_update_token1);
      END_STATE();
    case 663:
      ACCEPT_TOKEN(aux_sym_update_assignments_token1);
      END_STATE();
    case 664:
      ACCEPT_TOKEN(aux_sym_update_assignments_token1);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 665:
      ACCEPT_TOKEN(anon_sym_PLUS);
      END_STATE();
    case 666:
      ACCEPT_TOKEN(anon_sym_DASH);
      END_STATE();
    case 667:
      ACCEPT_TOKEN(aux_sym_use_token1);
      END_STATE();
    case 668:
      ACCEPT_TOKEN(aux_sym_grant_token1);
      END_STATE();
    case 669:
      ACCEPT_TOKEN(aux_sym_grant_token2);
      END_STATE();
    case 670:
      ACCEPT_TOKEN(aux_sym_revoke_token1);
      END_STATE();
    case 671:
      ACCEPT_TOKEN(aux_sym_privilege_token1);
      END_STATE();
    case 672:
      ACCEPT_TOKEN(aux_sym_privilege_token1);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 673:
      ACCEPT_TOKEN(aux_sym_privilege_token2);
      END_STATE();
    case 674:
      ACCEPT_TOKEN(aux_sym_privilege_token3);
      END_STATE();
    case 675:
      ACCEPT_TOKEN(aux_sym_privilege_token4);
      END_STATE();
    case 676:
      ACCEPT_TOKEN(aux_sym_privilege_token5);
      END_STATE();
    case 677:
      ACCEPT_TOKEN(aux_sym_privilege_token6);
      END_STATE();
    case 678:
      ACCEPT_TOKEN(aux_sym_privilege_token7);
      END_STATE();
    case 679:
      ACCEPT_TOKEN(aux_sym_resource_token1);
      END_STATE();
    case 680:
      ACCEPT_TOKEN(aux_sym_resource_token2);
      END_STATE();
    case 681:
      ACCEPT_TOKEN(aux_sym_resource_token2);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 682:
      ACCEPT_TOKEN(aux_sym_resource_token3);
      END_STATE();
    case 683:
      ACCEPT_TOKEN(aux_sym_resource_token4);
      END_STATE();
    case 684:
      ACCEPT_TOKEN(aux_sym_resource_token5);
      END_STATE();
    case 685:
      ACCEPT_TOKEN(aux_sym_resource_token5);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 686:
      ACCEPT_TOKEN(anon_sym_DOT);
      END_STATE();
    case 687:
      ACCEPT_TOKEN(aux_sym_resource_token6);
      END_STATE();
    case 688:
      ACCEPT_TOKEN(aux_sym_resource_token6);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 689:
      ACCEPT_TOKEN(aux_sym_list_roles_token1);
      END_STATE();
    case 690:
      ACCEPT_TOKEN(aux_sym_list_roles_token1);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 691:
      ACCEPT_TOKEN(aux_sym_list_roles_token2);
      END_STATE();
    case 692:
      ACCEPT_TOKEN(aux_sym_list_roles_token3);
      END_STATE();
    case 693:
      ACCEPT_TOKEN(aux_sym_drop_aggregate_token1);
      END_STATE();
    case 694:
      ACCEPT_TOKEN(aux_sym_drop_materialized_view_token1);
      END_STATE();
    case 695:
      ACCEPT_TOKEN(aux_sym_drop_materialized_view_token2);
      END_STATE();
    case 696:
      ACCEPT_TOKEN(aux_sym_drop_trigger_token1);
      END_STATE();
    case 697:
      ACCEPT_TOKEN(aux_sym_drop_type_token1);
      END_STATE();
    case 698:
      ACCEPT_TOKEN(aux_sym_drop_user_token1);
      END_STATE();
    case 699:
      ACCEPT_TOKEN(aux_sym_create_aggregate_token1);
      END_STATE();
    case 700:
      ACCEPT_TOKEN(aux_sym_create_aggregate_token1);
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(163);
      END_STATE();
    case 701:
      ACCEPT_TOKEN(aux_sym_create_aggregate_token2);
      END_STATE();
    case 702:
      ACCEPT_TOKEN(aux_sym_create_aggregate_token3);
      END_STATE();
    case 703:
      ACCEPT_TOKEN(aux_sym_create_aggregate_token4);
      END_STATE();
    case 704:
      ACCEPT_TOKEN(aux_sym_create_aggregate_token5);
      END_STATE();
    case 705:
      ACCEPT_TOKEN(aux_sym_create_aggregate_token6);
      END_STATE();
    case 706:
      ACCEPT_TOKEN(aux_sym_column_not_null_token1);
      END_STATE();
    case 707:
      ACCEPT_TOKEN(aux_sym_create_function_token1);
      END_STATE();
    case 708:
      ACCEPT_TOKEN(aux_sym_create_function_token2);
      END_STATE();
    case 709:
      ACCEPT_TOKEN(aux_sym_native_type_token1);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 710:
      ACCEPT_TOKEN(aux_sym_native_type_token2);
      END_STATE();
    case 711:
      ACCEPT_TOKEN(aux_sym_native_type_token2);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 712:
      ACCEPT_TOKEN(aux_sym_native_type_token3);
      END_STATE();
    case 713:
      ACCEPT_TOKEN(aux_sym_native_type_token3);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 714:
      ACCEPT_TOKEN(aux_sym_native_type_token4);
      END_STATE();
    case 715:
      ACCEPT_TOKEN(aux_sym_native_type_token4);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 716:
      ACCEPT_TOKEN(aux_sym_native_type_token5);
      END_STATE();
    case 717:
      ACCEPT_TOKEN(aux_sym_native_type_token5);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 718:
      ACCEPT_TOKEN(aux_sym_native_type_token6);
      END_STATE();
    case 719:
      ACCEPT_TOKEN(aux_sym_native_type_token6);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 720:
      ACCEPT_TOKEN(aux_sym_native_type_token7);
      END_STATE();
    case 721:
      ACCEPT_TOKEN(aux_sym_native_type_token7);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 722:
      ACCEPT_TOKEN(aux_sym_native_type_token8);
      END_STATE();
    case 723:
      ACCEPT_TOKEN(aux_sym_native_type_token8);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 724:
      ACCEPT_TOKEN(aux_sym_native_type_token9);
      END_STATE();
    case 725:
      ACCEPT_TOKEN(aux_sym_native_type_token9);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 726:
      ACCEPT_TOKEN(aux_sym_native_type_token10);
      END_STATE();
    case 727:
      ACCEPT_TOKEN(aux_sym_native_type_token10);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 728:
      ACCEPT_TOKEN(aux_sym_native_type_token11);
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(642);
      END_STATE();
    case 729:
      ACCEPT_TOKEN(aux_sym_native_type_token11);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 730:
      ACCEPT_TOKEN(aux_sym_native_type_token12);
      END_STATE();
    case 731:
      ACCEPT_TOKEN(aux_sym_native_type_token12);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 732:
      ACCEPT_TOKEN(aux_sym_native_type_token13);
      END_STATE();
    case 733:
      ACCEPT_TOKEN(aux_sym_native_type_token13);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 734:
      ACCEPT_TOKEN(aux_sym_native_type_token14);
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(933);
      if (lookahead == 'U' ||
          lookahead == 'u') ADVANCE(942);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 735:
      ACCEPT_TOKEN(aux_sym_native_type_token14);
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(465);
      if (lookahead == 'U' ||
          lookahead == 'u') ADVANCE(488);
      END_STATE();
    case 736:
      ACCEPT_TOKEN(aux_sym_native_type_token15);
      END_STATE();
    case 737:
      ACCEPT_TOKEN(aux_sym_native_type_token15);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 738:
      ACCEPT_TOKEN(aux_sym_native_type_token16);
      END_STATE();
    case 739:
      ACCEPT_TOKEN(aux_sym_native_type_token16);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 740:
      ACCEPT_TOKEN(aux_sym_native_type_token17);
      END_STATE();
    case 741:
      ACCEPT_TOKEN(aux_sym_native_type_token17);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 742:
      ACCEPT_TOKEN(aux_sym_native_type_token18);
      END_STATE();
    case 743:
      ACCEPT_TOKEN(aux_sym_native_type_token18);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 744:
      ACCEPT_TOKEN(aux_sym_native_type_token19);
      END_STATE();
    case 745:
      ACCEPT_TOKEN(aux_sym_native_type_token19);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 746:
      ACCEPT_TOKEN(aux_sym_collection_type_token1);
      END_STATE();
    case 747:
      ACCEPT_TOKEN(aux_sym_collection_type_token1);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 748:
      ACCEPT_TOKEN(aux_sym_tuple_type_token1);
      END_STATE();
    case 749:
      ACCEPT_TOKEN(aux_sym_tuple_type_token1);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 750:
      ACCEPT_TOKEN(aux_sym_frozen_type_token1);
      END_STATE();
    case 751:
      ACCEPT_TOKEN(aux_sym_frozen_type_token1);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 752:
      ACCEPT_TOKEN(aux_sym_return_mode_token1);
      END_STATE();
    case 753:
      ACCEPT_TOKEN(aux_sym_return_mode_token2);
      END_STATE();
    case 754:
      ACCEPT_TOKEN(aux_sym_create_keyspace_token1);
      END_STATE();
    case 755:
      ACCEPT_TOKEN(aux_sym_create_keyspace_token2);
      END_STATE();
    case 756:
      ACCEPT_TOKEN(aux_sym_durable_writes_token1);
      END_STATE();
    case 757:
      ACCEPT_TOKEN(aux_sym_role_with_option_token1);
      END_STATE();
    case 758:
      ACCEPT_TOKEN(aux_sym_role_with_option_token2);
      END_STATE();
    case 759:
      ACCEPT_TOKEN(aux_sym_role_with_option_token3);
      END_STATE();
    case 760:
      ACCEPT_TOKEN(aux_sym_role_with_option_token4);
      END_STATE();
    case 761:
      ACCEPT_TOKEN(aux_sym_primary_key_column_token1);
      END_STATE();
    case 762:
      ACCEPT_TOKEN(aux_sym_primary_key_column_token1);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 763:
      ACCEPT_TOKEN(aux_sym_compact_storage_token1);
      END_STATE();
    case 764:
      ACCEPT_TOKEN(aux_sym_compact_storage_token1);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 765:
      ACCEPT_TOKEN(aux_sym_compact_storage_token2);
      END_STATE();
    case 766:
      ACCEPT_TOKEN(aux_sym_clustering_order_token1);
      END_STATE();
    case 767:
      ACCEPT_TOKEN(aux_sym_clustering_order_token1);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 768:
      ACCEPT_TOKEN(aux_sym_user_super_user_token1);
      END_STATE();
    case 769:
      ACCEPT_TOKEN(aux_sym_alter_table_add_token1);
      END_STATE();
    case 770:
      ACCEPT_TOKEN(aux_sym_alter_table_rename_token1);
      END_STATE();
    case 771:
      ACCEPT_TOKEN(aux_sym_apply_batch_token1);
      END_STATE();
    case 772:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == '"') ADVANCE(17);
      END_STATE();
    case 773:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == '-') ADVANCE(548);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 774:
      ACCEPT_TOKEN(sym_object_name);
      ADVANCE_MAP(
        'A', 917,
        'a', 917,
        'E', 794,
        'e', 794,
        'O', 939,
        'o', 939,
        'U', 900,
        'u', 900,
      );
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('B' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 775:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(891);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('B' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 776:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(845);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('B' <= lookahead && lookahead <= 'F') ||
          ('b' <= lookahead && lookahead <= 'f')) ADVANCE(958);
      if (lookahead == '$' ||
          ('G' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('g' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 777:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(796);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('B' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 778:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(896);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('B' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 779:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(846);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('B' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 780:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(860);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('B' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 781:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(795);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('B' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 782:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(898);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('B' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 783:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(841);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('B' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 784:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(866);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('B' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 785:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(932);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('B' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 786:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(922);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('B' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 787:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(899);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('B' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 788:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(791);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('B' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 789:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'B' ||
          lookahead == 'b') ADVANCE(713);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 790:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'B' ||
          lookahead == 'b') ADVANCE(854);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 791:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'B' ||
          lookahead == 'b') ADVANCE(856);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 792:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(822);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(873);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 793:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(831);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 794:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(825);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 795:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(809);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 796:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(927);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 797:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(928);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 798:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(936);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 799:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(741);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 800:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(737);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 801:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(946);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(859);
      if (lookahead == 'U' ||
          lookahead == 'u') ADVANCE(895);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 802:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(717);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 803:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(734);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 804:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(749);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 805:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(721);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 806:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(604);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 807:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(688);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 808:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(650);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 809:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(681);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 810:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(918);
      if (lookahead == 'M' ||
          lookahead == 'm') ADVANCE(779);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 811:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(949);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 812:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(919);
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(729);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 813:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(897);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 814:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(865);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 815:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(784);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 816:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(909);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 817:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(950);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 818:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(904);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 819:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'F' ||
          lookahead == 'f') ADVANCE(627);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 820:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'G' ||
          lookahead == 'g') ADVANCE(767);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 821:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'G' ||
          lookahead == 'g') ADVANCE(829);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 822:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'H' ||
          lookahead == 'h') ADVANCE(782);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 823:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(821);
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(880);
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(881);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 824:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(799);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 825:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(862);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 826:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(709);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 827:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(910);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 828:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(800);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 829:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(872);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 830:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(885);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 831:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(826);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 832:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(871);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 833:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(816);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 834:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(863);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 835:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(912);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 836:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(886);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 837:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(914);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 838:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(874);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 839:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(875);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 840:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(879);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 841:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(719);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 842:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(576);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 843:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(660);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 844:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(672);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 845:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(911);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(957);
      if (lookahead == '$' ||
          ('G' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('g' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 846:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(857);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 847:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(815);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 848:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(889);
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(882);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 849:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(842);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 850:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(804);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 851:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(940);
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(861);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 852:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(843);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 853:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(844);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 854:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(805);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 855:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(807);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 856:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(808);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 857:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(839);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 858:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'M' ||
          lookahead == 'm') ADVANCE(607);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 859:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'M' ||
          lookahead == 'm') ADVANCE(803);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(951);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 860:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'M' ||
          lookahead == 'm') ADVANCE(892);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 861:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'M' ||
          lookahead == 'm') ADVANCE(893);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 862:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'M' ||
          lookahead == 'm') ADVANCE(783);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 863:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'M' ||
          lookahead == 'm') ADVANCE(787);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 864:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(812);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 865:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(751);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 866:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(715);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 867:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(723);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 868:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(685);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 869:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(565);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 870:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(654);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 871:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(820);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 872:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(923);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 873:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(924);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 874:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(925);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 875:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(926);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 876:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(930);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 877:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(931);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 878:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(798);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 879:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(797);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 880:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(789);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 881:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(847);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 882:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(952);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 883:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(937);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 884:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(858);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 885:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(867);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 886:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(868);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 887:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(869);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 888:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(861);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 889:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(786);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 890:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(855);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 891:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(747);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 892:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(640);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 893:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(777);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 894:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(781);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 895:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(850);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 896:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(792);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 897:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(634);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 898:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(743);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 899:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(948);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 900:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(785);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 901:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(943);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 902:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(884);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 903:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(833);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 904:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(832);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 905:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(834);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 906:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(793);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 907:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(629);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 908:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(656);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 909:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(658);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 910:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(920);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 911:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(806);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 912:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(929);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 913:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(894);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 914:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(934);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 915:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(935);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 916:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(887);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 917:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(802);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 918:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(664);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 919:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(727);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 920:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(690);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 921:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(733);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 922:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(725);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 923:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(711);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 924:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(745);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 925:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(739);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 926:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(731);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 927:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(764);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 928:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(563);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 929:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(907);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 930:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(903);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 931:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(813);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 932:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(830);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 933:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(780);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 934:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(840);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 935:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(818);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 936:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(836);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 937:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'U' ||
          lookahead == 'u') ADVANCE(877);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 938:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'U' ||
          lookahead == 'u') ADVANCE(824);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 939:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'U' ||
          lookahead == 'u') ADVANCE(790);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 940:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'U' ||
          lookahead == 'u') ADVANCE(915);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 941:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'U' ||
          lookahead == 'u') ADVANCE(878);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 942:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'U' ||
          lookahead == 'u') ADVANCE(828);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 943:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'U' ||
          lookahead == 'u') ADVANCE(806);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 944:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'U' ||
          lookahead == 'u') ADVANCE(849);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 945:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'U' ||
          lookahead == 'u') ADVANCE(852);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 946:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'X' ||
          lookahead == 'x') ADVANCE(921);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 947:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'X' ||
          lookahead == 'x') ADVANCE(835);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 948:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'Y' ||
          lookahead == 'y') ADVANCE(762);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 949:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'Y' ||
          lookahead == 'y') ADVANCE(908);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 950:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'Y' ||
          lookahead == 'y') ADVANCE(913);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 951:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'Y' ||
          lookahead == 'y') ADVANCE(838);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 952:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == 'Z' ||
          lookahead == 'z') ADVANCE(814);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Y') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'y')) ADVANCE(960);
      END_STATE();
    case 953:
      ACCEPT_TOKEN(sym_object_name);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(773);
      if (lookahead == '$' ||
          ('G' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('g' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 954:
      ACCEPT_TOKEN(sym_object_name);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(953);
      if (lookahead == '$' ||
          ('G' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('g' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 955:
      ACCEPT_TOKEN(sym_object_name);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(954);
      if (lookahead == '$' ||
          ('G' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('g' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 956:
      ACCEPT_TOKEN(sym_object_name);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(955);
      if (lookahead == '$' ||
          ('G' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('g' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 957:
      ACCEPT_TOKEN(sym_object_name);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(956);
      if (lookahead == '$' ||
          ('G' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('g' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 958:
      ACCEPT_TOKEN(sym_object_name);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(957);
      if (lookahead == '$' ||
          ('G' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('g' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 959:
      ACCEPT_TOKEN(sym_object_name);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(958);
      if (lookahead == '$' ||
          ('G' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('g' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    case 960:
      ACCEPT_TOKEN(sym_object_name);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(960);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 0},
  [2] = {.lex_state = 0},
  [3] = {.lex_state = 0},
  [4] = {.lex_state = 4},
  [5] = {.lex_state = 4},
  [6] = {.lex_state = 4},
  [7] = {.lex_state = 4},
  [8] = {.lex_state = 4},
  [9] = {.lex_state = 4},
  [10] = {.lex_state = 4},
  [11] = {.lex_state = 4},
  [12] = {.lex_state = 4},
  [13] = {.lex_state = 4},
  [14] = {.lex_state = 4},
  [15] = {.lex_state = 4},
  [16] = {.lex_state = 4},
  [17] = {.lex_state = 4},
  [18] = {.lex_state = 4},
  [19] = {.lex_state = 4},
  [20] = {.lex_state = 4},
  [21] = {.lex_state = 4},
  [22] = {.lex_state = 4},
  [23] = {.lex_state = 4},
  [24] = {.lex_state = 4},
  [25] = {.lex_state = 4},
  [26] = {.lex_state = 4},
  [27] = {.lex_state = 4},
  [28] = {.lex_state = 4},
  [29] = {.lex_state = 558},
  [30] = {.lex_state = 558},
  [31] = {.lex_state = 558},
  [32] = {.lex_state = 558},
  [33] = {.lex_state = 558},
  [34] = {.lex_state = 558},
  [35] = {.lex_state = 558},
  [36] = {.lex_state = 558},
  [37] = {.lex_state = 558},
  [38] = {.lex_state = 558},
  [39] = {.lex_state = 558},
  [40] = {.lex_state = 558},
  [41] = {.lex_state = 558},
  [42] = {.lex_state = 558},
  [43] = {.lex_state = 0},
  [44] = {.lex_state = 558},
  [45] = {.lex_state = 558},
  [46] = {.lex_state = 558},
  [47] = {.lex_state = 558},
  [48] = {.lex_state = 558},
  [49] = {.lex_state = 558},
  [50] = {.lex_state = 0},
  [51] = {.lex_state = 557},
  [52] = {.lex_state = 0},
  [53] = {.lex_state = 558},
  [54] = {.lex_state = 558},
  [55] = {.lex_state = 558},
  [56] = {.lex_state = 558},
  [57] = {.lex_state = 558},
  [58] = {.lex_state = 0},
  [59] = {.lex_state = 558},
  [60] = {.lex_state = 558},
  [61] = {.lex_state = 0},
  [62] = {.lex_state = 557},
  [63] = {.lex_state = 558},
  [64] = {.lex_state = 0},
  [65] = {.lex_state = 0},
  [66] = {.lex_state = 0},
  [67] = {.lex_state = 558},
  [68] = {.lex_state = 0},
  [69] = {.lex_state = 558},
  [70] = {.lex_state = 0},
  [71] = {.lex_state = 0},
  [72] = {.lex_state = 558},
  [73] = {.lex_state = 557},
  [74] = {.lex_state = 558},
  [75] = {.lex_state = 558},
  [76] = {.lex_state = 558},
  [77] = {.lex_state = 0},
  [78] = {.lex_state = 0},
  [79] = {.lex_state = 0},
  [80] = {.lex_state = 558},
  [81] = {.lex_state = 558},
  [82] = {.lex_state = 557},
  [83] = {.lex_state = 0},
  [84] = {.lex_state = 557},
  [85] = {.lex_state = 0},
  [86] = {.lex_state = 0},
  [87] = {.lex_state = 0},
  [88] = {.lex_state = 0},
  [89] = {.lex_state = 0},
  [90] = {.lex_state = 0},
  [91] = {.lex_state = 558},
  [92] = {.lex_state = 0},
  [93] = {.lex_state = 558},
  [94] = {.lex_state = 558},
  [95] = {.lex_state = 0},
  [96] = {.lex_state = 558},
  [97] = {.lex_state = 0},
  [98] = {.lex_state = 0},
  [99] = {.lex_state = 0},
  [100] = {.lex_state = 0},
  [101] = {.lex_state = 558},
  [102] = {.lex_state = 0},
  [103] = {.lex_state = 0},
  [104] = {.lex_state = 0},
  [105] = {.lex_state = 0},
  [106] = {.lex_state = 0},
  [107] = {.lex_state = 0},
  [108] = {.lex_state = 0},
  [109] = {.lex_state = 0},
  [110] = {.lex_state = 0},
  [111] = {.lex_state = 0},
  [112] = {.lex_state = 0},
  [113] = {.lex_state = 0},
  [114] = {.lex_state = 0},
  [115] = {.lex_state = 0},
  [116] = {.lex_state = 0},
  [117] = {.lex_state = 0},
  [118] = {.lex_state = 0},
  [119] = {.lex_state = 0},
  [120] = {.lex_state = 0},
  [121] = {.lex_state = 0},
  [122] = {.lex_state = 0},
  [123] = {.lex_state = 0},
  [124] = {.lex_state = 0},
  [125] = {.lex_state = 0},
  [126] = {.lex_state = 0},
  [127] = {.lex_state = 0},
  [128] = {.lex_state = 0},
  [129] = {.lex_state = 0},
  [130] = {.lex_state = 0},
  [131] = {.lex_state = 0},
  [132] = {.lex_state = 0},
  [133] = {.lex_state = 0},
  [134] = {.lex_state = 0},
  [135] = {.lex_state = 0},
  [136] = {.lex_state = 0},
  [137] = {.lex_state = 0},
  [138] = {.lex_state = 0},
  [139] = {.lex_state = 0},
  [140] = {.lex_state = 0},
  [141] = {.lex_state = 0},
  [142] = {.lex_state = 0},
  [143] = {.lex_state = 558},
  [144] = {.lex_state = 0},
  [145] = {.lex_state = 0},
  [146] = {.lex_state = 0},
  [147] = {.lex_state = 0},
  [148] = {.lex_state = 0},
  [149] = {.lex_state = 0},
  [150] = {.lex_state = 0},
  [151] = {.lex_state = 0},
  [152] = {.lex_state = 0},
  [153] = {.lex_state = 0},
  [154] = {.lex_state = 0},
  [155] = {.lex_state = 0},
  [156] = {.lex_state = 0},
  [157] = {.lex_state = 0},
  [158] = {.lex_state = 0},
  [159] = {.lex_state = 0},
  [160] = {.lex_state = 0},
  [161] = {.lex_state = 0},
  [162] = {.lex_state = 0},
  [163] = {.lex_state = 558},
  [164] = {.lex_state = 0},
  [165] = {.lex_state = 0},
  [166] = {.lex_state = 0},
  [167] = {.lex_state = 0},
  [168] = {.lex_state = 0},
  [169] = {.lex_state = 0},
  [170] = {.lex_state = 558},
  [171] = {.lex_state = 0},
  [172] = {.lex_state = 558},
  [173] = {.lex_state = 558},
  [174] = {.lex_state = 0},
  [175] = {.lex_state = 0},
  [176] = {.lex_state = 0},
  [177] = {.lex_state = 0},
  [178] = {.lex_state = 0},
  [179] = {.lex_state = 0},
  [180] = {.lex_state = 0},
  [181] = {.lex_state = 0},
  [182] = {.lex_state = 558},
  [183] = {.lex_state = 0},
  [184] = {.lex_state = 0},
  [185] = {.lex_state = 0},
  [186] = {.lex_state = 0},
  [187] = {.lex_state = 0},
  [188] = {.lex_state = 0},
  [189] = {.lex_state = 0},
  [190] = {.lex_state = 0},
  [191] = {.lex_state = 0},
  [192] = {.lex_state = 558},
  [193] = {.lex_state = 0},
  [194] = {.lex_state = 0},
  [195] = {.lex_state = 0},
  [196] = {.lex_state = 0},
  [197] = {.lex_state = 0},
  [198] = {.lex_state = 0},
  [199] = {.lex_state = 0},
  [200] = {.lex_state = 0},
  [201] = {.lex_state = 0},
  [202] = {.lex_state = 0},
  [203] = {.lex_state = 0},
  [204] = {.lex_state = 0},
  [205] = {.lex_state = 0},
  [206] = {.lex_state = 0},
  [207] = {.lex_state = 0},
  [208] = {.lex_state = 0},
  [209] = {.lex_state = 0},
  [210] = {.lex_state = 0},
  [211] = {.lex_state = 0},
  [212] = {.lex_state = 0},
  [213] = {.lex_state = 0},
  [214] = {.lex_state = 0},
  [215] = {.lex_state = 0},
  [216] = {.lex_state = 0},
  [217] = {.lex_state = 0},
  [218] = {.lex_state = 0},
  [219] = {.lex_state = 0},
  [220] = {.lex_state = 0},
  [221] = {.lex_state = 0},
  [222] = {.lex_state = 0},
  [223] = {.lex_state = 0},
  [224] = {.lex_state = 0},
  [225] = {.lex_state = 0},
  [226] = {.lex_state = 0},
  [227] = {.lex_state = 0},
  [228] = {.lex_state = 0},
  [229] = {.lex_state = 0},
  [230] = {.lex_state = 0},
  [231] = {.lex_state = 0},
  [232] = {.lex_state = 0},
  [233] = {.lex_state = 0},
  [234] = {.lex_state = 0},
  [235] = {.lex_state = 0},
  [236] = {.lex_state = 0},
  [237] = {.lex_state = 0},
  [238] = {.lex_state = 0},
  [239] = {.lex_state = 0},
  [240] = {.lex_state = 0},
  [241] = {.lex_state = 0},
  [242] = {.lex_state = 0},
  [243] = {.lex_state = 0},
  [244] = {.lex_state = 0},
  [245] = {.lex_state = 0},
  [246] = {.lex_state = 0},
  [247] = {.lex_state = 0},
  [248] = {.lex_state = 0},
  [249] = {.lex_state = 0},
  [250] = {.lex_state = 0},
  [251] = {.lex_state = 0},
  [252] = {.lex_state = 0},
  [253] = {.lex_state = 0},
  [254] = {.lex_state = 0},
  [255] = {.lex_state = 0},
  [256] = {.lex_state = 0},
  [257] = {.lex_state = 0},
  [258] = {.lex_state = 0},
  [259] = {.lex_state = 0},
  [260] = {.lex_state = 0},
  [261] = {.lex_state = 0},
  [262] = {.lex_state = 0},
  [263] = {.lex_state = 0},
  [264] = {.lex_state = 0},
  [265] = {.lex_state = 0},
  [266] = {.lex_state = 0},
  [267] = {.lex_state = 0},
  [268] = {.lex_state = 0},
  [269] = {.lex_state = 0},
  [270] = {.lex_state = 0},
  [271] = {.lex_state = 0},
  [272] = {.lex_state = 0},
  [273] = {.lex_state = 0},
  [274] = {.lex_state = 0},
  [275] = {.lex_state = 0},
  [276] = {.lex_state = 0},
  [277] = {.lex_state = 0},
  [278] = {.lex_state = 0},
  [279] = {.lex_state = 0},
  [280] = {.lex_state = 0},
  [281] = {.lex_state = 0},
  [282] = {.lex_state = 0},
  [283] = {.lex_state = 1},
  [284] = {.lex_state = 0},
  [285] = {.lex_state = 0},
  [286] = {.lex_state = 0},
  [287] = {.lex_state = 0},
  [288] = {.lex_state = 0},
  [289] = {.lex_state = 0},
  [290] = {.lex_state = 0},
  [291] = {.lex_state = 0},
  [292] = {.lex_state = 0},
  [293] = {.lex_state = 0},
  [294] = {.lex_state = 0},
  [295] = {.lex_state = 0},
  [296] = {.lex_state = 1},
  [297] = {.lex_state = 0},
  [298] = {.lex_state = 557},
  [299] = {.lex_state = 557},
  [300] = {.lex_state = 557},
  [301] = {.lex_state = 557},
  [302] = {.lex_state = 557},
  [303] = {.lex_state = 0},
  [304] = {.lex_state = 557},
  [305] = {.lex_state = 557},
  [306] = {.lex_state = 1},
  [307] = {.lex_state = 557},
  [308] = {.lex_state = 557},
  [309] = {.lex_state = 557},
  [310] = {.lex_state = 557},
  [311] = {.lex_state = 1},
  [312] = {.lex_state = 1},
  [313] = {.lex_state = 557},
  [314] = {.lex_state = 1},
  [315] = {.lex_state = 557},
  [316] = {.lex_state = 44},
  [317] = {.lex_state = 55},
  [318] = {.lex_state = 557},
  [319] = {.lex_state = 557},
  [320] = {.lex_state = 0},
  [321] = {.lex_state = 557},
  [322] = {.lex_state = 44},
  [323] = {.lex_state = 44},
  [324] = {.lex_state = 557},
  [325] = {.lex_state = 557},
  [326] = {.lex_state = 557},
  [327] = {.lex_state = 55},
  [328] = {.lex_state = 557},
  [329] = {.lex_state = 557},
  [330] = {.lex_state = 6},
  [331] = {.lex_state = 6},
  [332] = {.lex_state = 12},
  [333] = {.lex_state = 6},
  [334] = {.lex_state = 12},
  [335] = {.lex_state = 6},
  [336] = {.lex_state = 10},
  [337] = {.lex_state = 6},
  [338] = {.lex_state = 12},
  [339] = {.lex_state = 12},
  [340] = {.lex_state = 6},
  [341] = {.lex_state = 6},
  [342] = {.lex_state = 4},
  [343] = {.lex_state = 9},
  [344] = {.lex_state = 9},
  [345] = {.lex_state = 5},
  [346] = {.lex_state = 557},
  [347] = {.lex_state = 0},
  [348] = {.lex_state = 9},
  [349] = {.lex_state = 10},
  [350] = {.lex_state = 5},
  [351] = {.lex_state = 7},
  [352] = {.lex_state = 557},
  [353] = {.lex_state = 0},
  [354] = {.lex_state = 55},
  [355] = {.lex_state = 8},
  [356] = {.lex_state = 5},
  [357] = {.lex_state = 557},
  [358] = {.lex_state = 0},
  [359] = {.lex_state = 0},
  [360] = {.lex_state = 0},
  [361] = {.lex_state = 13},
  [362] = {.lex_state = 0},
  [363] = {.lex_state = 5},
  [364] = {.lex_state = 0},
  [365] = {.lex_state = 4},
  [366] = {.lex_state = 0},
  [367] = {.lex_state = 0},
  [368] = {.lex_state = 0},
  [369] = {.lex_state = 0},
  [370] = {.lex_state = 0},
  [371] = {.lex_state = 2},
  [372] = {.lex_state = 5},
  [373] = {.lex_state = 13},
  [374] = {.lex_state = 5},
  [375] = {.lex_state = 0},
  [376] = {.lex_state = 0},
  [377] = {.lex_state = 0},
  [378] = {.lex_state = 0},
  [379] = {.lex_state = 3},
  [380] = {.lex_state = 0},
  [381] = {.lex_state = 0},
  [382] = {.lex_state = 0},
  [383] = {.lex_state = 0},
  [384] = {.lex_state = 0},
  [385] = {.lex_state = 0},
  [386] = {.lex_state = 557},
  [387] = {.lex_state = 15},
  [388] = {.lex_state = 0},
  [389] = {.lex_state = 0},
  [390] = {.lex_state = 0},
  [391] = {.lex_state = 0},
  [392] = {.lex_state = 0},
  [393] = {.lex_state = 0},
  [394] = {.lex_state = 0},
  [395] = {.lex_state = 0},
  [396] = {.lex_state = 15},
  [397] = {.lex_state = 0},
  [398] = {.lex_state = 0},
  [399] = {.lex_state = 0},
  [400] = {.lex_state = 558},
  [401] = {.lex_state = 0},
  [402] = {.lex_state = 0},
  [403] = {.lex_state = 0},
  [404] = {.lex_state = 5},
  [405] = {.lex_state = 0},
  [406] = {.lex_state = 0},
  [407] = {.lex_state = 0},
  [408] = {.lex_state = 558},
  [409] = {.lex_state = 0},
  [410] = {.lex_state = 0},
  [411] = {.lex_state = 0},
  [412] = {.lex_state = 558},
  [413] = {.lex_state = 0},
  [414] = {.lex_state = 0},
  [415] = {.lex_state = 0},
  [416] = {.lex_state = 0},
  [417] = {.lex_state = 0},
  [418] = {.lex_state = 14},
  [419] = {.lex_state = 14},
  [420] = {.lex_state = 0},
  [421] = {.lex_state = 0},
  [422] = {.lex_state = 0},
  [423] = {.lex_state = 14},
  [424] = {.lex_state = 0},
  [425] = {.lex_state = 0},
  [426] = {.lex_state = 0},
  [427] = {.lex_state = 0},
  [428] = {.lex_state = 14},
  [429] = {.lex_state = 0},
  [430] = {.lex_state = 0},
  [431] = {.lex_state = 14},
  [432] = {.lex_state = 0},
  [433] = {.lex_state = 14},
  [434] = {.lex_state = 14},
  [435] = {.lex_state = 14},
  [436] = {.lex_state = 5},
  [437] = {.lex_state = 5},
  [438] = {.lex_state = 0},
  [439] = {.lex_state = 0},
  [440] = {.lex_state = 14},
  [441] = {.lex_state = 5},
  [442] = {.lex_state = 0},
  [443] = {.lex_state = 0},
  [444] = {.lex_state = 14},
  [445] = {.lex_state = 0},
  [446] = {.lex_state = 14},
  [447] = {.lex_state = 0},
  [448] = {.lex_state = 0},
  [449] = {.lex_state = 0},
  [450] = {.lex_state = 14},
  [451] = {.lex_state = 14},
  [452] = {.lex_state = 14},
  [453] = {.lex_state = 14},
  [454] = {.lex_state = 14},
  [455] = {.lex_state = 14},
  [456] = {.lex_state = 0},
  [457] = {.lex_state = 14},
  [458] = {.lex_state = 14},
  [459] = {.lex_state = 14},
  [460] = {.lex_state = 0},
  [461] = {.lex_state = 0},
  [462] = {.lex_state = 0},
  [463] = {.lex_state = 5},
  [464] = {.lex_state = 0},
  [465] = {.lex_state = 0},
  [466] = {.lex_state = 0},
  [467] = {.lex_state = 0},
  [468] = {.lex_state = 0},
  [469] = {.lex_state = 0},
  [470] = {.lex_state = 0},
  [471] = {.lex_state = 0},
  [472] = {.lex_state = 0},
  [473] = {.lex_state = 0},
  [474] = {.lex_state = 0},
  [475] = {.lex_state = 5},
  [476] = {.lex_state = 0},
  [477] = {.lex_state = 0},
  [478] = {.lex_state = 0},
  [479] = {.lex_state = 0},
  [480] = {.lex_state = 0},
  [481] = {.lex_state = 0},
  [482] = {.lex_state = 0},
  [483] = {.lex_state = 0},
  [484] = {.lex_state = 0},
  [485] = {.lex_state = 0},
  [486] = {.lex_state = 0},
  [487] = {.lex_state = 5},
  [488] = {.lex_state = 0},
  [489] = {.lex_state = 0},
  [490] = {.lex_state = 0},
  [491] = {.lex_state = 0},
  [492] = {.lex_state = 0},
  [493] = {.lex_state = 0},
  [494] = {.lex_state = 5},
  [495] = {.lex_state = 0},
  [496] = {.lex_state = 5},
  [497] = {.lex_state = 0},
  [498] = {.lex_state = 0},
  [499] = {.lex_state = 0},
  [500] = {.lex_state = 0},
  [501] = {.lex_state = 0},
  [502] = {.lex_state = 0},
  [503] = {.lex_state = 0},
  [504] = {.lex_state = 0},
  [505] = {.lex_state = 0},
  [506] = {.lex_state = 0},
  [507] = {.lex_state = 0},
  [508] = {.lex_state = 0},
  [509] = {.lex_state = 0},
  [510] = {.lex_state = 0},
  [511] = {.lex_state = 0},
  [512] = {.lex_state = 0},
  [513] = {.lex_state = 0},
  [514] = {.lex_state = 16},
  [515] = {.lex_state = 0},
  [516] = {.lex_state = 0},
  [517] = {.lex_state = 0},
  [518] = {.lex_state = 0},
  [519] = {.lex_state = 14},
  [520] = {.lex_state = 0},
  [521] = {.lex_state = 0},
  [522] = {.lex_state = 0},
  [523] = {.lex_state = 5},
  [524] = {.lex_state = 5},
  [525] = {.lex_state = 5},
  [526] = {.lex_state = 0},
  [527] = {.lex_state = 0},
  [528] = {.lex_state = 5},
  [529] = {.lex_state = 0},
  [530] = {.lex_state = 0},
  [531] = {.lex_state = 5},
  [532] = {.lex_state = 0},
  [533] = {.lex_state = 5},
  [534] = {.lex_state = 0},
  [535] = {.lex_state = 5},
  [536] = {.lex_state = 0},
  [537] = {.lex_state = 0},
  [538] = {.lex_state = 0},
  [539] = {.lex_state = 0},
  [540] = {.lex_state = 5},
  [541] = {.lex_state = 5},
  [542] = {.lex_state = 5},
  [543] = {.lex_state = 0},
  [544] = {.lex_state = 5},
  [545] = {.lex_state = 5},
  [546] = {.lex_state = 0},
  [547] = {.lex_state = 5},
  [548] = {.lex_state = 5},
  [549] = {.lex_state = 5},
  [550] = {.lex_state = 5},
  [551] = {.lex_state = 5},
  [552] = {.lex_state = 0},
  [553] = {.lex_state = 5},
  [554] = {.lex_state = 0},
  [555] = {.lex_state = 0},
  [556] = {.lex_state = 5},
  [557] = {.lex_state = 0},
  [558] = {.lex_state = 0},
  [559] = {.lex_state = 5},
  [560] = {.lex_state = 0},
  [561] = {.lex_state = 0},
  [562] = {.lex_state = 5},
  [563] = {.lex_state = 0},
  [564] = {.lex_state = 5},
  [565] = {.lex_state = 0},
  [566] = {.lex_state = 5},
  [567] = {.lex_state = 5},
  [568] = {.lex_state = 0},
  [569] = {.lex_state = 0},
  [570] = {.lex_state = 5},
  [571] = {.lex_state = 0},
  [572] = {.lex_state = 5},
  [573] = {.lex_state = 0},
  [574] = {.lex_state = 0},
  [575] = {.lex_state = 5},
  [576] = {.lex_state = 0},
  [577] = {.lex_state = 0},
  [578] = {.lex_state = 0},
  [579] = {.lex_state = 0},
  [580] = {.lex_state = 0},
  [581] = {.lex_state = 5},
  [582] = {.lex_state = 0},
  [583] = {.lex_state = 0},
  [584] = {.lex_state = 5},
  [585] = {.lex_state = 5},
  [586] = {.lex_state = 5},
  [587] = {.lex_state = 0},
  [588] = {.lex_state = 0},
  [589] = {.lex_state = 0},
  [590] = {.lex_state = 0},
  [591] = {.lex_state = 0},
  [592] = {.lex_state = 5},
  [593] = {.lex_state = 4},
  [594] = {.lex_state = 0},
  [595] = {.lex_state = 0},
  [596] = {.lex_state = 5},
  [597] = {.lex_state = 5},
  [598] = {.lex_state = 0},
  [599] = {.lex_state = 5},
  [600] = {.lex_state = 0},
  [601] = {.lex_state = 5},
  [602] = {.lex_state = 0},
  [603] = {.lex_state = 5},
  [604] = {.lex_state = 5},
  [605] = {.lex_state = 0},
  [606] = {.lex_state = 5},
  [607] = {.lex_state = 5},
  [608] = {.lex_state = 5},
  [609] = {.lex_state = 0},
  [610] = {.lex_state = 0},
  [611] = {.lex_state = 0},
  [612] = {.lex_state = 0},
  [613] = {.lex_state = 0},
  [614] = {.lex_state = 0},
  [615] = {.lex_state = 0},
  [616] = {.lex_state = 5},
  [617] = {.lex_state = 0},
  [618] = {.lex_state = 0},
  [619] = {.lex_state = 5},
  [620] = {.lex_state = 0},
  [621] = {.lex_state = 5},
  [622] = {.lex_state = 5},
  [623] = {.lex_state = 5},
  [624] = {.lex_state = 5},
  [625] = {.lex_state = 5},
  [626] = {.lex_state = 5},
  [627] = {.lex_state = 5},
  [628] = {.lex_state = 5},
  [629] = {.lex_state = 0},
  [630] = {.lex_state = 5},
  [631] = {.lex_state = 5},
  [632] = {.lex_state = 5},
  [633] = {.lex_state = 0},
  [634] = {.lex_state = 4},
  [635] = {.lex_state = 0},
  [636] = {.lex_state = 0},
  [637] = {.lex_state = 5},
  [638] = {.lex_state = 4},
  [639] = {.lex_state = 0},
  [640] = {.lex_state = 0},
  [641] = {.lex_state = 0},
  [642] = {.lex_state = 0},
  [643] = {.lex_state = 0},
  [644] = {.lex_state = 0},
  [645] = {.lex_state = 11},
  [646] = {.lex_state = 5},
  [647] = {.lex_state = 0},
  [648] = {.lex_state = 5},
  [649] = {.lex_state = 5},
  [650] = {.lex_state = 0},
  [651] = {.lex_state = 5},
  [652] = {.lex_state = 0},
  [653] = {.lex_state = 0},
  [654] = {.lex_state = 5},
  [655] = {.lex_state = 5},
  [656] = {.lex_state = 5},
  [657] = {.lex_state = 0},
  [658] = {.lex_state = 0},
  [659] = {.lex_state = 0},
  [660] = {.lex_state = 5},
  [661] = {.lex_state = 0},
  [662] = {.lex_state = 0},
  [663] = {.lex_state = 5},
  [664] = {.lex_state = 5},
  [665] = {.lex_state = 0},
  [666] = {.lex_state = 0},
  [667] = {.lex_state = 5},
  [668] = {.lex_state = 0},
  [669] = {.lex_state = 5},
  [670] = {.lex_state = 5},
  [671] = {.lex_state = 0},
  [672] = {.lex_state = 0},
  [673] = {.lex_state = 5},
  [674] = {.lex_state = 0},
  [675] = {.lex_state = 0},
  [676] = {.lex_state = 0},
  [677] = {.lex_state = 0},
  [678] = {.lex_state = 0},
  [679] = {.lex_state = 0},
  [680] = {.lex_state = 558},
  [681] = {.lex_state = 0},
  [682] = {.lex_state = 0},
  [683] = {.lex_state = 0},
  [684] = {.lex_state = 0},
  [685] = {.lex_state = 0},
  [686] = {.lex_state = 0},
  [687] = {.lex_state = 0},
  [688] = {.lex_state = 0},
  [689] = {.lex_state = 0},
  [690] = {.lex_state = 0},
  [691] = {.lex_state = 0},
  [692] = {.lex_state = 0},
  [693] = {.lex_state = 0},
  [694] = {.lex_state = 0},
  [695] = {.lex_state = 0},
  [696] = {.lex_state = 0},
  [697] = {.lex_state = 0},
  [698] = {.lex_state = 0},
  [699] = {.lex_state = 0},
  [700] = {.lex_state = 0},
  [701] = {.lex_state = 0},
  [702] = {.lex_state = 0},
  [703] = {.lex_state = 0},
  [704] = {.lex_state = 5},
  [705] = {.lex_state = 0},
  [706] = {.lex_state = 0},
  [707] = {.lex_state = 0},
  [708] = {.lex_state = 0},
  [709] = {.lex_state = 0},
  [710] = {.lex_state = 0},
  [711] = {.lex_state = 0},
  [712] = {.lex_state = 0},
  [713] = {.lex_state = 0},
  [714] = {.lex_state = 0},
  [715] = {.lex_state = 5},
  [716] = {.lex_state = 0},
  [717] = {.lex_state = 0},
  [718] = {.lex_state = 5},
  [719] = {.lex_state = 0},
  [720] = {.lex_state = 0},
  [721] = {.lex_state = 0},
  [722] = {.lex_state = 0},
  [723] = {.lex_state = 0},
  [724] = {.lex_state = 0},
  [725] = {.lex_state = 0},
  [726] = {.lex_state = 0},
  [727] = {.lex_state = 0},
  [728] = {.lex_state = 0},
  [729] = {.lex_state = 5},
  [730] = {.lex_state = 5},
  [731] = {.lex_state = 0},
  [732] = {.lex_state = 5},
  [733] = {.lex_state = 0},
  [734] = {.lex_state = 5},
  [735] = {.lex_state = 0},
  [736] = {.lex_state = 558},
  [737] = {.lex_state = 0},
  [738] = {.lex_state = 5},
  [739] = {.lex_state = 0},
  [740] = {.lex_state = 0},
  [741] = {.lex_state = 0},
  [742] = {.lex_state = 0},
  [743] = {.lex_state = 0},
  [744] = {.lex_state = 4},
  [745] = {.lex_state = 0},
  [746] = {.lex_state = 0},
  [747] = {.lex_state = 0},
  [748] = {.lex_state = 4},
  [749] = {.lex_state = 5},
  [750] = {.lex_state = 5},
  [751] = {.lex_state = 5},
  [752] = {.lex_state = 0},
  [753] = {.lex_state = 0},
  [754] = {.lex_state = 558},
  [755] = {.lex_state = 0},
  [756] = {.lex_state = 0},
  [757] = {.lex_state = 0},
  [758] = {.lex_state = 0},
  [759] = {.lex_state = 0},
  [760] = {.lex_state = 5},
  [761] = {.lex_state = 0},
  [762] = {.lex_state = 0},
  [763] = {.lex_state = 0},
  [764] = {.lex_state = 0},
  [765] = {.lex_state = 5},
  [766] = {.lex_state = 5},
  [767] = {.lex_state = 0},
  [768] = {.lex_state = 5},
  [769] = {.lex_state = 5},
  [770] = {.lex_state = 0},
  [771] = {.lex_state = 0},
  [772] = {.lex_state = 0},
  [773] = {.lex_state = 5},
  [774] = {.lex_state = 0},
  [775] = {.lex_state = 5},
  [776] = {.lex_state = 0},
  [777] = {.lex_state = 0},
  [778] = {.lex_state = 0},
  [779] = {.lex_state = 0},
  [780] = {.lex_state = 0},
  [781] = {.lex_state = 0},
  [782] = {.lex_state = 5},
  [783] = {.lex_state = 5},
  [784] = {.lex_state = 0},
  [785] = {.lex_state = 0},
  [786] = {.lex_state = 0},
  [787] = {.lex_state = 0},
  [788] = {.lex_state = 0},
  [789] = {.lex_state = 0},
  [790] = {.lex_state = 0},
  [791] = {.lex_state = 5},
  [792] = {.lex_state = 0},
  [793] = {.lex_state = 5},
  [794] = {.lex_state = 4},
  [795] = {.lex_state = 4},
  [796] = {.lex_state = 0},
  [797] = {.lex_state = 0},
  [798] = {.lex_state = 0},
  [799] = {.lex_state = 0},
  [800] = {.lex_state = 0},
  [801] = {.lex_state = 0},
  [802] = {.lex_state = 0},
  [803] = {.lex_state = 0},
  [804] = {.lex_state = 0},
  [805] = {.lex_state = 0},
  [806] = {.lex_state = 0},
  [807] = {.lex_state = 0},
  [808] = {.lex_state = 0},
  [809] = {.lex_state = 4},
  [810] = {.lex_state = 5},
  [811] = {.lex_state = 5},
  [812] = {.lex_state = 0},
  [813] = {.lex_state = 0},
  [814] = {.lex_state = 0},
  [815] = {.lex_state = 0},
  [816] = {.lex_state = 0},
  [817] = {.lex_state = 0},
  [818] = {.lex_state = 0},
  [819] = {.lex_state = 0},
  [820] = {.lex_state = 0},
  [821] = {.lex_state = 0},
  [822] = {.lex_state = 0},
  [823] = {.lex_state = 0},
  [824] = {.lex_state = 0},
  [825] = {.lex_state = 0},
  [826] = {.lex_state = 0},
  [827] = {.lex_state = 0},
  [828] = {.lex_state = 0},
  [829] = {.lex_state = 5},
  [830] = {.lex_state = 0},
  [831] = {.lex_state = 0},
  [832] = {.lex_state = 0},
  [833] = {.lex_state = 0},
  [834] = {.lex_state = 0},
  [835] = {.lex_state = 5},
  [836] = {.lex_state = 5},
  [837] = {.lex_state = 0},
  [838] = {.lex_state = 0},
  [839] = {.lex_state = 0},
  [840] = {.lex_state = 0},
  [841] = {.lex_state = 0},
  [842] = {.lex_state = 0},
  [843] = {.lex_state = 0},
  [844] = {.lex_state = 0},
  [845] = {.lex_state = 0},
  [846] = {.lex_state = 0},
  [847] = {.lex_state = 0},
  [848] = {.lex_state = 0},
  [849] = {.lex_state = 0},
  [850] = {.lex_state = 0},
  [851] = {.lex_state = 0},
  [852] = {.lex_state = 0},
  [853] = {.lex_state = 5},
  [854] = {.lex_state = 0},
  [855] = {.lex_state = 0},
  [856] = {.lex_state = 558},
  [857] = {.lex_state = 0},
  [858] = {.lex_state = 0},
  [859] = {.lex_state = 0},
  [860] = {.lex_state = 558},
  [861] = {.lex_state = 5},
  [862] = {.lex_state = 0},
  [863] = {.lex_state = 0},
  [864] = {.lex_state = 0},
  [865] = {.lex_state = 0},
  [866] = {.lex_state = 0},
  [867] = {.lex_state = 0},
  [868] = {.lex_state = 0},
  [869] = {.lex_state = 0},
  [870] = {.lex_state = 0},
  [871] = {.lex_state = 0},
  [872] = {.lex_state = 0},
  [873] = {.lex_state = 0},
  [874] = {.lex_state = 0},
  [875] = {.lex_state = 0},
  [876] = {.lex_state = 0},
  [877] = {.lex_state = 5},
  [878] = {.lex_state = 0},
  [879] = {.lex_state = 0},
  [880] = {.lex_state = 0},
  [881] = {.lex_state = 0},
  [882] = {.lex_state = 0},
  [883] = {.lex_state = 0},
  [884] = {.lex_state = 0},
  [885] = {.lex_state = 0},
  [886] = {.lex_state = 5},
  [887] = {.lex_state = 0},
  [888] = {.lex_state = 0},
  [889] = {.lex_state = 0},
  [890] = {.lex_state = 0},
  [891] = {.lex_state = 0},
  [892] = {.lex_state = 5},
  [893] = {.lex_state = 5},
  [894] = {.lex_state = 0},
  [895] = {.lex_state = 0},
  [896] = {.lex_state = 0},
  [897] = {.lex_state = 5},
  [898] = {.lex_state = 0},
  [899] = {.lex_state = 0},
  [900] = {.lex_state = 0},
  [901] = {.lex_state = 0},
  [902] = {.lex_state = 0},
  [903] = {.lex_state = 0},
  [904] = {.lex_state = 0},
  [905] = {.lex_state = 557},
  [906] = {.lex_state = 0},
  [907] = {.lex_state = 0},
  [908] = {.lex_state = 0},
  [909] = {.lex_state = 558},
  [910] = {.lex_state = 5},
  [911] = {.lex_state = 0},
  [912] = {.lex_state = 0},
  [913] = {.lex_state = 558},
  [914] = {.lex_state = 0},
  [915] = {.lex_state = 0},
  [916] = {.lex_state = 557},
  [917] = {.lex_state = 0},
  [918] = {.lex_state = 0},
  [919] = {.lex_state = 5},
  [920] = {.lex_state = 5},
  [921] = {.lex_state = 0},
  [922] = {.lex_state = 0},
  [923] = {.lex_state = 5},
  [924] = {.lex_state = 0},
  [925] = {.lex_state = 0},
  [926] = {.lex_state = 5},
  [927] = {.lex_state = 558},
  [928] = {.lex_state = 0},
  [929] = {.lex_state = 0},
  [930] = {.lex_state = 0},
  [931] = {.lex_state = 0},
  [932] = {.lex_state = 0},
  [933] = {.lex_state = 0},
  [934] = {.lex_state = 0},
  [935] = {.lex_state = 0},
  [936] = {.lex_state = 0},
  [937] = {.lex_state = 0},
  [938] = {.lex_state = 5},
  [939] = {.lex_state = 0},
  [940] = {.lex_state = 0},
  [941] = {.lex_state = 0},
  [942] = {.lex_state = 0},
  [943] = {.lex_state = 0},
  [944] = {.lex_state = 0},
  [945] = {.lex_state = 0},
  [946] = {.lex_state = 0},
  [947] = {.lex_state = 5},
  [948] = {.lex_state = 0},
  [949] = {.lex_state = 44},
  [950] = {.lex_state = 5},
  [951] = {.lex_state = 5},
  [952] = {.lex_state = 0},
  [953] = {.lex_state = 0},
  [954] = {.lex_state = 0},
  [955] = {.lex_state = 558},
  [956] = {.lex_state = 0},
  [957] = {.lex_state = 0},
  [958] = {.lex_state = 0},
  [959] = {.lex_state = 5},
  [960] = {.lex_state = 5},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [anon_sym_SEMI] = ACTIONS(1),
    [aux_sym_select_statement_token1] = ACTIONS(1),
    [aux_sym_select_statement_token2] = ACTIONS(1),
    [aux_sym_select_statement_token3] = ACTIONS(1),
    [aux_sym_select_statement_token5] = ACTIONS(1),
    [aux_sym_limit_spec_token1] = ACTIONS(1),
    [anon_sym_STAR] = ACTIONS(1),
    [anon_sym_COMMA] = ACTIONS(1),
    [aux_sym_select_element_token1] = ACTIONS(1),
    [anon_sym_LPAREN] = ACTIONS(1),
    [anon_sym_RPAREN] = ACTIONS(1),
    [aux_sym_constant_token1] = ACTIONS(1),
    [aux_sym_constant_token2] = ACTIONS(1),
    [anon_sym_QMARK] = ACTIONS(1),
    [anon_sym_COLON] = ACTIONS(1),
    [sym__string_literal] = ACTIONS(1),
    [sym__boolean_literal] = ACTIONS(1),
    [sym__code_block] = ACTIONS(1),
    [aux_sym_from_spec_token1] = ACTIONS(1),
    [aux_sym_where_spec_token1] = ACTIONS(1),
    [aux_sym_relation_elements_token1] = ACTIONS(1),
    [anon_sym_LT] = ACTIONS(1),
    [anon_sym_LT_EQ] = ACTIONS(1),
    [anon_sym_LT_GT] = ACTIONS(1),
    [anon_sym_EQ] = ACTIONS(1),
    [anon_sym_GT] = ACTIONS(1),
    [anon_sym_GT_EQ] = ACTIONS(1),
    [aux_sym_relation_element_token1] = ACTIONS(1),
    [aux_sym_relation_contains_key_token1] = ACTIONS(1),
    [aux_sym_relation_contains_key_token2] = ACTIONS(1),
    [aux_sym_order_spec_token1] = ACTIONS(1),
    [aux_sym_order_spec_token2] = ACTIONS(1),
    [aux_sym_order_spec_token4] = ACTIONS(1),
    [aux_sym_delete_statement_token1] = ACTIONS(1),
    [aux_sym_delete_statement_token2] = ACTIONS(1),
    [aux_sym_delete_statement_token3] = ACTIONS(1),
    [aux_sym_begin_batch_token1] = ACTIONS(1),
    [aux_sym_begin_batch_token2] = ACTIONS(1),
    [aux_sym_begin_batch_token3] = ACTIONS(1),
    [aux_sym_begin_batch_token4] = ACTIONS(1),
    [aux_sym_begin_batch_token5] = ACTIONS(1),
    [anon_sym_LBRACK] = ACTIONS(1),
    [anon_sym_RBRACK] = ACTIONS(1),
    [aux_sym_using_timestamp_spec_token1] = ACTIONS(1),
    [aux_sym_using_timestamp_spec_token2] = ACTIONS(1),
    [aux_sym_insert_statement_token1] = ACTIONS(1),
    [aux_sym_insert_statement_token2] = ACTIONS(1),
    [aux_sym_insert_statement_token3] = ACTIONS(1),
    [aux_sym_insert_values_spec_token1] = ACTIONS(1),
    [anon_sym_LBRACE] = ACTIONS(1),
    [anon_sym_RBRACE] = ACTIONS(1),
    [aux_sym_using_ttl_timestamp_token1] = ACTIONS(1),
    [aux_sym_truncate_token1] = ACTIONS(1),
    [aux_sym_truncate_token2] = ACTIONS(1),
    [aux_sym_create_index_token1] = ACTIONS(1),
    [aux_sym_create_index_token2] = ACTIONS(1),
    [aux_sym_create_index_token3] = ACTIONS(1),
    [aux_sym_index_keys_spec_token1] = ACTIONS(1),
    [aux_sym_index_entries_s_spec_token1] = ACTIONS(1),
    [aux_sym_index_full_spec_token1] = ACTIONS(1),
    [aux_sym_drop_index_token1] = ACTIONS(1),
    [aux_sym_update_token1] = ACTIONS(1),
    [aux_sym_update_assignments_token1] = ACTIONS(1),
    [anon_sym_PLUS] = ACTIONS(1),
    [anon_sym_DASH] = ACTIONS(1),
    [aux_sym_use_token1] = ACTIONS(1),
    [aux_sym_grant_token1] = ACTIONS(1),
    [aux_sym_grant_token2] = ACTIONS(1),
    [aux_sym_revoke_token1] = ACTIONS(1),
    [aux_sym_privilege_token1] = ACTIONS(1),
    [aux_sym_privilege_token2] = ACTIONS(1),
    [aux_sym_privilege_token3] = ACTIONS(1),
    [aux_sym_privilege_token4] = ACTIONS(1),
    [aux_sym_privilege_token6] = ACTIONS(1),
    [aux_sym_privilege_token7] = ACTIONS(1),
    [aux_sym_resource_token2] = ACTIONS(1),
    [aux_sym_resource_token5] = ACTIONS(1),
    [anon_sym_DOT] = ACTIONS(1),
    [aux_sym_resource_token6] = ACTIONS(1),
    [aux_sym_list_roles_token1] = ACTIONS(1),
    [aux_sym_list_roles_token2] = ACTIONS(1),
    [aux_sym_list_roles_token3] = ACTIONS(1),
    [aux_sym_drop_aggregate_token1] = ACTIONS(1),
    [aux_sym_drop_materialized_view_token1] = ACTIONS(1),
    [aux_sym_drop_materialized_view_token2] = ACTIONS(1),
    [aux_sym_drop_trigger_token1] = ACTIONS(1),
    [aux_sym_drop_type_token1] = ACTIONS(1),
    [aux_sym_create_aggregate_token1] = ACTIONS(1),
    [aux_sym_create_aggregate_token2] = ACTIONS(1),
    [aux_sym_create_aggregate_token3] = ACTIONS(1),
    [aux_sym_create_aggregate_token4] = ACTIONS(1),
    [aux_sym_create_aggregate_token5] = ACTIONS(1),
    [aux_sym_create_aggregate_token6] = ACTIONS(1),
    [aux_sym_column_not_null_token1] = ACTIONS(1),
    [aux_sym_create_function_token1] = ACTIONS(1),
    [aux_sym_create_function_token2] = ACTIONS(1),
    [aux_sym_native_type_token2] = ACTIONS(1),
    [aux_sym_native_type_token3] = ACTIONS(1),
    [aux_sym_native_type_token4] = ACTIONS(1),
    [aux_sym_native_type_token5] = ACTIONS(1),
    [aux_sym_native_type_token6] = ACTIONS(1),
    [aux_sym_native_type_token7] = ACTIONS(1),
    [aux_sym_native_type_token8] = ACTIONS(1),
    [aux_sym_native_type_token9] = ACTIONS(1),
    [aux_sym_native_type_token10] = ACTIONS(1),
    [aux_sym_native_type_token11] = ACTIONS(1),
    [aux_sym_native_type_token12] = ACTIONS(1),
    [aux_sym_native_type_token13] = ACTIONS(1),
    [aux_sym_native_type_token14] = ACTIONS(1),
    [aux_sym_native_type_token15] = ACTIONS(1),
    [aux_sym_native_type_token16] = ACTIONS(1),
    [aux_sym_native_type_token17] = ACTIONS(1),
    [aux_sym_native_type_token18] = ACTIONS(1),
    [aux_sym_native_type_token19] = ACTIONS(1),
    [aux_sym_collection_type_token1] = ACTIONS(1),
    [aux_sym_tuple_type_token1] = ACTIONS(1),
    [aux_sym_frozen_type_token1] = ACTIONS(1),
    [aux_sym_return_mode_token1] = ACTIONS(1),
    [aux_sym_return_mode_token2] = ACTIONS(1),
    [aux_sym_create_keyspace_token1] = ACTIONS(1),
    [aux_sym_create_keyspace_token2] = ACTIONS(1),
    [aux_sym_durable_writes_token1] = ACTIONS(1),
    [aux_sym_role_with_option_token1] = ACTIONS(1),
    [aux_sym_role_with_option_token2] = ACTIONS(1),
    [aux_sym_role_with_option_token3] = ACTIONS(1),
    [aux_sym_role_with_option_token4] = ACTIONS(1),
    [aux_sym_primary_key_column_token1] = ACTIONS(1),
    [aux_sym_compact_storage_token1] = ACTIONS(1),
    [aux_sym_compact_storage_token2] = ACTIONS(1),
    [aux_sym_clustering_order_token1] = ACTIONS(1),
    [aux_sym_user_super_user_token1] = ACTIONS(1),
    [aux_sym_alter_table_add_token1] = ACTIONS(1),
    [aux_sym_alter_table_rename_token1] = ACTIONS(1),
    [aux_sym_apply_batch_token1] = ACTIONS(1),
  },
  [1] = {
    [sym_source_file] = STATE(956),
    [sym__statement] = STATE(3),
    [sym_select_statement] = STATE(226),
    [sym_delete_statement] = STATE(226),
    [sym_begin_batch] = STATE(485),
    [sym_insert_statement] = STATE(226),
    [sym_truncate] = STATE(226),
    [sym_create_index] = STATE(226),
    [sym_drop_index] = STATE(226),
    [sym_update] = STATE(226),
    [sym_use] = STATE(226),
    [sym_grant] = STATE(226),
    [sym_revoke] = STATE(226),
    [sym_list_roles] = STATE(226),
    [sym_list_permissions] = STATE(226),
    [sym_drop_aggregate] = STATE(226),
    [sym_drop_materialized_view] = STATE(226),
    [sym_drop_function] = STATE(226),
    [sym_drop_keyspace] = STATE(226),
    [sym_drop_role] = STATE(226),
    [sym_drop_table] = STATE(226),
    [sym_drop_trigger] = STATE(226),
    [sym_drop_type] = STATE(226),
    [sym_drop_user] = STATE(226),
    [sym_create_aggregate] = STATE(226),
    [sym_create_materialized_view] = STATE(226),
    [sym_create_function] = STATE(226),
    [sym_create_keyspace] = STATE(226),
    [sym_create_role] = STATE(226),
    [sym_create_table] = STATE(226),
    [sym_create_trigger] = STATE(226),
    [sym_create_type] = STATE(226),
    [sym_create_user] = STATE(226),
    [sym_alter_materialized_view] = STATE(226),
    [sym_alter_keyspace] = STATE(226),
    [sym_alter_role] = STATE(226),
    [sym_alter_table] = STATE(226),
    [sym_alter_type] = STATE(226),
    [sym_alter_user] = STATE(226),
    [sym_apply_batch] = STATE(226),
    [aux_sym_source_file_repeat1] = STATE(3),
    [ts_builtin_sym_end] = ACTIONS(3),
    [aux_sym_select_statement_token1] = ACTIONS(5),
    [aux_sym_delete_statement_token1] = ACTIONS(7),
    [aux_sym_begin_batch_token1] = ACTIONS(9),
    [aux_sym_insert_statement_token1] = ACTIONS(11),
    [aux_sym_truncate_token1] = ACTIONS(13),
    [aux_sym_create_index_token1] = ACTIONS(15),
    [aux_sym_drop_index_token1] = ACTIONS(17),
    [aux_sym_update_token1] = ACTIONS(19),
    [aux_sym_use_token1] = ACTIONS(21),
    [aux_sym_grant_token1] = ACTIONS(23),
    [aux_sym_revoke_token1] = ACTIONS(25),
    [aux_sym_privilege_token3] = ACTIONS(27),
    [aux_sym_list_roles_token1] = ACTIONS(29),
    [aux_sym_apply_batch_token1] = ACTIONS(31),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 18,
    ACTIONS(33), 1,
      ts_builtin_sym_end,
    ACTIONS(35), 1,
      aux_sym_select_statement_token1,
    ACTIONS(38), 1,
      aux_sym_delete_statement_token1,
    ACTIONS(41), 1,
      aux_sym_begin_batch_token1,
    ACTIONS(44), 1,
      aux_sym_insert_statement_token1,
    ACTIONS(47), 1,
      aux_sym_truncate_token1,
    ACTIONS(50), 1,
      aux_sym_create_index_token1,
    ACTIONS(53), 1,
      aux_sym_drop_index_token1,
    ACTIONS(56), 1,
      aux_sym_update_token1,
    ACTIONS(59), 1,
      aux_sym_use_token1,
    ACTIONS(62), 1,
      aux_sym_grant_token1,
    ACTIONS(65), 1,
      aux_sym_revoke_token1,
    ACTIONS(68), 1,
      aux_sym_privilege_token3,
    ACTIONS(71), 1,
      aux_sym_list_roles_token1,
    ACTIONS(74), 1,
      aux_sym_apply_batch_token1,
    STATE(485), 1,
      sym_begin_batch,
    STATE(2), 2,
      sym__statement,
      aux_sym_source_file_repeat1,
    STATE(226), 37,
      sym_select_statement,
      sym_delete_statement,
      sym_insert_statement,
      sym_truncate,
      sym_create_index,
      sym_drop_index,
      sym_update,
      sym_use,
      sym_grant,
      sym_revoke,
      sym_list_roles,
      sym_list_permissions,
      sym_drop_aggregate,
      sym_drop_materialized_view,
      sym_drop_function,
      sym_drop_keyspace,
      sym_drop_role,
      sym_drop_table,
      sym_drop_trigger,
      sym_drop_type,
      sym_drop_user,
      sym_create_aggregate,
      sym_create_materialized_view,
      sym_create_function,
      sym_create_keyspace,
      sym_create_role,
      sym_create_table,
      sym_create_trigger,
      sym_create_type,
      sym_create_user,
      sym_alter_materialized_view,
      sym_alter_keyspace,
      sym_alter_role,
      sym_alter_table,
      sym_alter_type,
      sym_alter_user,
      sym_apply_batch,
  [92] = 18,
    ACTIONS(5), 1,
      aux_sym_select_statement_token1,
    ACTIONS(7), 1,
      aux_sym_delete_statement_token1,
    ACTIONS(9), 1,
      aux_sym_begin_batch_token1,
    ACTIONS(11), 1,
      aux_sym_insert_statement_token1,
    ACTIONS(13), 1,
      aux_sym_truncate_token1,
    ACTIONS(15), 1,
      aux_sym_create_index_token1,
    ACTIONS(17), 1,
      aux_sym_drop_index_token1,
    ACTIONS(19), 1,
      aux_sym_update_token1,
    ACTIONS(21), 1,
      aux_sym_use_token1,
    ACTIONS(23), 1,
      aux_sym_grant_token1,
    ACTIONS(25), 1,
      aux_sym_revoke_token1,
    ACTIONS(27), 1,
      aux_sym_privilege_token3,
    ACTIONS(29), 1,
      aux_sym_list_roles_token1,
    ACTIONS(31), 1,
      aux_sym_apply_batch_token1,
    ACTIONS(77), 1,
      ts_builtin_sym_end,
    STATE(485), 1,
      sym_begin_batch,
    STATE(2), 2,
      sym__statement,
      aux_sym_source_file_repeat1,
    STATE(226), 37,
      sym_select_statement,
      sym_delete_statement,
      sym_insert_statement,
      sym_truncate,
      sym_create_index,
      sym_drop_index,
      sym_update,
      sym_use,
      sym_grant,
      sym_revoke,
      sym_list_roles,
      sym_list_permissions,
      sym_drop_aggregate,
      sym_drop_materialized_view,
      sym_drop_function,
      sym_drop_keyspace,
      sym_drop_role,
      sym_drop_table,
      sym_drop_trigger,
      sym_drop_type,
      sym_drop_user,
      sym_create_aggregate,
      sym_create_materialized_view,
      sym_create_function,
      sym_create_keyspace,
      sym_create_role,
      sym_create_table,
      sym_create_trigger,
      sym_create_type,
      sym_create_user,
      sym_alter_materialized_view,
      sym_alter_keyspace,
      sym_alter_role,
      sym_alter_table,
      sym_alter_type,
      sym_alter_user,
      sym_apply_batch,
  [184] = 11,
    ACTIONS(83), 1,
      aux_sym_collection_type_token1,
    ACTIONS(85), 1,
      aux_sym_tuple_type_token1,
    ACTIONS(87), 1,
      aux_sym_frozen_type_token1,
    ACTIONS(89), 1,
      sym_object_name,
    STATE(64), 1,
      sym_udt_name,
    STATE(71), 1,
      sym_cql_type,
    STATE(677), 1,
      sym_keyspace_name,
    STATE(906), 1,
      sym_data_type,
    ACTIONS(81), 2,
      aux_sym_update_assignments_token1,
      aux_sym_list_roles_token1,
    STATE(58), 5,
      sym_user_defined_type,
      sym_native_type,
      sym_collection_type,
      sym_tuple_type,
      sym_frozen_type,
    ACTIONS(79), 21,
      aux_sym_begin_batch_token4,
      aux_sym_using_timestamp_spec_token2,
      aux_sym_native_type_token1,
      aux_sym_native_type_token2,
      aux_sym_native_type_token3,
      aux_sym_native_type_token4,
      aux_sym_native_type_token5,
      aux_sym_native_type_token6,
      aux_sym_native_type_token7,
      aux_sym_native_type_token8,
      aux_sym_native_type_token9,
      aux_sym_native_type_token10,
      aux_sym_native_type_token11,
      aux_sym_native_type_token12,
      aux_sym_native_type_token13,
      aux_sym_native_type_token14,
      aux_sym_native_type_token15,
      aux_sym_native_type_token16,
      aux_sym_native_type_token17,
      aux_sym_native_type_token18,
      aux_sym_native_type_token19,
  [243] = 11,
    ACTIONS(83), 1,
      aux_sym_collection_type_token1,
    ACTIONS(85), 1,
      aux_sym_tuple_type_token1,
    ACTIONS(87), 1,
      aux_sym_frozen_type_token1,
    ACTIONS(89), 1,
      sym_object_name,
    STATE(64), 1,
      sym_udt_name,
    STATE(71), 1,
      sym_cql_type,
    STATE(384), 1,
      sym_data_type,
    STATE(677), 1,
      sym_keyspace_name,
    ACTIONS(81), 2,
      aux_sym_update_assignments_token1,
      aux_sym_list_roles_token1,
    STATE(58), 5,
      sym_user_defined_type,
      sym_native_type,
      sym_collection_type,
      sym_tuple_type,
      sym_frozen_type,
    ACTIONS(79), 21,
      aux_sym_begin_batch_token4,
      aux_sym_using_timestamp_spec_token2,
      aux_sym_native_type_token1,
      aux_sym_native_type_token2,
      aux_sym_native_type_token3,
      aux_sym_native_type_token4,
      aux_sym_native_type_token5,
      aux_sym_native_type_token6,
      aux_sym_native_type_token7,
      aux_sym_native_type_token8,
      aux_sym_native_type_token9,
      aux_sym_native_type_token10,
      aux_sym_native_type_token11,
      aux_sym_native_type_token12,
      aux_sym_native_type_token13,
      aux_sym_native_type_token14,
      aux_sym_native_type_token15,
      aux_sym_native_type_token16,
      aux_sym_native_type_token17,
      aux_sym_native_type_token18,
      aux_sym_native_type_token19,
  [302] = 11,
    ACTIONS(83), 1,
      aux_sym_collection_type_token1,
    ACTIONS(85), 1,
      aux_sym_tuple_type_token1,
    ACTIONS(87), 1,
      aux_sym_frozen_type_token1,
    ACTIONS(89), 1,
      sym_object_name,
    STATE(64), 1,
      sym_udt_name,
    STATE(71), 1,
      sym_cql_type,
    STATE(677), 1,
      sym_keyspace_name,
    STATE(824), 1,
      sym_data_type,
    ACTIONS(81), 2,
      aux_sym_update_assignments_token1,
      aux_sym_list_roles_token1,
    STATE(58), 5,
      sym_user_defined_type,
      sym_native_type,
      sym_collection_type,
      sym_tuple_type,
      sym_frozen_type,
    ACTIONS(79), 21,
      aux_sym_begin_batch_token4,
      aux_sym_using_timestamp_spec_token2,
      aux_sym_native_type_token1,
      aux_sym_native_type_token2,
      aux_sym_native_type_token3,
      aux_sym_native_type_token4,
      aux_sym_native_type_token5,
      aux_sym_native_type_token6,
      aux_sym_native_type_token7,
      aux_sym_native_type_token8,
      aux_sym_native_type_token9,
      aux_sym_native_type_token10,
      aux_sym_native_type_token11,
      aux_sym_native_type_token12,
      aux_sym_native_type_token13,
      aux_sym_native_type_token14,
      aux_sym_native_type_token15,
      aux_sym_native_type_token16,
      aux_sym_native_type_token17,
      aux_sym_native_type_token18,
      aux_sym_native_type_token19,
  [361] = 11,
    ACTIONS(83), 1,
      aux_sym_collection_type_token1,
    ACTIONS(85), 1,
      aux_sym_tuple_type_token1,
    ACTIONS(87), 1,
      aux_sym_frozen_type_token1,
    ACTIONS(89), 1,
      sym_object_name,
    STATE(64), 1,
      sym_udt_name,
    STATE(71), 1,
      sym_cql_type,
    STATE(272), 1,
      sym_data_type,
    STATE(677), 1,
      sym_keyspace_name,
    ACTIONS(81), 2,
      aux_sym_update_assignments_token1,
      aux_sym_list_roles_token1,
    STATE(58), 5,
      sym_user_defined_type,
      sym_native_type,
      sym_collection_type,
      sym_tuple_type,
      sym_frozen_type,
    ACTIONS(79), 21,
      aux_sym_begin_batch_token4,
      aux_sym_using_timestamp_spec_token2,
      aux_sym_native_type_token1,
      aux_sym_native_type_token2,
      aux_sym_native_type_token3,
      aux_sym_native_type_token4,
      aux_sym_native_type_token5,
      aux_sym_native_type_token6,
      aux_sym_native_type_token7,
      aux_sym_native_type_token8,
      aux_sym_native_type_token9,
      aux_sym_native_type_token10,
      aux_sym_native_type_token11,
      aux_sym_native_type_token12,
      aux_sym_native_type_token13,
      aux_sym_native_type_token14,
      aux_sym_native_type_token15,
      aux_sym_native_type_token16,
      aux_sym_native_type_token17,
      aux_sym_native_type_token18,
      aux_sym_native_type_token19,
  [420] = 11,
    ACTIONS(83), 1,
      aux_sym_collection_type_token1,
    ACTIONS(85), 1,
      aux_sym_tuple_type_token1,
    ACTIONS(87), 1,
      aux_sym_frozen_type_token1,
    ACTIONS(89), 1,
      sym_object_name,
    STATE(64), 1,
      sym_udt_name,
    STATE(71), 1,
      sym_cql_type,
    STATE(677), 1,
      sym_keyspace_name,
    STATE(792), 1,
      sym_data_type,
    ACTIONS(81), 2,
      aux_sym_update_assignments_token1,
      aux_sym_list_roles_token1,
    STATE(58), 5,
      sym_user_defined_type,
      sym_native_type,
      sym_collection_type,
      sym_tuple_type,
      sym_frozen_type,
    ACTIONS(79), 21,
      aux_sym_begin_batch_token4,
      aux_sym_using_timestamp_spec_token2,
      aux_sym_native_type_token1,
      aux_sym_native_type_token2,
      aux_sym_native_type_token3,
      aux_sym_native_type_token4,
      aux_sym_native_type_token5,
      aux_sym_native_type_token6,
      aux_sym_native_type_token7,
      aux_sym_native_type_token8,
      aux_sym_native_type_token9,
      aux_sym_native_type_token10,
      aux_sym_native_type_token11,
      aux_sym_native_type_token12,
      aux_sym_native_type_token13,
      aux_sym_native_type_token14,
      aux_sym_native_type_token15,
      aux_sym_native_type_token16,
      aux_sym_native_type_token17,
      aux_sym_native_type_token18,
      aux_sym_native_type_token19,
  [479] = 11,
    ACTIONS(83), 1,
      aux_sym_collection_type_token1,
    ACTIONS(85), 1,
      aux_sym_tuple_type_token1,
    ACTIONS(87), 1,
      aux_sym_frozen_type_token1,
    ACTIONS(89), 1,
      sym_object_name,
    STATE(64), 1,
      sym_udt_name,
    STATE(71), 1,
      sym_cql_type,
    STATE(677), 1,
      sym_keyspace_name,
    STATE(739), 1,
      sym_data_type,
    ACTIONS(81), 2,
      aux_sym_update_assignments_token1,
      aux_sym_list_roles_token1,
    STATE(58), 5,
      sym_user_defined_type,
      sym_native_type,
      sym_collection_type,
      sym_tuple_type,
      sym_frozen_type,
    ACTIONS(79), 21,
      aux_sym_begin_batch_token4,
      aux_sym_using_timestamp_spec_token2,
      aux_sym_native_type_token1,
      aux_sym_native_type_token2,
      aux_sym_native_type_token3,
      aux_sym_native_type_token4,
      aux_sym_native_type_token5,
      aux_sym_native_type_token6,
      aux_sym_native_type_token7,
      aux_sym_native_type_token8,
      aux_sym_native_type_token9,
      aux_sym_native_type_token10,
      aux_sym_native_type_token11,
      aux_sym_native_type_token12,
      aux_sym_native_type_token13,
      aux_sym_native_type_token14,
      aux_sym_native_type_token15,
      aux_sym_native_type_token16,
      aux_sym_native_type_token17,
      aux_sym_native_type_token18,
      aux_sym_native_type_token19,
  [538] = 11,
    ACTIONS(83), 1,
      aux_sym_collection_type_token1,
    ACTIONS(85), 1,
      aux_sym_tuple_type_token1,
    ACTIONS(87), 1,
      aux_sym_frozen_type_token1,
    ACTIONS(89), 1,
      sym_object_name,
    STATE(64), 1,
      sym_udt_name,
    STATE(71), 1,
      sym_cql_type,
    STATE(677), 1,
      sym_keyspace_name,
    STATE(881), 1,
      sym_data_type,
    ACTIONS(81), 2,
      aux_sym_update_assignments_token1,
      aux_sym_list_roles_token1,
    STATE(58), 5,
      sym_user_defined_type,
      sym_native_type,
      sym_collection_type,
      sym_tuple_type,
      sym_frozen_type,
    ACTIONS(79), 21,
      aux_sym_begin_batch_token4,
      aux_sym_using_timestamp_spec_token2,
      aux_sym_native_type_token1,
      aux_sym_native_type_token2,
      aux_sym_native_type_token3,
      aux_sym_native_type_token4,
      aux_sym_native_type_token5,
      aux_sym_native_type_token6,
      aux_sym_native_type_token7,
      aux_sym_native_type_token8,
      aux_sym_native_type_token9,
      aux_sym_native_type_token10,
      aux_sym_native_type_token11,
      aux_sym_native_type_token12,
      aux_sym_native_type_token13,
      aux_sym_native_type_token14,
      aux_sym_native_type_token15,
      aux_sym_native_type_token16,
      aux_sym_native_type_token17,
      aux_sym_native_type_token18,
      aux_sym_native_type_token19,
  [597] = 11,
    ACTIONS(83), 1,
      aux_sym_collection_type_token1,
    ACTIONS(85), 1,
      aux_sym_tuple_type_token1,
    ACTIONS(87), 1,
      aux_sym_frozen_type_token1,
    ACTIONS(89), 1,
      sym_object_name,
    STATE(64), 1,
      sym_udt_name,
    STATE(71), 1,
      sym_cql_type,
    STATE(137), 1,
      sym_data_type,
    STATE(677), 1,
      sym_keyspace_name,
    ACTIONS(81), 2,
      aux_sym_update_assignments_token1,
      aux_sym_list_roles_token1,
    STATE(58), 5,
      sym_user_defined_type,
      sym_native_type,
      sym_collection_type,
      sym_tuple_type,
      sym_frozen_type,
    ACTIONS(79), 21,
      aux_sym_begin_batch_token4,
      aux_sym_using_timestamp_spec_token2,
      aux_sym_native_type_token1,
      aux_sym_native_type_token2,
      aux_sym_native_type_token3,
      aux_sym_native_type_token4,
      aux_sym_native_type_token5,
      aux_sym_native_type_token6,
      aux_sym_native_type_token7,
      aux_sym_native_type_token8,
      aux_sym_native_type_token9,
      aux_sym_native_type_token10,
      aux_sym_native_type_token11,
      aux_sym_native_type_token12,
      aux_sym_native_type_token13,
      aux_sym_native_type_token14,
      aux_sym_native_type_token15,
      aux_sym_native_type_token16,
      aux_sym_native_type_token17,
      aux_sym_native_type_token18,
      aux_sym_native_type_token19,
  [656] = 11,
    ACTIONS(83), 1,
      aux_sym_collection_type_token1,
    ACTIONS(85), 1,
      aux_sym_tuple_type_token1,
    ACTIONS(87), 1,
      aux_sym_frozen_type_token1,
    ACTIONS(89), 1,
      sym_object_name,
    STATE(64), 1,
      sym_udt_name,
    STATE(71), 1,
      sym_cql_type,
    STATE(677), 1,
      sym_keyspace_name,
    STATE(681), 1,
      sym_data_type,
    ACTIONS(81), 2,
      aux_sym_update_assignments_token1,
      aux_sym_list_roles_token1,
    STATE(58), 5,
      sym_user_defined_type,
      sym_native_type,
      sym_collection_type,
      sym_tuple_type,
      sym_frozen_type,
    ACTIONS(79), 21,
      aux_sym_begin_batch_token4,
      aux_sym_using_timestamp_spec_token2,
      aux_sym_native_type_token1,
      aux_sym_native_type_token2,
      aux_sym_native_type_token3,
      aux_sym_native_type_token4,
      aux_sym_native_type_token5,
      aux_sym_native_type_token6,
      aux_sym_native_type_token7,
      aux_sym_native_type_token8,
      aux_sym_native_type_token9,
      aux_sym_native_type_token10,
      aux_sym_native_type_token11,
      aux_sym_native_type_token12,
      aux_sym_native_type_token13,
      aux_sym_native_type_token14,
      aux_sym_native_type_token15,
      aux_sym_native_type_token16,
      aux_sym_native_type_token17,
      aux_sym_native_type_token18,
      aux_sym_native_type_token19,
  [715] = 11,
    ACTIONS(83), 1,
      aux_sym_collection_type_token1,
    ACTIONS(85), 1,
      aux_sym_tuple_type_token1,
    ACTIONS(87), 1,
      aux_sym_frozen_type_token1,
    ACTIONS(89), 1,
      sym_object_name,
    STATE(64), 1,
      sym_udt_name,
    STATE(71), 1,
      sym_cql_type,
    STATE(677), 1,
      sym_keyspace_name,
    STATE(878), 1,
      sym_data_type,
    ACTIONS(81), 2,
      aux_sym_update_assignments_token1,
      aux_sym_list_roles_token1,
    STATE(58), 5,
      sym_user_defined_type,
      sym_native_type,
      sym_collection_type,
      sym_tuple_type,
      sym_frozen_type,
    ACTIONS(79), 21,
      aux_sym_begin_batch_token4,
      aux_sym_using_timestamp_spec_token2,
      aux_sym_native_type_token1,
      aux_sym_native_type_token2,
      aux_sym_native_type_token3,
      aux_sym_native_type_token4,
      aux_sym_native_type_token5,
      aux_sym_native_type_token6,
      aux_sym_native_type_token7,
      aux_sym_native_type_token8,
      aux_sym_native_type_token9,
      aux_sym_native_type_token10,
      aux_sym_native_type_token11,
      aux_sym_native_type_token12,
      aux_sym_native_type_token13,
      aux_sym_native_type_token14,
      aux_sym_native_type_token15,
      aux_sym_native_type_token16,
      aux_sym_native_type_token17,
      aux_sym_native_type_token18,
      aux_sym_native_type_token19,
  [774] = 11,
    ACTIONS(83), 1,
      aux_sym_collection_type_token1,
    ACTIONS(85), 1,
      aux_sym_tuple_type_token1,
    ACTIONS(87), 1,
      aux_sym_frozen_type_token1,
    ACTIONS(89), 1,
      sym_object_name,
    STATE(64), 1,
      sym_udt_name,
    STATE(71), 1,
      sym_cql_type,
    STATE(677), 1,
      sym_keyspace_name,
    STATE(801), 1,
      sym_data_type,
    ACTIONS(81), 2,
      aux_sym_update_assignments_token1,
      aux_sym_list_roles_token1,
    STATE(58), 5,
      sym_user_defined_type,
      sym_native_type,
      sym_collection_type,
      sym_tuple_type,
      sym_frozen_type,
    ACTIONS(79), 21,
      aux_sym_begin_batch_token4,
      aux_sym_using_timestamp_spec_token2,
      aux_sym_native_type_token1,
      aux_sym_native_type_token2,
      aux_sym_native_type_token3,
      aux_sym_native_type_token4,
      aux_sym_native_type_token5,
      aux_sym_native_type_token6,
      aux_sym_native_type_token7,
      aux_sym_native_type_token8,
      aux_sym_native_type_token9,
      aux_sym_native_type_token10,
      aux_sym_native_type_token11,
      aux_sym_native_type_token12,
      aux_sym_native_type_token13,
      aux_sym_native_type_token14,
      aux_sym_native_type_token15,
      aux_sym_native_type_token16,
      aux_sym_native_type_token17,
      aux_sym_native_type_token18,
      aux_sym_native_type_token19,
  [833] = 11,
    ACTIONS(83), 1,
      aux_sym_collection_type_token1,
    ACTIONS(85), 1,
      aux_sym_tuple_type_token1,
    ACTIONS(87), 1,
      aux_sym_frozen_type_token1,
    ACTIONS(89), 1,
      sym_object_name,
    STATE(64), 1,
      sym_udt_name,
    STATE(71), 1,
      sym_cql_type,
    STATE(677), 1,
      sym_keyspace_name,
    STATE(854), 1,
      sym_data_type,
    ACTIONS(81), 2,
      aux_sym_update_assignments_token1,
      aux_sym_list_roles_token1,
    STATE(58), 5,
      sym_user_defined_type,
      sym_native_type,
      sym_collection_type,
      sym_tuple_type,
      sym_frozen_type,
    ACTIONS(79), 21,
      aux_sym_begin_batch_token4,
      aux_sym_using_timestamp_spec_token2,
      aux_sym_native_type_token1,
      aux_sym_native_type_token2,
      aux_sym_native_type_token3,
      aux_sym_native_type_token4,
      aux_sym_native_type_token5,
      aux_sym_native_type_token6,
      aux_sym_native_type_token7,
      aux_sym_native_type_token8,
      aux_sym_native_type_token9,
      aux_sym_native_type_token10,
      aux_sym_native_type_token11,
      aux_sym_native_type_token12,
      aux_sym_native_type_token13,
      aux_sym_native_type_token14,
      aux_sym_native_type_token15,
      aux_sym_native_type_token16,
      aux_sym_native_type_token17,
      aux_sym_native_type_token18,
      aux_sym_native_type_token19,
  [892] = 11,
    ACTIONS(83), 1,
      aux_sym_collection_type_token1,
    ACTIONS(85), 1,
      aux_sym_tuple_type_token1,
    ACTIONS(87), 1,
      aux_sym_frozen_type_token1,
    ACTIONS(89), 1,
      sym_object_name,
    STATE(64), 1,
      sym_udt_name,
    STATE(71), 1,
      sym_cql_type,
    STATE(677), 1,
      sym_keyspace_name,
    STATE(686), 1,
      sym_data_type,
    ACTIONS(81), 2,
      aux_sym_update_assignments_token1,
      aux_sym_list_roles_token1,
    STATE(58), 5,
      sym_user_defined_type,
      sym_native_type,
      sym_collection_type,
      sym_tuple_type,
      sym_frozen_type,
    ACTIONS(79), 21,
      aux_sym_begin_batch_token4,
      aux_sym_using_timestamp_spec_token2,
      aux_sym_native_type_token1,
      aux_sym_native_type_token2,
      aux_sym_native_type_token3,
      aux_sym_native_type_token4,
      aux_sym_native_type_token5,
      aux_sym_native_type_token6,
      aux_sym_native_type_token7,
      aux_sym_native_type_token8,
      aux_sym_native_type_token9,
      aux_sym_native_type_token10,
      aux_sym_native_type_token11,
      aux_sym_native_type_token12,
      aux_sym_native_type_token13,
      aux_sym_native_type_token14,
      aux_sym_native_type_token15,
      aux_sym_native_type_token16,
      aux_sym_native_type_token17,
      aux_sym_native_type_token18,
      aux_sym_native_type_token19,
  [951] = 11,
    ACTIONS(83), 1,
      aux_sym_collection_type_token1,
    ACTIONS(85), 1,
      aux_sym_tuple_type_token1,
    ACTIONS(87), 1,
      aux_sym_frozen_type_token1,
    ACTIONS(89), 1,
      sym_object_name,
    STATE(64), 1,
      sym_udt_name,
    STATE(71), 1,
      sym_cql_type,
    STATE(677), 1,
      sym_keyspace_name,
    STATE(799), 1,
      sym_data_type,
    ACTIONS(81), 2,
      aux_sym_update_assignments_token1,
      aux_sym_list_roles_token1,
    STATE(58), 5,
      sym_user_defined_type,
      sym_native_type,
      sym_collection_type,
      sym_tuple_type,
      sym_frozen_type,
    ACTIONS(79), 21,
      aux_sym_begin_batch_token4,
      aux_sym_using_timestamp_spec_token2,
      aux_sym_native_type_token1,
      aux_sym_native_type_token2,
      aux_sym_native_type_token3,
      aux_sym_native_type_token4,
      aux_sym_native_type_token5,
      aux_sym_native_type_token6,
      aux_sym_native_type_token7,
      aux_sym_native_type_token8,
      aux_sym_native_type_token9,
      aux_sym_native_type_token10,
      aux_sym_native_type_token11,
      aux_sym_native_type_token12,
      aux_sym_native_type_token13,
      aux_sym_native_type_token14,
      aux_sym_native_type_token15,
      aux_sym_native_type_token16,
      aux_sym_native_type_token17,
      aux_sym_native_type_token18,
      aux_sym_native_type_token19,
  [1010] = 11,
    ACTIONS(83), 1,
      aux_sym_collection_type_token1,
    ACTIONS(85), 1,
      aux_sym_tuple_type_token1,
    ACTIONS(87), 1,
      aux_sym_frozen_type_token1,
    ACTIONS(89), 1,
      sym_object_name,
    STATE(64), 1,
      sym_udt_name,
    STATE(71), 1,
      sym_cql_type,
    STATE(677), 1,
      sym_keyspace_name,
    STATE(678), 1,
      sym_data_type,
    ACTIONS(81), 2,
      aux_sym_update_assignments_token1,
      aux_sym_list_roles_token1,
    STATE(58), 5,
      sym_user_defined_type,
      sym_native_type,
      sym_collection_type,
      sym_tuple_type,
      sym_frozen_type,
    ACTIONS(79), 21,
      aux_sym_begin_batch_token4,
      aux_sym_using_timestamp_spec_token2,
      aux_sym_native_type_token1,
      aux_sym_native_type_token2,
      aux_sym_native_type_token3,
      aux_sym_native_type_token4,
      aux_sym_native_type_token5,
      aux_sym_native_type_token6,
      aux_sym_native_type_token7,
      aux_sym_native_type_token8,
      aux_sym_native_type_token9,
      aux_sym_native_type_token10,
      aux_sym_native_type_token11,
      aux_sym_native_type_token12,
      aux_sym_native_type_token13,
      aux_sym_native_type_token14,
      aux_sym_native_type_token15,
      aux_sym_native_type_token16,
      aux_sym_native_type_token17,
      aux_sym_native_type_token18,
      aux_sym_native_type_token19,
  [1069] = 11,
    ACTIONS(83), 1,
      aux_sym_collection_type_token1,
    ACTIONS(85), 1,
      aux_sym_tuple_type_token1,
    ACTIONS(87), 1,
      aux_sym_frozen_type_token1,
    ACTIONS(89), 1,
      sym_object_name,
    STATE(64), 1,
      sym_udt_name,
    STATE(71), 1,
      sym_cql_type,
    STATE(677), 1,
      sym_keyspace_name,
    STATE(805), 1,
      sym_data_type,
    ACTIONS(81), 2,
      aux_sym_update_assignments_token1,
      aux_sym_list_roles_token1,
    STATE(58), 5,
      sym_user_defined_type,
      sym_native_type,
      sym_collection_type,
      sym_tuple_type,
      sym_frozen_type,
    ACTIONS(79), 21,
      aux_sym_begin_batch_token4,
      aux_sym_using_timestamp_spec_token2,
      aux_sym_native_type_token1,
      aux_sym_native_type_token2,
      aux_sym_native_type_token3,
      aux_sym_native_type_token4,
      aux_sym_native_type_token5,
      aux_sym_native_type_token6,
      aux_sym_native_type_token7,
      aux_sym_native_type_token8,
      aux_sym_native_type_token9,
      aux_sym_native_type_token10,
      aux_sym_native_type_token11,
      aux_sym_native_type_token12,
      aux_sym_native_type_token13,
      aux_sym_native_type_token14,
      aux_sym_native_type_token15,
      aux_sym_native_type_token16,
      aux_sym_native_type_token17,
      aux_sym_native_type_token18,
      aux_sym_native_type_token19,
  [1128] = 11,
    ACTIONS(83), 1,
      aux_sym_collection_type_token1,
    ACTIONS(85), 1,
      aux_sym_tuple_type_token1,
    ACTIONS(87), 1,
      aux_sym_frozen_type_token1,
    ACTIONS(89), 1,
      sym_object_name,
    STATE(64), 1,
      sym_udt_name,
    STATE(71), 1,
      sym_cql_type,
    STATE(677), 1,
      sym_keyspace_name,
    STATE(870), 1,
      sym_data_type,
    ACTIONS(81), 2,
      aux_sym_update_assignments_token1,
      aux_sym_list_roles_token1,
    STATE(58), 5,
      sym_user_defined_type,
      sym_native_type,
      sym_collection_type,
      sym_tuple_type,
      sym_frozen_type,
    ACTIONS(79), 21,
      aux_sym_begin_batch_token4,
      aux_sym_using_timestamp_spec_token2,
      aux_sym_native_type_token1,
      aux_sym_native_type_token2,
      aux_sym_native_type_token3,
      aux_sym_native_type_token4,
      aux_sym_native_type_token5,
      aux_sym_native_type_token6,
      aux_sym_native_type_token7,
      aux_sym_native_type_token8,
      aux_sym_native_type_token9,
      aux_sym_native_type_token10,
      aux_sym_native_type_token11,
      aux_sym_native_type_token12,
      aux_sym_native_type_token13,
      aux_sym_native_type_token14,
      aux_sym_native_type_token15,
      aux_sym_native_type_token16,
      aux_sym_native_type_token17,
      aux_sym_native_type_token18,
      aux_sym_native_type_token19,
  [1187] = 11,
    ACTIONS(83), 1,
      aux_sym_collection_type_token1,
    ACTIONS(85), 1,
      aux_sym_tuple_type_token1,
    ACTIONS(87), 1,
      aux_sym_frozen_type_token1,
    ACTIONS(89), 1,
      sym_object_name,
    STATE(64), 1,
      sym_udt_name,
    STATE(71), 1,
      sym_cql_type,
    STATE(677), 1,
      sym_keyspace_name,
    STATE(922), 1,
      sym_data_type,
    ACTIONS(81), 2,
      aux_sym_update_assignments_token1,
      aux_sym_list_roles_token1,
    STATE(58), 5,
      sym_user_defined_type,
      sym_native_type,
      sym_collection_type,
      sym_tuple_type,
      sym_frozen_type,
    ACTIONS(79), 21,
      aux_sym_begin_batch_token4,
      aux_sym_using_timestamp_spec_token2,
      aux_sym_native_type_token1,
      aux_sym_native_type_token2,
      aux_sym_native_type_token3,
      aux_sym_native_type_token4,
      aux_sym_native_type_token5,
      aux_sym_native_type_token6,
      aux_sym_native_type_token7,
      aux_sym_native_type_token8,
      aux_sym_native_type_token9,
      aux_sym_native_type_token10,
      aux_sym_native_type_token11,
      aux_sym_native_type_token12,
      aux_sym_native_type_token13,
      aux_sym_native_type_token14,
      aux_sym_native_type_token15,
      aux_sym_native_type_token16,
      aux_sym_native_type_token17,
      aux_sym_native_type_token18,
      aux_sym_native_type_token19,
  [1246] = 11,
    ACTIONS(83), 1,
      aux_sym_collection_type_token1,
    ACTIONS(85), 1,
      aux_sym_tuple_type_token1,
    ACTIONS(87), 1,
      aux_sym_frozen_type_token1,
    ACTIONS(89), 1,
      sym_object_name,
    STATE(64), 1,
      sym_udt_name,
    STATE(71), 1,
      sym_cql_type,
    STATE(677), 1,
      sym_keyspace_name,
    STATE(921), 1,
      sym_data_type,
    ACTIONS(81), 2,
      aux_sym_update_assignments_token1,
      aux_sym_list_roles_token1,
    STATE(58), 5,
      sym_user_defined_type,
      sym_native_type,
      sym_collection_type,
      sym_tuple_type,
      sym_frozen_type,
    ACTIONS(79), 21,
      aux_sym_begin_batch_token4,
      aux_sym_using_timestamp_spec_token2,
      aux_sym_native_type_token1,
      aux_sym_native_type_token2,
      aux_sym_native_type_token3,
      aux_sym_native_type_token4,
      aux_sym_native_type_token5,
      aux_sym_native_type_token6,
      aux_sym_native_type_token7,
      aux_sym_native_type_token8,
      aux_sym_native_type_token9,
      aux_sym_native_type_token10,
      aux_sym_native_type_token11,
      aux_sym_native_type_token12,
      aux_sym_native_type_token13,
      aux_sym_native_type_token14,
      aux_sym_native_type_token15,
      aux_sym_native_type_token16,
      aux_sym_native_type_token17,
      aux_sym_native_type_token18,
      aux_sym_native_type_token19,
  [1305] = 10,
    ACTIONS(83), 1,
      aux_sym_collection_type_token1,
    ACTIONS(85), 1,
      aux_sym_tuple_type_token1,
    ACTIONS(87), 1,
      aux_sym_frozen_type_token1,
    ACTIONS(89), 1,
      sym_object_name,
    STATE(64), 1,
      sym_udt_name,
    STATE(449), 1,
      sym_cql_type,
    STATE(677), 1,
      sym_keyspace_name,
    ACTIONS(81), 2,
      aux_sym_update_assignments_token1,
      aux_sym_list_roles_token1,
    STATE(58), 5,
      sym_user_defined_type,
      sym_native_type,
      sym_collection_type,
      sym_tuple_type,
      sym_frozen_type,
    ACTIONS(79), 21,
      aux_sym_begin_batch_token4,
      aux_sym_using_timestamp_spec_token2,
      aux_sym_native_type_token1,
      aux_sym_native_type_token2,
      aux_sym_native_type_token3,
      aux_sym_native_type_token4,
      aux_sym_native_type_token5,
      aux_sym_native_type_token6,
      aux_sym_native_type_token7,
      aux_sym_native_type_token8,
      aux_sym_native_type_token9,
      aux_sym_native_type_token10,
      aux_sym_native_type_token11,
      aux_sym_native_type_token12,
      aux_sym_native_type_token13,
      aux_sym_native_type_token14,
      aux_sym_native_type_token15,
      aux_sym_native_type_token16,
      aux_sym_native_type_token17,
      aux_sym_native_type_token18,
      aux_sym_native_type_token19,
  [1361] = 10,
    ACTIONS(83), 1,
      aux_sym_collection_type_token1,
    ACTIONS(85), 1,
      aux_sym_tuple_type_token1,
    ACTIONS(87), 1,
      aux_sym_frozen_type_token1,
    ACTIONS(89), 1,
      sym_object_name,
    STATE(64), 1,
      sym_udt_name,
    STATE(677), 1,
      sym_keyspace_name,
    STATE(813), 1,
      sym_cql_type,
    ACTIONS(81), 2,
      aux_sym_update_assignments_token1,
      aux_sym_list_roles_token1,
    STATE(58), 5,
      sym_user_defined_type,
      sym_native_type,
      sym_collection_type,
      sym_tuple_type,
      sym_frozen_type,
    ACTIONS(79), 21,
      aux_sym_begin_batch_token4,
      aux_sym_using_timestamp_spec_token2,
      aux_sym_native_type_token1,
      aux_sym_native_type_token2,
      aux_sym_native_type_token3,
      aux_sym_native_type_token4,
      aux_sym_native_type_token5,
      aux_sym_native_type_token6,
      aux_sym_native_type_token7,
      aux_sym_native_type_token8,
      aux_sym_native_type_token9,
      aux_sym_native_type_token10,
      aux_sym_native_type_token11,
      aux_sym_native_type_token12,
      aux_sym_native_type_token13,
      aux_sym_native_type_token14,
      aux_sym_native_type_token15,
      aux_sym_native_type_token16,
      aux_sym_native_type_token17,
      aux_sym_native_type_token18,
      aux_sym_native_type_token19,
  [1417] = 10,
    ACTIONS(83), 1,
      aux_sym_collection_type_token1,
    ACTIONS(85), 1,
      aux_sym_tuple_type_token1,
    ACTIONS(87), 1,
      aux_sym_frozen_type_token1,
    ACTIONS(89), 1,
      sym_object_name,
    STATE(64), 1,
      sym_udt_name,
    STATE(677), 1,
      sym_keyspace_name,
    STATE(819), 1,
      sym_cql_type,
    ACTIONS(81), 2,
      aux_sym_update_assignments_token1,
      aux_sym_list_roles_token1,
    STATE(58), 5,
      sym_user_defined_type,
      sym_native_type,
      sym_collection_type,
      sym_tuple_type,
      sym_frozen_type,
    ACTIONS(79), 21,
      aux_sym_begin_batch_token4,
      aux_sym_using_timestamp_spec_token2,
      aux_sym_native_type_token1,
      aux_sym_native_type_token2,
      aux_sym_native_type_token3,
      aux_sym_native_type_token4,
      aux_sym_native_type_token5,
      aux_sym_native_type_token6,
      aux_sym_native_type_token7,
      aux_sym_native_type_token8,
      aux_sym_native_type_token9,
      aux_sym_native_type_token10,
      aux_sym_native_type_token11,
      aux_sym_native_type_token12,
      aux_sym_native_type_token13,
      aux_sym_native_type_token14,
      aux_sym_native_type_token15,
      aux_sym_native_type_token16,
      aux_sym_native_type_token17,
      aux_sym_native_type_token18,
      aux_sym_native_type_token19,
  [1473] = 10,
    ACTIONS(83), 1,
      aux_sym_collection_type_token1,
    ACTIONS(85), 1,
      aux_sym_tuple_type_token1,
    ACTIONS(87), 1,
      aux_sym_frozen_type_token1,
    ACTIONS(89), 1,
      sym_object_name,
    STATE(64), 1,
      sym_udt_name,
    STATE(677), 1,
      sym_keyspace_name,
    STATE(820), 1,
      sym_cql_type,
    ACTIONS(81), 2,
      aux_sym_update_assignments_token1,
      aux_sym_list_roles_token1,
    STATE(58), 5,
      sym_user_defined_type,
      sym_native_type,
      sym_collection_type,
      sym_tuple_type,
      sym_frozen_type,
    ACTIONS(79), 21,
      aux_sym_begin_batch_token4,
      aux_sym_using_timestamp_spec_token2,
      aux_sym_native_type_token1,
      aux_sym_native_type_token2,
      aux_sym_native_type_token3,
      aux_sym_native_type_token4,
      aux_sym_native_type_token5,
      aux_sym_native_type_token6,
      aux_sym_native_type_token7,
      aux_sym_native_type_token8,
      aux_sym_native_type_token9,
      aux_sym_native_type_token10,
      aux_sym_native_type_token11,
      aux_sym_native_type_token12,
      aux_sym_native_type_token13,
      aux_sym_native_type_token14,
      aux_sym_native_type_token15,
      aux_sym_native_type_token16,
      aux_sym_native_type_token17,
      aux_sym_native_type_token18,
      aux_sym_native_type_token19,
  [1529] = 10,
    ACTIONS(83), 1,
      aux_sym_collection_type_token1,
    ACTIONS(85), 1,
      aux_sym_tuple_type_token1,
    ACTIONS(87), 1,
      aux_sym_frozen_type_token1,
    ACTIONS(89), 1,
      sym_object_name,
    STATE(64), 1,
      sym_udt_name,
    STATE(677), 1,
      sym_keyspace_name,
    STATE(746), 1,
      sym_cql_type,
    ACTIONS(81), 2,
      aux_sym_update_assignments_token1,
      aux_sym_list_roles_token1,
    STATE(58), 5,
      sym_user_defined_type,
      sym_native_type,
      sym_collection_type,
      sym_tuple_type,
      sym_frozen_type,
    ACTIONS(79), 21,
      aux_sym_begin_batch_token4,
      aux_sym_using_timestamp_spec_token2,
      aux_sym_native_type_token1,
      aux_sym_native_type_token2,
      aux_sym_native_type_token3,
      aux_sym_native_type_token4,
      aux_sym_native_type_token5,
      aux_sym_native_type_token6,
      aux_sym_native_type_token7,
      aux_sym_native_type_token8,
      aux_sym_native_type_token9,
      aux_sym_native_type_token10,
      aux_sym_native_type_token11,
      aux_sym_native_type_token12,
      aux_sym_native_type_token13,
      aux_sym_native_type_token14,
      aux_sym_native_type_token15,
      aux_sym_native_type_token16,
      aux_sym_native_type_token17,
      aux_sym_native_type_token18,
      aux_sym_native_type_token19,
  [1585] = 10,
    ACTIONS(83), 1,
      aux_sym_collection_type_token1,
    ACTIONS(85), 1,
      aux_sym_tuple_type_token1,
    ACTIONS(87), 1,
      aux_sym_frozen_type_token1,
    ACTIONS(89), 1,
      sym_object_name,
    STATE(64), 1,
      sym_udt_name,
    STATE(633), 1,
      sym_cql_type,
    STATE(677), 1,
      sym_keyspace_name,
    ACTIONS(81), 2,
      aux_sym_update_assignments_token1,
      aux_sym_list_roles_token1,
    STATE(58), 5,
      sym_user_defined_type,
      sym_native_type,
      sym_collection_type,
      sym_tuple_type,
      sym_frozen_type,
    ACTIONS(79), 21,
      aux_sym_begin_batch_token4,
      aux_sym_using_timestamp_spec_token2,
      aux_sym_native_type_token1,
      aux_sym_native_type_token2,
      aux_sym_native_type_token3,
      aux_sym_native_type_token4,
      aux_sym_native_type_token5,
      aux_sym_native_type_token6,
      aux_sym_native_type_token7,
      aux_sym_native_type_token8,
      aux_sym_native_type_token9,
      aux_sym_native_type_token10,
      aux_sym_native_type_token11,
      aux_sym_native_type_token12,
      aux_sym_native_type_token13,
      aux_sym_native_type_token14,
      aux_sym_native_type_token15,
      aux_sym_native_type_token16,
      aux_sym_native_type_token17,
      aux_sym_native_type_token18,
      aux_sym_native_type_token19,
  [1641] = 2,
    ACTIONS(93), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(91), 30,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_select_statement_token4,
      aux_sym_limit_spec_token1,
      anon_sym_COMMA,
      aux_sym_select_element_token1,
      anon_sym_RPAREN,
      aux_sym_from_spec_token1,
      aux_sym_relation_elements_token1,
      anon_sym_LT_EQ,
      anon_sym_LT_GT,
      anon_sym_EQ,
      anon_sym_GT_EQ,
      aux_sym_order_spec_token1,
      aux_sym_delete_statement_token1,
      aux_sym_delete_statement_token2,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_primary_key_column_token1,
      aux_sym_apply_batch_token1,
  [1678] = 1,
    ACTIONS(95), 29,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_select_statement_token4,
      aux_sym_limit_spec_token1,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_COLON,
      aux_sym_where_spec_token1,
      aux_sym_relation_elements_token1,
      aux_sym_order_spec_token1,
      aux_sym_delete_statement_token1,
      aux_sym_delete_statement_token2,
      aux_sym_begin_batch_token1,
      anon_sym_RBRACK,
      aux_sym_using_timestamp_spec_token1,
      aux_sym_insert_statement_token1,
      anon_sym_RBRACE,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_primary_key_column_token1,
      aux_sym_apply_batch_token1,
  [1710] = 1,
    ACTIONS(97), 29,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_select_statement_token4,
      aux_sym_limit_spec_token1,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_COLON,
      aux_sym_where_spec_token1,
      aux_sym_relation_elements_token1,
      aux_sym_order_spec_token1,
      aux_sym_delete_statement_token1,
      aux_sym_delete_statement_token2,
      aux_sym_begin_batch_token1,
      anon_sym_RBRACK,
      aux_sym_using_timestamp_spec_token1,
      aux_sym_insert_statement_token1,
      anon_sym_RBRACE,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_primary_key_column_token1,
      aux_sym_apply_batch_token1,
  [1742] = 2,
    ACTIONS(101), 1,
      anon_sym_DOT,
    ACTIONS(99), 26,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_select_statement_token4,
      aux_sym_limit_spec_token1,
      anon_sym_LPAREN,
      aux_sym_where_spec_token1,
      aux_sym_order_spec_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_using_timestamp_spec_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_update_assignments_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_create_keyspace_token1,
      aux_sym_alter_table_add_token1,
      aux_sym_alter_table_rename_token1,
      aux_sym_apply_batch_token1,
  [1774] = 1,
    ACTIONS(103), 26,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_select_statement_token4,
      aux_sym_limit_spec_token1,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      aux_sym_relation_elements_token1,
      aux_sym_order_spec_token1,
      aux_sym_delete_statement_token1,
      aux_sym_delete_statement_token2,
      aux_sym_begin_batch_token1,
      anon_sym_RBRACK,
      aux_sym_insert_statement_token1,
      anon_sym_RBRACE,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_primary_key_column_token1,
      aux_sym_apply_batch_token1,
  [1803] = 1,
    ACTIONS(105), 26,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_select_statement_token4,
      aux_sym_limit_spec_token1,
      anon_sym_LPAREN,
      aux_sym_where_spec_token1,
      aux_sym_order_spec_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_using_timestamp_spec_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_update_assignments_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_create_keyspace_token1,
      aux_sym_alter_table_add_token1,
      aux_sym_alter_table_rename_token1,
      aux_sym_apply_batch_token1,
  [1832] = 1,
    ACTIONS(107), 26,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_select_statement_token4,
      aux_sym_limit_spec_token1,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      aux_sym_relation_elements_token1,
      aux_sym_order_spec_token1,
      aux_sym_delete_statement_token1,
      aux_sym_delete_statement_token2,
      aux_sym_begin_batch_token1,
      anon_sym_RBRACK,
      aux_sym_insert_statement_token1,
      anon_sym_RBRACE,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_primary_key_column_token1,
      aux_sym_apply_batch_token1,
  [1861] = 3,
    ACTIONS(111), 1,
      anon_sym_COMMA,
    STATE(36), 1,
      aux_sym_relation_element_repeat2,
    ACTIONS(109), 23,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_select_statement_token4,
      aux_sym_limit_spec_token1,
      anon_sym_RPAREN,
      aux_sym_relation_elements_token1,
      aux_sym_order_spec_token1,
      aux_sym_delete_statement_token1,
      aux_sym_delete_statement_token2,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_primary_key_column_token1,
      aux_sym_apply_batch_token1,
  [1893] = 3,
    ACTIONS(116), 1,
      anon_sym_COMMA,
    STATE(41), 1,
      aux_sym_relation_element_repeat2,
    ACTIONS(114), 22,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_select_statement_token4,
      aux_sym_limit_spec_token1,
      aux_sym_relation_elements_token1,
      aux_sym_order_spec_token1,
      aux_sym_delete_statement_token1,
      aux_sym_delete_statement_token2,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_primary_key_column_token1,
      aux_sym_apply_batch_token1,
  [1924] = 1,
    ACTIONS(109), 24,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_select_statement_token4,
      aux_sym_limit_spec_token1,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      aux_sym_relation_elements_token1,
      aux_sym_order_spec_token1,
      aux_sym_delete_statement_token1,
      aux_sym_delete_statement_token2,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_primary_key_column_token1,
      aux_sym_apply_batch_token1,
  [1951] = 3,
    ACTIONS(116), 1,
      anon_sym_COMMA,
    STATE(36), 1,
      aux_sym_relation_element_repeat2,
    ACTIONS(114), 22,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_select_statement_token4,
      aux_sym_limit_spec_token1,
      aux_sym_relation_elements_token1,
      aux_sym_order_spec_token1,
      aux_sym_delete_statement_token1,
      aux_sym_delete_statement_token2,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_primary_key_column_token1,
      aux_sym_apply_batch_token1,
  [1982] = 1,
    ACTIONS(118), 24,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_select_statement_token4,
      aux_sym_limit_spec_token1,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      aux_sym_relation_elements_token1,
      aux_sym_order_spec_token1,
      aux_sym_delete_statement_token1,
      aux_sym_delete_statement_token2,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_primary_key_column_token1,
      aux_sym_apply_batch_token1,
  [2009] = 3,
    ACTIONS(116), 1,
      anon_sym_COMMA,
    STATE(36), 1,
      aux_sym_relation_element_repeat2,
    ACTIONS(120), 22,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_select_statement_token4,
      aux_sym_limit_spec_token1,
      aux_sym_relation_elements_token1,
      aux_sym_order_spec_token1,
      aux_sym_delete_statement_token1,
      aux_sym_delete_statement_token2,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_primary_key_column_token1,
      aux_sym_apply_batch_token1,
  [2040] = 3,
    ACTIONS(116), 1,
      anon_sym_COMMA,
    STATE(39), 1,
      aux_sym_relation_element_repeat2,
    ACTIONS(122), 22,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_select_statement_token4,
      aux_sym_limit_spec_token1,
      aux_sym_relation_elements_token1,
      aux_sym_order_spec_token1,
      aux_sym_delete_statement_token1,
      aux_sym_delete_statement_token2,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_primary_key_column_token1,
      aux_sym_apply_batch_token1,
  [2071] = 2,
    ACTIONS(126), 1,
      anon_sym_DOT,
    ACTIONS(124), 22,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_GT,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_create_aggregate_token5,
      aux_sym_create_function_token2,
      aux_sym_primary_key_column_token1,
      aux_sym_apply_batch_token1,
  [2099] = 8,
    ACTIONS(130), 1,
      aux_sym_select_statement_token4,
    ACTIONS(132), 1,
      aux_sym_limit_spec_token1,
    ACTIONS(134), 1,
      aux_sym_where_spec_token1,
    ACTIONS(136), 1,
      aux_sym_order_spec_token1,
    STATE(75), 1,
      sym_where_spec,
    STATE(93), 1,
      sym_order_spec,
    STATE(192), 1,
      sym_limit_spec,
    ACTIONS(128), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [2139] = 3,
    ACTIONS(140), 1,
      aux_sym_relation_elements_token1,
    STATE(45), 1,
      aux_sym_relation_elements_repeat1,
    ACTIONS(138), 21,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_select_statement_token4,
      aux_sym_limit_spec_token1,
      aux_sym_order_spec_token1,
      aux_sym_delete_statement_token1,
      aux_sym_delete_statement_token2,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_primary_key_column_token1,
      aux_sym_apply_batch_token1,
  [2169] = 8,
    ACTIONS(132), 1,
      aux_sym_limit_spec_token1,
    ACTIONS(134), 1,
      aux_sym_where_spec_token1,
    ACTIONS(136), 1,
      aux_sym_order_spec_token1,
    ACTIONS(145), 1,
      aux_sym_select_statement_token4,
    STATE(72), 1,
      sym_where_spec,
    STATE(101), 1,
      sym_order_spec,
    STATE(182), 1,
      sym_limit_spec,
    ACTIONS(143), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [2209] = 8,
    ACTIONS(132), 1,
      aux_sym_limit_spec_token1,
    ACTIONS(134), 1,
      aux_sym_where_spec_token1,
    ACTIONS(136), 1,
      aux_sym_order_spec_token1,
    ACTIONS(149), 1,
      aux_sym_select_statement_token4,
    STATE(74), 1,
      sym_where_spec,
    STATE(94), 1,
      sym_order_spec,
    STATE(163), 1,
      sym_limit_spec,
    ACTIONS(147), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [2249] = 1,
    ACTIONS(138), 22,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_select_statement_token4,
      aux_sym_limit_spec_token1,
      aux_sym_relation_elements_token1,
      aux_sym_order_spec_token1,
      aux_sym_delete_statement_token1,
      aux_sym_delete_statement_token2,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_primary_key_column_token1,
      aux_sym_apply_batch_token1,
  [2274] = 1,
    ACTIONS(151), 22,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_select_statement_token4,
      aux_sym_limit_spec_token1,
      aux_sym_relation_elements_token1,
      aux_sym_order_spec_token1,
      aux_sym_delete_statement_token1,
      aux_sym_delete_statement_token2,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_primary_key_column_token1,
      aux_sym_apply_batch_token1,
  [2299] = 1,
    ACTIONS(153), 22,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_GT,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_create_aggregate_token5,
      aux_sym_create_function_token2,
      aux_sym_primary_key_column_token1,
      aux_sym_apply_batch_token1,
  [2324] = 12,
    ACTIONS(155), 1,
      anon_sym_LPAREN,
    ACTIONS(159), 1,
      anon_sym_QMARK,
    ACTIONS(161), 1,
      anon_sym_COLON,
    ACTIONS(165), 1,
      aux_sym__decimal_literal_token1,
    ACTIONS(167), 1,
      anon_sym_LBRACK,
    ACTIONS(169), 1,
      anon_sym_LBRACE,
    STATE(31), 1,
      sym__decimal_literal,
    STATE(480), 1,
      sym_expression,
    STATE(928), 1,
      sym_expression_list,
    ACTIONS(163), 2,
      sym__string_literal,
      sym__float_literal,
    ACTIONS(157), 5,
      aux_sym_constant_token1,
      aux_sym_constant_token2,
      aux_sym_constant_token3,
      sym__boolean_literal,
      sym__code_block,
    STATE(552), 6,
      sym_constant,
      sym_bind_marker,
      sym_assignment_map,
      sym_assignment_set,
      sym_assignment_list,
      sym_assignment_tuple,
  [2371] = 1,
    ACTIONS(171), 22,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_GT,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_create_aggregate_token5,
      aux_sym_create_function_token2,
      aux_sym_primary_key_column_token1,
      aux_sym_apply_batch_token1,
  [2396] = 1,
    ACTIONS(173), 22,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_select_statement_token4,
      aux_sym_limit_spec_token1,
      aux_sym_relation_elements_token1,
      aux_sym_order_spec_token1,
      aux_sym_delete_statement_token1,
      aux_sym_delete_statement_token2,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_primary_key_column_token1,
      aux_sym_apply_batch_token1,
  [2421] = 1,
    ACTIONS(175), 22,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_select_statement_token4,
      aux_sym_limit_spec_token1,
      aux_sym_relation_elements_token1,
      aux_sym_order_spec_token1,
      aux_sym_delete_statement_token1,
      aux_sym_delete_statement_token2,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_primary_key_column_token1,
      aux_sym_apply_batch_token1,
  [2446] = 1,
    ACTIONS(177), 22,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_select_statement_token4,
      aux_sym_limit_spec_token1,
      aux_sym_relation_elements_token1,
      aux_sym_order_spec_token1,
      aux_sym_delete_statement_token1,
      aux_sym_delete_statement_token2,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_primary_key_column_token1,
      aux_sym_apply_batch_token1,
  [2471] = 1,
    ACTIONS(179), 22,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_select_statement_token4,
      aux_sym_limit_spec_token1,
      aux_sym_relation_elements_token1,
      aux_sym_order_spec_token1,
      aux_sym_delete_statement_token1,
      aux_sym_delete_statement_token2,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_primary_key_column_token1,
      aux_sym_apply_batch_token1,
  [2496] = 3,
    ACTIONS(183), 1,
      aux_sym_relation_elements_token1,
    STATE(45), 1,
      aux_sym_relation_elements_repeat1,
    ACTIONS(181), 20,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_select_statement_token4,
      aux_sym_limit_spec_token1,
      aux_sym_order_spec_token1,
      aux_sym_delete_statement_token1,
      aux_sym_delete_statement_token2,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [2525] = 1,
    ACTIONS(185), 22,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_GT,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_create_aggregate_token5,
      aux_sym_create_function_token2,
      aux_sym_primary_key_column_token1,
      aux_sym_apply_batch_token1,
  [2550] = 1,
    ACTIONS(187), 22,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_select_statement_token4,
      aux_sym_limit_spec_token1,
      aux_sym_relation_elements_token1,
      aux_sym_order_spec_token1,
      aux_sym_delete_statement_token1,
      aux_sym_delete_statement_token2,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_primary_key_column_token1,
      aux_sym_apply_batch_token1,
  [2575] = 3,
    ACTIONS(183), 1,
      aux_sym_relation_elements_token1,
    STATE(57), 1,
      aux_sym_relation_elements_repeat1,
    ACTIONS(189), 20,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_select_statement_token4,
      aux_sym_limit_spec_token1,
      aux_sym_order_spec_token1,
      aux_sym_delete_statement_token1,
      aux_sym_delete_statement_token2,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [2604] = 1,
    ACTIONS(191), 22,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_GT,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_create_aggregate_token5,
      aux_sym_create_function_token2,
      aux_sym_primary_key_column_token1,
      aux_sym_apply_batch_token1,
  [2629] = 12,
    ACTIONS(155), 1,
      anon_sym_LPAREN,
    ACTIONS(159), 1,
      anon_sym_QMARK,
    ACTIONS(161), 1,
      anon_sym_COLON,
    ACTIONS(165), 1,
      aux_sym__decimal_literal_token1,
    ACTIONS(167), 1,
      anon_sym_LBRACK,
    ACTIONS(169), 1,
      anon_sym_LBRACE,
    STATE(31), 1,
      sym__decimal_literal,
    STATE(480), 1,
      sym_expression,
    STATE(719), 1,
      sym_expression_list,
    ACTIONS(163), 2,
      sym__string_literal,
      sym__float_literal,
    ACTIONS(157), 5,
      aux_sym_constant_token1,
      aux_sym_constant_token2,
      aux_sym_constant_token3,
      sym__boolean_literal,
      sym__code_block,
    STATE(552), 6,
      sym_constant,
      sym_bind_marker,
      sym_assignment_map,
      sym_assignment_set,
      sym_assignment_list,
      sym_assignment_tuple,
  [2676] = 1,
    ACTIONS(193), 22,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_select_statement_token4,
      aux_sym_limit_spec_token1,
      aux_sym_relation_elements_token1,
      aux_sym_order_spec_token1,
      aux_sym_delete_statement_token1,
      aux_sym_delete_statement_token2,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_primary_key_column_token1,
      aux_sym_apply_batch_token1,
  [2701] = 1,
    ACTIONS(195), 22,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_GT,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_create_aggregate_token5,
      aux_sym_create_function_token2,
      aux_sym_primary_key_column_token1,
      aux_sym_apply_batch_token1,
  [2726] = 1,
    ACTIONS(197), 22,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_GT,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_create_aggregate_token5,
      aux_sym_create_function_token2,
      aux_sym_primary_key_column_token1,
      aux_sym_apply_batch_token1,
  [2751] = 1,
    ACTIONS(199), 22,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_GT,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_create_aggregate_token5,
      aux_sym_create_function_token2,
      aux_sym_primary_key_column_token1,
      aux_sym_apply_batch_token1,
  [2776] = 1,
    ACTIONS(120), 22,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_select_statement_token4,
      aux_sym_limit_spec_token1,
      aux_sym_relation_elements_token1,
      aux_sym_order_spec_token1,
      aux_sym_delete_statement_token1,
      aux_sym_delete_statement_token2,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_primary_key_column_token1,
      aux_sym_apply_batch_token1,
  [2801] = 1,
    ACTIONS(201), 22,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_GT,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_create_aggregate_token5,
      aux_sym_create_function_token2,
      aux_sym_primary_key_column_token1,
      aux_sym_apply_batch_token1,
  [2826] = 1,
    ACTIONS(203), 22,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_select_statement_token4,
      aux_sym_limit_spec_token1,
      aux_sym_relation_elements_token1,
      aux_sym_order_spec_token1,
      aux_sym_delete_statement_token1,
      aux_sym_delete_statement_token2,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_primary_key_column_token1,
      aux_sym_apply_batch_token1,
  [2851] = 1,
    ACTIONS(205), 22,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_GT,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_create_aggregate_token5,
      aux_sym_create_function_token2,
      aux_sym_primary_key_column_token1,
      aux_sym_apply_batch_token1,
  [2876] = 1,
    ACTIONS(207), 21,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_create_aggregate_token5,
      aux_sym_create_function_token2,
      aux_sym_primary_key_column_token1,
      aux_sym_apply_batch_token1,
  [2900] = 6,
    ACTIONS(132), 1,
      aux_sym_limit_spec_token1,
    ACTIONS(136), 1,
      aux_sym_order_spec_token1,
    ACTIONS(149), 1,
      aux_sym_select_statement_token4,
    STATE(94), 1,
      sym_order_spec,
    STATE(163), 1,
      sym_limit_spec,
    ACTIONS(147), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [2934] = 11,
    ACTIONS(155), 1,
      anon_sym_LPAREN,
    ACTIONS(159), 1,
      anon_sym_QMARK,
    ACTIONS(161), 1,
      anon_sym_COLON,
    ACTIONS(165), 1,
      aux_sym__decimal_literal_token1,
    ACTIONS(167), 1,
      anon_sym_LBRACK,
    ACTIONS(169), 1,
      anon_sym_LBRACE,
    STATE(31), 1,
      sym__decimal_literal,
    STATE(647), 1,
      sym_expression,
    ACTIONS(163), 2,
      sym__string_literal,
      sym__float_literal,
    ACTIONS(157), 5,
      aux_sym_constant_token1,
      aux_sym_constant_token2,
      aux_sym_constant_token3,
      sym__boolean_literal,
      sym__code_block,
    STATE(552), 6,
      sym_constant,
      sym_bind_marker,
      sym_assignment_map,
      sym_assignment_set,
      sym_assignment_list,
      sym_assignment_tuple,
  [2978] = 6,
    ACTIONS(130), 1,
      aux_sym_select_statement_token4,
    ACTIONS(132), 1,
      aux_sym_limit_spec_token1,
    ACTIONS(136), 1,
      aux_sym_order_spec_token1,
    STATE(93), 1,
      sym_order_spec,
    STATE(192), 1,
      sym_limit_spec,
    ACTIONS(128), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [3012] = 6,
    ACTIONS(132), 1,
      aux_sym_limit_spec_token1,
    ACTIONS(136), 1,
      aux_sym_order_spec_token1,
    ACTIONS(211), 1,
      aux_sym_select_statement_token4,
    STATE(96), 1,
      sym_order_spec,
    STATE(173), 1,
      sym_limit_spec,
    ACTIONS(209), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [3046] = 1,
    ACTIONS(213), 21,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_select_statement_token4,
      aux_sym_limit_spec_token1,
      aux_sym_where_spec_token1,
      aux_sym_order_spec_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_using_timestamp_spec_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [3070] = 2,
    ACTIONS(217), 1,
      anon_sym_DOT,
    ACTIONS(215), 19,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      anon_sym_LPAREN,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_alter_table_add_token1,
      aux_sym_alter_table_rename_token1,
      aux_sym_apply_batch_token1,
  [3095] = 2,
    ACTIONS(221), 1,
      anon_sym_DOT,
    ACTIONS(219), 19,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_from_spec_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_grant_token2,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_list_roles_token2,
      aux_sym_apply_batch_token1,
  [3120] = 2,
    ACTIONS(225), 1,
      anon_sym_DOT,
    ACTIONS(223), 19,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_from_spec_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_grant_token2,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_list_roles_token2,
      aux_sym_apply_batch_token1,
  [3145] = 2,
    ACTIONS(229), 1,
      anon_sym_DOT,
    ACTIONS(227), 19,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      anon_sym_LPAREN,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_create_aggregate_token4,
      aux_sym_create_aggregate_token6,
      aux_sym_apply_batch_token1,
  [3170] = 1,
    ACTIONS(231), 20,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_select_statement_token4,
      aux_sym_limit_spec_token1,
      aux_sym_order_spec_token1,
      aux_sym_delete_statement_token1,
      aux_sym_delete_statement_token2,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [3193] = 2,
    ACTIONS(235), 2,
      aux_sym_order_spec_token3,
      aux_sym_order_spec_token4,
    ACTIONS(233), 18,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_select_statement_token4,
      aux_sym_limit_spec_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [3218] = 2,
    ACTIONS(239), 1,
      anon_sym_DOT,
    ACTIONS(237), 19,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_from_spec_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_grant_token2,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_list_roles_token2,
      aux_sym_apply_batch_token1,
  [3243] = 2,
    ACTIONS(243), 1,
      aux_sym_relation_element_token1,
    ACTIONS(241), 19,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_from_spec_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_grant_token2,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_list_roles_token2,
      aux_sym_apply_batch_token1,
  [3268] = 1,
    ACTIONS(245), 19,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_from_spec_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_grant_token2,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_list_roles_token2,
      aux_sym_apply_batch_token1,
  [3290] = 1,
    ACTIONS(241), 19,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_from_spec_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_grant_token2,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_list_roles_token2,
      aux_sym_apply_batch_token1,
  [3312] = 1,
    ACTIONS(247), 19,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_from_spec_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_grant_token2,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_list_roles_token2,
      aux_sym_apply_batch_token1,
  [3334] = 1,
    ACTIONS(249), 19,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_from_spec_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_grant_token2,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_list_roles_token2,
      aux_sym_apply_batch_token1,
  [3356] = 1,
    ACTIONS(251), 19,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_from_spec_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_grant_token2,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_list_roles_token2,
      aux_sym_apply_batch_token1,
  [3378] = 4,
    ACTIONS(255), 1,
      aux_sym_delete_statement_token2,
    ACTIONS(257), 1,
      aux_sym_using_timestamp_spec_token1,
    STATE(241), 1,
      sym_using_ttl_timestamp,
    ACTIONS(253), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [3406] = 1,
    ACTIONS(259), 19,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      anon_sym_LPAREN,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_create_aggregate_token4,
      aux_sym_create_aggregate_token6,
      aux_sym_apply_batch_token1,
  [3428] = 3,
    ACTIONS(263), 1,
      anon_sym_COMMA,
    STATE(92), 1,
      aux_sym_create_function_repeat1,
    ACTIONS(261), 17,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      anon_sym_RPAREN,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [3454] = 4,
    ACTIONS(132), 1,
      aux_sym_limit_spec_token1,
    ACTIONS(211), 1,
      aux_sym_select_statement_token4,
    STATE(173), 1,
      sym_limit_spec,
    ACTIONS(209), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [3482] = 4,
    ACTIONS(130), 1,
      aux_sym_select_statement_token4,
    ACTIONS(132), 1,
      aux_sym_limit_spec_token1,
    STATE(192), 1,
      sym_limit_spec,
    ACTIONS(128), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [3510] = 2,
    ACTIONS(268), 1,
      anon_sym_DOT,
    ACTIONS(266), 18,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_select_element_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_create_keyspace_token1,
      aux_sym_apply_batch_token1,
  [3534] = 4,
    ACTIONS(132), 1,
      aux_sym_limit_spec_token1,
    ACTIONS(272), 1,
      aux_sym_select_statement_token4,
    STATE(172), 1,
      sym_limit_spec,
    ACTIONS(270), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [3562] = 3,
    STATE(224), 1,
      sym_user_super_user,
    ACTIONS(276), 2,
      aux_sym_role_with_option_token3,
      aux_sym_user_super_user_token1,
    ACTIONS(274), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [3588] = 3,
    ACTIONS(280), 1,
      anon_sym_COMMA,
    STATE(98), 1,
      aux_sym_clustering_key_list_repeat1,
    ACTIONS(278), 17,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      anon_sym_RPAREN,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [3614] = 4,
    ACTIONS(257), 1,
      aux_sym_using_timestamp_spec_token1,
    ACTIONS(285), 1,
      aux_sym_delete_statement_token2,
    STATE(261), 1,
      sym_using_ttl_timestamp,
    ACTIONS(283), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [3642] = 1,
    ACTIONS(287), 19,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_from_spec_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_grant_token2,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_list_roles_token2,
      aux_sym_apply_batch_token1,
  [3664] = 4,
    ACTIONS(132), 1,
      aux_sym_limit_spec_token1,
    ACTIONS(149), 1,
      aux_sym_select_statement_token4,
    STATE(163), 1,
      sym_limit_spec,
    ACTIONS(147), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [3692] = 1,
    ACTIONS(289), 19,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      anon_sym_LPAREN,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_alter_table_add_token1,
      aux_sym_alter_table_rename_token1,
      aux_sym_apply_batch_token1,
  [3714] = 2,
    ACTIONS(293), 1,
      aux_sym_privilege_token2,
    ACTIONS(291), 18,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_create_index_token3,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_list_roles_token2,
      aux_sym_apply_batch_token1,
  [3738] = 1,
    ACTIONS(295), 19,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_from_spec_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_grant_token2,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_list_roles_token2,
      aux_sym_apply_batch_token1,
  [3760] = 1,
    ACTIONS(297), 18,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [3781] = 3,
    ACTIONS(301), 1,
      anon_sym_COMMA,
    STATE(130), 1,
      aux_sym_create_function_repeat1,
    ACTIONS(299), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [3806] = 3,
    ACTIONS(305), 1,
      aux_sym_relation_elements_token1,
    STATE(157), 1,
      aux_sym_table_options_repeat1,
    ACTIONS(303), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [3831] = 3,
    ACTIONS(309), 1,
      aux_sym_relation_elements_token1,
    STATE(108), 1,
      aux_sym_role_with_repeat1,
    ACTIONS(307), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [3856] = 3,
    ACTIONS(314), 1,
      aux_sym_create_keyspace_token1,
    STATE(273), 1,
      sym_with_element,
    ACTIONS(312), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [3881] = 1,
    ACTIONS(316), 18,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [3902] = 1,
    ACTIONS(318), 18,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_delete_statement_token2,
      aux_sym_begin_batch_token1,
      aux_sym_using_timestamp_spec_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [3923] = 3,
    ACTIONS(322), 1,
      aux_sym_delete_statement_token2,
    STATE(277), 1,
      sym_if_spec,
    ACTIONS(320), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [3948] = 3,
    ACTIONS(326), 1,
      anon_sym_COMMA,
    STATE(98), 1,
      aux_sym_clustering_key_list_repeat1,
    ACTIONS(324), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [3973] = 3,
    ACTIONS(257), 1,
      aux_sym_using_timestamp_spec_token1,
    STATE(197), 1,
      sym_using_ttl_timestamp,
    ACTIONS(328), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [3998] = 3,
    ACTIONS(332), 1,
      aux_sym_relation_elements_token1,
    STATE(132), 1,
      aux_sym_alter_type_rename_repeat1,
    ACTIONS(330), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [4023] = 3,
    ACTIONS(336), 1,
      aux_sym_create_keyspace_token1,
    STATE(231), 1,
      sym_role_with,
    ACTIONS(334), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [4048] = 1,
    ACTIONS(291), 18,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_create_index_token3,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_list_roles_token2,
      aux_sym_apply_batch_token1,
  [4069] = 2,
    ACTIONS(340), 1,
      anon_sym_DOT,
    ACTIONS(338), 17,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      anon_sym_LPAREN,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [4092] = 1,
    ACTIONS(342), 18,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [4113] = 3,
    ACTIONS(301), 1,
      anon_sym_COMMA,
    STATE(125), 1,
      aux_sym_create_function_repeat1,
    ACTIONS(344), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [4138] = 1,
    ACTIONS(346), 18,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [4159] = 3,
    ACTIONS(257), 1,
      aux_sym_using_timestamp_spec_token1,
    STATE(209), 1,
      sym_using_ttl_timestamp,
    ACTIONS(348), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [4184] = 1,
    ACTIONS(350), 18,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_delete_statement_token2,
      aux_sym_begin_batch_token1,
      aux_sym_using_timestamp_spec_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [4205] = 3,
    ACTIONS(354), 1,
      aux_sym_relation_elements_token1,
    STATE(154), 1,
      aux_sym_role_with_repeat1,
    ACTIONS(352), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [4230] = 3,
    ACTIONS(301), 1,
      anon_sym_COMMA,
    STATE(92), 1,
      aux_sym_create_function_repeat1,
    ACTIONS(356), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [4255] = 1,
    ACTIONS(278), 18,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [4276] = 3,
    ACTIONS(360), 1,
      aux_sym_relation_elements_token1,
    STATE(127), 1,
      aux_sym_alter_type_rename_repeat1,
    ACTIONS(358), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [4301] = 2,
    ACTIONS(365), 1,
      aux_sym_relation_elements_token1,
    ACTIONS(363), 17,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_update_assignments_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [4324] = 2,
    ACTIONS(369), 1,
      aux_sym_relation_elements_token1,
    ACTIONS(367), 17,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_update_assignments_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [4347] = 3,
    ACTIONS(301), 1,
      anon_sym_COMMA,
    STATE(92), 1,
      aux_sym_create_function_repeat1,
    ACTIONS(371), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [4372] = 1,
    ACTIONS(261), 18,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [4393] = 3,
    ACTIONS(332), 1,
      aux_sym_relation_elements_token1,
    STATE(127), 1,
      aux_sym_alter_type_rename_repeat1,
    ACTIONS(373), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [4418] = 3,
    ACTIONS(377), 1,
      aux_sym_delete_statement_token2,
    STATE(228), 1,
      sym_if_spec,
    ACTIONS(375), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [4443] = 1,
    ACTIONS(379), 18,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [4464] = 1,
    ACTIONS(381), 18,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [4485] = 3,
    ACTIONS(385), 1,
      aux_sym_delete_statement_token2,
    STATE(252), 1,
      sym_if_spec,
    ACTIONS(383), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [4510] = 1,
    ACTIONS(387), 18,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [4531] = 3,
    ACTIONS(391), 1,
      aux_sym_delete_statement_token2,
    STATE(217), 1,
      sym_if_spec,
    ACTIONS(389), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [4556] = 3,
    ACTIONS(395), 1,
      aux_sym_delete_statement_token2,
    STATE(245), 1,
      sym_if_spec,
    ACTIONS(393), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [4581] = 3,
    ACTIONS(399), 1,
      aux_sym_delete_statement_token2,
    STATE(208), 1,
      sym_if_spec,
    ACTIONS(397), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [4606] = 1,
    ACTIONS(401), 18,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      anon_sym_RPAREN,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_create_keyspace_token1,
      aux_sym_apply_batch_token1,
  [4627] = 3,
    ACTIONS(405), 1,
      aux_sym_list_roles_token2,
    ACTIONS(407), 1,
      aux_sym_list_roles_token3,
    ACTIONS(403), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [4652] = 1,
    ACTIONS(409), 18,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_select_statement_token4,
      aux_sym_limit_spec_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [4673] = 3,
    ACTIONS(413), 1,
      aux_sym_create_index_token3,
    ACTIONS(415), 1,
      aux_sym_list_roles_token2,
    ACTIONS(411), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [4698] = 3,
    ACTIONS(326), 1,
      anon_sym_COMMA,
    STATE(113), 1,
      aux_sym_clustering_key_list_repeat1,
    ACTIONS(417), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [4723] = 1,
    ACTIONS(419), 18,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_role_with_option_token3,
      aux_sym_user_super_user_token1,
      aux_sym_apply_batch_token1,
  [4744] = 3,
    ACTIONS(305), 1,
      aux_sym_relation_elements_token1,
    STATE(107), 1,
      aux_sym_table_options_repeat1,
    ACTIONS(421), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [4769] = 1,
    ACTIONS(423), 18,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_select_element_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_create_keyspace_token1,
      aux_sym_apply_batch_token1,
  [4790] = 1,
    ACTIONS(425), 18,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [4811] = 3,
    ACTIONS(314), 1,
      aux_sym_create_keyspace_token1,
    STATE(205), 1,
      sym_with_element,
    ACTIONS(427), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [4836] = 3,
    ACTIONS(431), 1,
      aux_sym_delete_statement_token2,
    STATE(278), 1,
      sym_if_spec,
    ACTIONS(429), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [4861] = 3,
    ACTIONS(336), 1,
      aux_sym_create_keyspace_token1,
    STATE(238), 1,
      sym_role_with,
    ACTIONS(433), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [4886] = 1,
    ACTIONS(435), 18,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_create_index_token3,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_list_roles_token2,
      aux_sym_apply_batch_token1,
  [4907] = 3,
    ACTIONS(354), 1,
      aux_sym_relation_elements_token1,
    STATE(108), 1,
      aux_sym_role_with_repeat1,
    ACTIONS(437), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [4932] = 3,
    ACTIONS(314), 1,
      aux_sym_create_keyspace_token1,
    STATE(257), 1,
      sym_with_element,
    ACTIONS(439), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [4957] = 3,
    ACTIONS(314), 1,
      aux_sym_create_keyspace_token1,
    STATE(230), 1,
      sym_with_element,
    ACTIONS(441), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [4982] = 3,
    ACTIONS(445), 1,
      aux_sym_relation_elements_token1,
    STATE(157), 1,
      aux_sym_table_options_repeat1,
    ACTIONS(443), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [5007] = 3,
    ACTIONS(336), 1,
      aux_sym_create_keyspace_token1,
    STATE(269), 1,
      sym_role_with,
    ACTIONS(448), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [5032] = 3,
    ACTIONS(314), 1,
      aux_sym_create_keyspace_token1,
    STATE(232), 1,
      sym_with_element,
    ACTIONS(450), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [5057] = 2,
    ACTIONS(454), 1,
      anon_sym_DOT,
    ACTIONS(452), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [5079] = 2,
    ACTIONS(458), 1,
      aux_sym_list_roles_token3,
    ACTIONS(456), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [5101] = 2,
    ACTIONS(462), 1,
      aux_sym_list_roles_token2,
    ACTIONS(460), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [5123] = 2,
    ACTIONS(130), 1,
      aux_sym_select_statement_token4,
    ACTIONS(128), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [5145] = 1,
    ACTIONS(464), 17,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_relation_elements_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [5165] = 1,
    ACTIONS(443), 17,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_relation_elements_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [5185] = 1,
    ACTIONS(466), 17,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_relation_elements_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [5205] = 1,
    ACTIONS(468), 17,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_relation_elements_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [5225] = 2,
    ACTIONS(472), 1,
      aux_sym_relation_elements_token1,
    ACTIONS(470), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [5247] = 2,
    ACTIONS(476), 1,
      aux_sym_relation_elements_token1,
    ACTIONS(474), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [5269] = 1,
    ACTIONS(478), 17,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_select_statement_token4,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [5289] = 1,
    ACTIONS(480), 17,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_relation_elements_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [5309] = 2,
    ACTIONS(484), 1,
      aux_sym_select_statement_token4,
    ACTIONS(482), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [5331] = 2,
    ACTIONS(272), 1,
      aux_sym_select_statement_token4,
    ACTIONS(270), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [5353] = 1,
    ACTIONS(486), 17,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_update_assignments_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [5373] = 1,
    ACTIONS(488), 17,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_update_assignments_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [5393] = 1,
    ACTIONS(490), 17,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_relation_elements_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [5413] = 1,
    ACTIONS(358), 17,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_relation_elements_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [5433] = 1,
    ACTIONS(492), 17,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_relation_elements_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [5453] = 1,
    ACTIONS(494), 17,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_create_keyspace_token1,
      aux_sym_apply_batch_token1,
  [5473] = 1,
    ACTIONS(496), 17,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_relation_elements_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [5493] = 1,
    ACTIONS(498), 17,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_relation_elements_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [5513] = 2,
    ACTIONS(149), 1,
      aux_sym_select_statement_token4,
    ACTIONS(147), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [5535] = 1,
    ACTIONS(500), 17,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      anon_sym_LPAREN,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [5555] = 1,
    ACTIONS(502), 17,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_relation_elements_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [5575] = 1,
    ACTIONS(504), 17,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_relation_elements_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [5595] = 1,
    ACTIONS(506), 17,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_relation_elements_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [5615] = 2,
    ACTIONS(510), 1,
      aux_sym_relation_elements_token1,
    ACTIONS(508), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [5637] = 1,
    ACTIONS(512), 17,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_relation_elements_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [5657] = 1,
    ACTIONS(514), 17,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_relation_elements_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [5677] = 1,
    ACTIONS(516), 17,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_relation_elements_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [5697] = 1,
    ACTIONS(518), 17,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_create_keyspace_token1,
      aux_sym_apply_batch_token1,
  [5717] = 2,
    ACTIONS(211), 1,
      aux_sym_select_statement_token4,
    ACTIONS(209), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [5739] = 1,
    ACTIONS(126), 17,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_create_keyspace_token1,
      aux_sym_apply_batch_token1,
  [5759] = 1,
    ACTIONS(307), 17,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_relation_elements_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [5779] = 1,
    ACTIONS(520), 17,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_relation_elements_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [5799] = 1,
    ACTIONS(522), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [5818] = 1,
    ACTIONS(348), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [5837] = 1,
    ACTIONS(524), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [5856] = 1,
    ACTIONS(526), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [5875] = 1,
    ACTIONS(528), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [5894] = 1,
    ACTIONS(530), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [5913] = 1,
    ACTIONS(532), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [5932] = 1,
    ACTIONS(534), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [5951] = 1,
    ACTIONS(536), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [5970] = 1,
    ACTIONS(538), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [5989] = 1,
    ACTIONS(540), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [6008] = 1,
    ACTIONS(542), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [6027] = 1,
    ACTIONS(383), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [6046] = 1,
    ACTIONS(544), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [6065] = 1,
    ACTIONS(546), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [6084] = 1,
    ACTIONS(548), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [6103] = 1,
    ACTIONS(550), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [6122] = 1,
    ACTIONS(552), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [6141] = 1,
    ACTIONS(554), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [6160] = 1,
    ACTIONS(556), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [6179] = 1,
    ACTIONS(558), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [6198] = 1,
    ACTIONS(320), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [6217] = 1,
    ACTIONS(560), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [6236] = 1,
    ACTIONS(270), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [6255] = 1,
    ACTIONS(562), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [6274] = 1,
    ACTIONS(564), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [6293] = 1,
    ACTIONS(566), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [6312] = 1,
    ACTIONS(568), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [6331] = 1,
    ACTIONS(570), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [6350] = 1,
    ACTIONS(572), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [6369] = 2,
    ACTIONS(576), 1,
      anon_sym_SEMI,
    ACTIONS(574), 15,
      ts_builtin_sym_end,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [6390] = 1,
    ACTIONS(578), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [6409] = 1,
    ACTIONS(580), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [6428] = 1,
    ACTIONS(582), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [6447] = 1,
    ACTIONS(584), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [6466] = 1,
    ACTIONS(586), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [6485] = 1,
    ACTIONS(588), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [6504] = 1,
    ACTIONS(590), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [6523] = 1,
    ACTIONS(592), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [6542] = 1,
    ACTIONS(594), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [6561] = 1,
    ACTIONS(596), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [6580] = 1,
    ACTIONS(598), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [6599] = 1,
    ACTIONS(600), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [6618] = 1,
    ACTIONS(602), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [6637] = 1,
    ACTIONS(604), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [6656] = 1,
    ACTIONS(283), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [6675] = 1,
    ACTIONS(606), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [6694] = 1,
    ACTIONS(608), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [6713] = 1,
    ACTIONS(610), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [6732] = 1,
    ACTIONS(375), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [6751] = 1,
    ACTIONS(612), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [6770] = 1,
    ACTIONS(614), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [6789] = 1,
    ACTIONS(616), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [6808] = 1,
    ACTIONS(618), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [6827] = 1,
    ACTIONS(620), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [6846] = 1,
    ACTIONS(209), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [6865] = 1,
    ACTIONS(622), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [6884] = 1,
    ACTIONS(624), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [6903] = 1,
    ACTIONS(626), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [6922] = 1,
    ACTIONS(628), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [6941] = 1,
    ACTIONS(630), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [6960] = 1,
    ACTIONS(632), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [6979] = 1,
    ACTIONS(634), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [6998] = 1,
    ACTIONS(482), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [7017] = 1,
    ACTIONS(636), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [7036] = 1,
    ACTIONS(638), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [7055] = 1,
    ACTIONS(640), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [7074] = 1,
    ACTIONS(642), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [7093] = 1,
    ACTIONS(644), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [7112] = 1,
    ACTIONS(646), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [7131] = 1,
    ACTIONS(648), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [7150] = 1,
    ACTIONS(650), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [7169] = 1,
    ACTIONS(652), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [7188] = 1,
    ACTIONS(654), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [7207] = 1,
    ACTIONS(656), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [7226] = 1,
    ACTIONS(658), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [7245] = 1,
    ACTIONS(660), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [7264] = 1,
    ACTIONS(662), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [7283] = 1,
    ACTIONS(664), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [7302] = 1,
    ACTIONS(666), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [7321] = 1,
    ACTIONS(668), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [7340] = 1,
    ACTIONS(393), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [7359] = 1,
    ACTIONS(397), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [7378] = 1,
    ACTIONS(670), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [7397] = 1,
    ACTIONS(672), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [7416] = 1,
    ACTIONS(674), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [7435] = 1,
    ACTIONS(676), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [7454] = 9,
    ACTIONS(165), 1,
      aux_sym__decimal_literal_token1,
    ACTIONS(167), 1,
      anon_sym_LBRACK,
    ACTIONS(169), 1,
      anon_sym_LBRACE,
    ACTIONS(678), 1,
      sym_object_name,
    STATE(31), 1,
      sym__decimal_literal,
    STATE(536), 1,
      sym_constant,
    ACTIONS(157), 3,
      aux_sym_constant_token1,
      aux_sym_constant_token3,
      sym__code_block,
    STATE(376), 3,
      sym_assignment_map,
      sym_assignment_set,
      sym_assignment_list,
    ACTIONS(163), 4,
      aux_sym_constant_token2,
      sym__string_literal,
      sym__float_literal,
      sym__boolean_literal,
  [7489] = 1,
    ACTIONS(680), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [7508] = 1,
    ACTIONS(682), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [7527] = 1,
    ACTIONS(684), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [7546] = 1,
    ACTIONS(686), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [7565] = 1,
    ACTIONS(688), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [7584] = 1,
    ACTIONS(690), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [7603] = 1,
    ACTIONS(692), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [7622] = 1,
    ACTIONS(128), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [7641] = 1,
    ACTIONS(694), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [7660] = 1,
    ACTIONS(696), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [7679] = 1,
    ACTIONS(698), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [7698] = 1,
    ACTIONS(700), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [7717] = 8,
    ACTIONS(159), 1,
      anon_sym_QMARK,
    ACTIONS(161), 1,
      anon_sym_COLON,
    ACTIONS(165), 1,
      aux_sym__decimal_literal_token1,
    ACTIONS(702), 1,
      sym_object_name,
    STATE(31), 1,
      sym__decimal_literal,
    ACTIONS(157), 3,
      aux_sym_constant_token1,
      aux_sym_constant_token3,
      sym__code_block,
    ACTIONS(163), 4,
      aux_sym_constant_token2,
      sym__string_literal,
      sym__float_literal,
      sym__boolean_literal,
    STATE(54), 4,
      sym_function_call,
      sym_constant,
      sym_bind_marker,
      sym__value_marker,
  [7750] = 1,
    ACTIONS(704), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [7769] = 7,
    ACTIONS(165), 1,
      aux_sym__decimal_literal_token1,
    ACTIONS(706), 1,
      anon_sym_LPAREN,
    STATE(31), 1,
      sym__decimal_literal,
    STATE(234), 1,
      sym_init_cond_definition,
    ACTIONS(163), 2,
      sym__string_literal,
      sym__float_literal,
    STATE(110), 4,
      sym_constant,
      sym_init_cond_list,
      sym_init_cond_nested_list,
      sym_init_cond_hash,
    ACTIONS(157), 5,
      aux_sym_constant_token1,
      aux_sym_constant_token2,
      aux_sym_constant_token3,
      sym__boolean_literal,
      sym__code_block,
  [7799] = 7,
    ACTIONS(165), 1,
      aux_sym__decimal_literal_token1,
    ACTIONS(706), 1,
      anon_sym_LPAREN,
    STATE(31), 1,
      sym__decimal_literal,
    STATE(243), 1,
      sym_init_cond_definition,
    ACTIONS(163), 2,
      sym__string_literal,
      sym__float_literal,
    STATE(110), 4,
      sym_constant,
      sym_init_cond_list,
      sym_init_cond_nested_list,
      sym_init_cond_hash,
    ACTIONS(157), 5,
      aux_sym_constant_token1,
      aux_sym_constant_token2,
      aux_sym_constant_token3,
      sym__boolean_literal,
      sym__code_block,
  [7829] = 7,
    ACTIONS(165), 1,
      aux_sym__decimal_literal_token1,
    ACTIONS(706), 1,
      anon_sym_LPAREN,
    STATE(31), 1,
      sym__decimal_literal,
    STATE(246), 1,
      sym_init_cond_definition,
    ACTIONS(163), 2,
      sym__string_literal,
      sym__float_literal,
    STATE(110), 4,
      sym_constant,
      sym_init_cond_list,
      sym_init_cond_nested_list,
      sym_init_cond_hash,
    ACTIONS(157), 5,
      aux_sym_constant_token1,
      aux_sym_constant_token2,
      aux_sym_constant_token3,
      sym__boolean_literal,
      sym__code_block,
  [7859] = 7,
    ACTIONS(165), 1,
      aux_sym__decimal_literal_token1,
    ACTIONS(706), 1,
      anon_sym_LPAREN,
    STATE(31), 1,
      sym__decimal_literal,
    STATE(199), 1,
      sym_init_cond_definition,
    ACTIONS(163), 2,
      sym__string_literal,
      sym__float_literal,
    STATE(110), 4,
      sym_constant,
      sym_init_cond_list,
      sym_init_cond_nested_list,
      sym_init_cond_hash,
    ACTIONS(157), 5,
      aux_sym_constant_token1,
      aux_sym_constant_token2,
      aux_sym_constant_token3,
      sym__boolean_literal,
      sym__code_block,
  [7889] = 9,
    ACTIONS(159), 1,
      anon_sym_QMARK,
    ACTIONS(161), 1,
      anon_sym_COLON,
    ACTIONS(165), 1,
      aux_sym__decimal_literal_token1,
    ACTIONS(708), 1,
      anon_sym_RBRACE,
    STATE(31), 1,
      sym__decimal_literal,
    STATE(417), 1,
      sym_constant,
    ACTIONS(163), 2,
      sym__string_literal,
      sym__float_literal,
    STATE(416), 2,
      sym_bind_marker,
      sym__value_marker,
    ACTIONS(157), 5,
      aux_sym_constant_token1,
      aux_sym_constant_token2,
      aux_sym_constant_token3,
      sym__boolean_literal,
      sym__code_block,
  [7923] = 1,
    ACTIONS(710), 15,
      ts_builtin_sym_end,
      aux_sym_select_statement_token1,
      aux_sym_delete_statement_token1,
      aux_sym_begin_batch_token1,
      aux_sym_insert_statement_token1,
      aux_sym_truncate_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_update_token1,
      aux_sym_use_token1,
      aux_sym_grant_token1,
      aux_sym_revoke_token1,
      aux_sym_privilege_token3,
      aux_sym_list_roles_token1,
      aux_sym_apply_batch_token1,
  [7941] = 7,
    ACTIONS(165), 1,
      aux_sym__decimal_literal_token1,
    ACTIONS(706), 1,
      anon_sym_LPAREN,
    STATE(31), 1,
      sym__decimal_literal,
    STATE(539), 1,
      sym_init_cond_definition,
    ACTIONS(163), 2,
      sym__string_literal,
      sym__float_literal,
    STATE(110), 4,
      sym_constant,
      sym_init_cond_list,
      sym_init_cond_nested_list,
      sym_init_cond_hash,
    ACTIONS(157), 5,
      aux_sym_constant_token1,
      aux_sym_constant_token2,
      aux_sym_constant_token3,
      sym__boolean_literal,
      sym__code_block,
  [7971] = 7,
    ACTIONS(159), 1,
      anon_sym_QMARK,
    ACTIONS(161), 1,
      anon_sym_COLON,
    ACTIONS(165), 1,
      aux_sym__decimal_literal_token1,
    STATE(31), 1,
      sym__decimal_literal,
    ACTIONS(163), 2,
      sym__string_literal,
      sym__float_literal,
    STATE(439), 3,
      sym_constant,
      sym_bind_marker,
      sym__value_marker,
    ACTIONS(157), 5,
      aux_sym_constant_token1,
      aux_sym_constant_token2,
      aux_sym_constant_token3,
      sym__boolean_literal,
      sym__code_block,
  [8000] = 8,
    ACTIONS(165), 1,
      aux_sym__decimal_literal_token1,
    ACTIONS(712), 1,
      anon_sym_STAR,
    ACTIONS(714), 1,
      sym_object_name,
    STATE(31), 1,
      sym__decimal_literal,
    STATE(817), 1,
      sym_function_args,
    STATE(511), 2,
      sym_function_call,
      sym_constant,
    ACTIONS(157), 3,
      aux_sym_constant_token1,
      aux_sym_constant_token3,
      sym__code_block,
    ACTIONS(163), 4,
      aux_sym_constant_token2,
      sym__string_literal,
      sym__float_literal,
      sym__boolean_literal,
  [8031] = 7,
    ACTIONS(159), 1,
      anon_sym_QMARK,
    ACTIONS(161), 1,
      anon_sym_COLON,
    ACTIONS(165), 1,
      aux_sym__decimal_literal_token1,
    STATE(31), 1,
      sym__decimal_literal,
    ACTIONS(163), 2,
      sym__string_literal,
      sym__float_literal,
    STATE(565), 3,
      sym_constant,
      sym_bind_marker,
      sym__value_marker,
    ACTIONS(157), 5,
      aux_sym_constant_token1,
      aux_sym_constant_token2,
      aux_sym_constant_token3,
      sym__boolean_literal,
      sym__code_block,
  [8060] = 7,
    ACTIONS(159), 1,
      anon_sym_QMARK,
    ACTIONS(161), 1,
      anon_sym_COLON,
    ACTIONS(165), 1,
      aux_sym__decimal_literal_token1,
    STATE(31), 1,
      sym__decimal_literal,
    ACTIONS(163), 2,
      sym__string_literal,
      sym__float_literal,
    STATE(443), 3,
      sym_constant,
      sym_bind_marker,
      sym__value_marker,
    ACTIONS(157), 5,
      aux_sym_constant_token1,
      aux_sym_constant_token2,
      aux_sym_constant_token3,
      sym__boolean_literal,
      sym__code_block,
  [8089] = 7,
    ACTIONS(159), 1,
      anon_sym_QMARK,
    ACTIONS(161), 1,
      anon_sym_COLON,
    ACTIONS(165), 1,
      aux_sym__decimal_literal_token1,
    STATE(31), 1,
      sym__decimal_literal,
    ACTIONS(163), 2,
      sym__string_literal,
      sym__float_literal,
    STATE(56), 3,
      sym_constant,
      sym_bind_marker,
      sym__value_marker,
    ACTIONS(157), 5,
      aux_sym_constant_token1,
      aux_sym_constant_token2,
      aux_sym_constant_token3,
      sym__boolean_literal,
      sym__code_block,
  [8118] = 7,
    ACTIONS(159), 1,
      anon_sym_QMARK,
    ACTIONS(161), 1,
      anon_sym_COLON,
    ACTIONS(165), 1,
      aux_sym__decimal_literal_token1,
    STATE(31), 1,
      sym__decimal_literal,
    ACTIONS(163), 2,
      sym__string_literal,
      sym__float_literal,
    STATE(424), 3,
      sym_constant,
      sym_bind_marker,
      sym__value_marker,
    ACTIONS(157), 5,
      aux_sym_constant_token1,
      aux_sym_constant_token2,
      aux_sym_constant_token3,
      sym__boolean_literal,
      sym__code_block,
  [8147] = 9,
    ACTIONS(165), 1,
      aux_sym__decimal_literal_token1,
    ACTIONS(716), 1,
      anon_sym_LPAREN,
    ACTIONS(718), 1,
      sym_object_name,
    STATE(31), 1,
      sym__decimal_literal,
    STATE(399), 1,
      sym_init_cond_list,
    STATE(401), 1,
      sym_init_cond_hash_item,
    STATE(460), 1,
      sym_constant,
    ACTIONS(157), 3,
      aux_sym_constant_token1,
      aux_sym_constant_token3,
      sym__code_block,
    ACTIONS(163), 4,
      aux_sym_constant_token2,
      sym__string_literal,
      sym__float_literal,
      sym__boolean_literal,
  [8180] = 7,
    ACTIONS(165), 1,
      aux_sym__decimal_literal_token1,
    ACTIONS(714), 1,
      sym_object_name,
    STATE(31), 1,
      sym__decimal_literal,
    STATE(931), 1,
      sym_function_args,
    STATE(511), 2,
      sym_function_call,
      sym_constant,
    ACTIONS(157), 3,
      aux_sym_constant_token1,
      aux_sym_constant_token3,
      sym__code_block,
    ACTIONS(163), 4,
      aux_sym_constant_token2,
      sym__string_literal,
      sym__float_literal,
      sym__boolean_literal,
  [8208] = 6,
    ACTIONS(165), 1,
      aux_sym__decimal_literal_token1,
    ACTIONS(716), 1,
      anon_sym_LPAREN,
    STATE(31), 1,
      sym__decimal_literal,
    ACTIONS(163), 2,
      sym__string_literal,
      sym__float_literal,
    STATE(532), 2,
      sym_constant,
      sym_init_cond_list,
    ACTIONS(157), 5,
      aux_sym_constant_token1,
      aux_sym_constant_token2,
      aux_sym_constant_token3,
      sym__boolean_literal,
      sym__code_block,
  [8233] = 6,
    ACTIONS(165), 1,
      aux_sym__decimal_literal_token1,
    ACTIONS(720), 1,
      sym_object_name,
    STATE(31), 1,
      sym__decimal_literal,
    STATE(613), 2,
      sym_function_call,
      sym_constant,
    ACTIONS(157), 3,
      aux_sym_constant_token1,
      aux_sym_constant_token3,
      sym__code_block,
    ACTIONS(163), 4,
      aux_sym_constant_token2,
      sym__string_literal,
      sym__float_literal,
      sym__boolean_literal,
  [8258] = 6,
    ACTIONS(165), 1,
      aux_sym__decimal_literal_token1,
    ACTIONS(722), 1,
      aux_sym_relation_contains_key_token2,
    STATE(31), 1,
      sym__decimal_literal,
    STATE(55), 1,
      sym_constant,
    ACTIONS(163), 2,
      sym__string_literal,
      sym__float_literal,
    ACTIONS(157), 5,
      aux_sym_constant_token1,
      aux_sym_constant_token2,
      aux_sym_constant_token3,
      sym__boolean_literal,
      sym__code_block,
  [8282] = 4,
    ACTIONS(726), 1,
      aux_sym_privilege_token1,
    ACTIONS(728), 1,
      aux_sym_resource_token4,
    STATE(144), 1,
      sym_privilege,
    ACTIONS(724), 8,
      aux_sym_select_statement_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_privilege_token3,
      aux_sym_privilege_token4,
      aux_sym_privilege_token5,
      aux_sym_privilege_token6,
      aux_sym_privilege_token7,
  [8302] = 11,
    ACTIONS(730), 1,
      aux_sym_truncate_token2,
    ACTIONS(732), 1,
      aux_sym_create_index_token2,
    ACTIONS(734), 1,
      aux_sym_resource_token2,
    ACTIONS(736), 1,
      aux_sym_resource_token5,
    ACTIONS(738), 1,
      aux_sym_resource_token6,
    ACTIONS(740), 1,
      aux_sym_drop_aggregate_token1,
    ACTIONS(742), 1,
      aux_sym_drop_materialized_view_token1,
    ACTIONS(744), 1,
      aux_sym_drop_trigger_token1,
    ACTIONS(746), 1,
      aux_sym_drop_type_token1,
    ACTIONS(748), 1,
      aux_sym_drop_user_token1,
    ACTIONS(750), 1,
      aux_sym_create_aggregate_token1,
  [8336] = 5,
    ACTIONS(165), 1,
      aux_sym__decimal_literal_token1,
    STATE(31), 1,
      sym__decimal_literal,
    STATE(63), 1,
      sym_constant,
    ACTIONS(163), 2,
      sym__string_literal,
      sym__float_literal,
    ACTIONS(157), 5,
      aux_sym_constant_token1,
      aux_sym_constant_token2,
      aux_sym_constant_token3,
      sym__boolean_literal,
      sym__code_block,
  [8357] = 5,
    ACTIONS(165), 1,
      aux_sym__decimal_literal_token1,
    STATE(31), 1,
      sym__decimal_literal,
    STATE(840), 1,
      sym_constant,
    ACTIONS(163), 2,
      sym__string_literal,
      sym__float_literal,
    ACTIONS(157), 5,
      aux_sym_constant_token1,
      aux_sym_constant_token2,
      aux_sym_constant_token3,
      sym__boolean_literal,
      sym__code_block,
  [8378] = 6,
    ACTIONS(314), 1,
      aux_sym_create_keyspace_token1,
    ACTIONS(752), 1,
      aux_sym_drop_index_token1,
    ACTIONS(754), 1,
      aux_sym_alter_table_add_token1,
    ACTIONS(756), 1,
      aux_sym_alter_table_rename_token1,
    STATE(267), 1,
      sym_alter_table_operation,
    STATE(266), 5,
      sym_with_element,
      sym_alter_table_add,
      sym_alter_table_drop_columns,
      sym_alter_table_drop_compact_storage,
      sym_alter_table_rename,
  [8401] = 5,
    ACTIONS(165), 1,
      aux_sym__decimal_literal_token1,
    STATE(31), 1,
      sym__decimal_literal,
    STATE(538), 1,
      sym_constant,
    ACTIONS(163), 2,
      sym__string_literal,
      sym__float_literal,
    ACTIONS(157), 5,
      aux_sym_constant_token1,
      aux_sym_constant_token2,
      aux_sym_constant_token3,
      sym__boolean_literal,
      sym__code_block,
  [8422] = 3,
    ACTIONS(726), 1,
      aux_sym_privilege_token1,
    STATE(935), 1,
      sym_privilege,
    ACTIONS(724), 8,
      aux_sym_select_statement_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_privilege_token3,
      aux_sym_privilege_token4,
      aux_sym_privilege_token5,
      aux_sym_privilege_token6,
      aux_sym_privilege_token7,
  [8439] = 3,
    ACTIONS(726), 1,
      aux_sym_privilege_token1,
    STATE(936), 1,
      sym_privilege,
    ACTIONS(724), 8,
      aux_sym_select_statement_token1,
      aux_sym_create_index_token1,
      aux_sym_drop_index_token1,
      aux_sym_privilege_token3,
      aux_sym_privilege_token4,
      aux_sym_privilege_token5,
      aux_sym_privilege_token6,
      aux_sym_privilege_token7,
  [8456] = 6,
    ACTIONS(758), 1,
      anon_sym_LPAREN,
    ACTIONS(764), 1,
      aux_sym_relation_element_token1,
    ACTIONS(766), 1,
      aux_sym_relation_contains_key_token1,
    ACTIONS(768), 1,
      aux_sym_column_not_null_token1,
    ACTIONS(760), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(762), 4,
      anon_sym_LT_EQ,
      anon_sym_LT_GT,
      anon_sym_EQ,
      anon_sym_GT_EQ,
  [8479] = 5,
    ACTIONS(165), 1,
      aux_sym__decimal_literal_token1,
    STATE(31), 1,
      sym__decimal_literal,
    STATE(536), 1,
      sym_constant,
    ACTIONS(163), 2,
      sym__string_literal,
      sym__float_literal,
    ACTIONS(157), 5,
      aux_sym_constant_token1,
      aux_sym_constant_token2,
      aux_sym_constant_token3,
      sym__boolean_literal,
      sym__code_block,
  [8500] = 5,
    ACTIONS(165), 1,
      aux_sym__decimal_literal_token1,
    STATE(31), 1,
      sym__decimal_literal,
    STATE(460), 1,
      sym_constant,
    ACTIONS(163), 2,
      sym__string_literal,
      sym__float_literal,
    ACTIONS(157), 5,
      aux_sym_constant_token1,
      aux_sym_constant_token2,
      aux_sym_constant_token3,
      sym__boolean_literal,
      sym__code_block,
  [8521] = 10,
    ACTIONS(770), 1,
      aux_sym_truncate_token2,
    ACTIONS(772), 1,
      aux_sym_create_index_token2,
    ACTIONS(774), 1,
      aux_sym_resource_token2,
    ACTIONS(776), 1,
      aux_sym_resource_token5,
    ACTIONS(778), 1,
      aux_sym_resource_token6,
    ACTIONS(780), 1,
      aux_sym_drop_aggregate_token1,
    ACTIONS(782), 1,
      aux_sym_drop_materialized_view_token1,
    ACTIONS(784), 1,
      aux_sym_drop_trigger_token1,
    ACTIONS(786), 1,
      aux_sym_drop_type_token1,
    ACTIONS(788), 1,
      aux_sym_drop_user_token1,
  [8552] = 5,
    ACTIONS(165), 1,
      aux_sym__decimal_literal_token1,
    STATE(31), 1,
      sym__decimal_literal,
    STATE(123), 1,
      sym_constant,
    ACTIONS(163), 2,
      sym__string_literal,
      sym__float_literal,
    ACTIONS(157), 5,
      aux_sym_constant_token1,
      aux_sym_constant_token2,
      aux_sym_constant_token3,
      sym__boolean_literal,
      sym__code_block,
  [8573] = 5,
    ACTIONS(758), 1,
      anon_sym_LPAREN,
    ACTIONS(764), 1,
      aux_sym_relation_element_token1,
    ACTIONS(766), 1,
      aux_sym_relation_contains_key_token1,
    ACTIONS(760), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(762), 4,
      anon_sym_LT_EQ,
      anon_sym_LT_GT,
      anon_sym_EQ,
      anon_sym_GT_EQ,
  [8593] = 7,
    ACTIONS(790), 1,
      anon_sym_LPAREN,
    ACTIONS(792), 1,
      aux_sym_delete_statement_token3,
    ACTIONS(794), 1,
      sym_object_name,
    STATE(60), 1,
      sym_relation_element,
    STATE(270), 1,
      sym_relation_elements,
    STATE(353), 1,
      sym_function_call,
    STATE(53), 2,
      sym_relation_contains_key,
      sym_relation_contains,
  [8616] = 7,
    ACTIONS(790), 1,
      anon_sym_LPAREN,
    ACTIONS(794), 1,
      sym_object_name,
    ACTIONS(796), 1,
      aux_sym_delete_statement_token3,
    STATE(60), 1,
      sym_relation_element,
    STATE(270), 1,
      sym_relation_elements,
    STATE(353), 1,
      sym_function_call,
    STATE(53), 2,
      sym_relation_contains_key,
      sym_relation_contains,
  [8639] = 6,
    ACTIONS(798), 1,
      aux_sym_index_keys_spec_token1,
    ACTIONS(800), 1,
      aux_sym_index_entries_s_spec_token1,
    ACTIONS(802), 1,
      aux_sym_index_full_spec_token1,
    ACTIONS(804), 1,
      sym_object_name,
    STATE(874), 1,
      sym_index_column_spec,
    STATE(832), 3,
      sym_index_keys_spec,
      sym_index_entries_s_spec,
      sym_index_full_spec,
  [8660] = 7,
    ACTIONS(790), 1,
      anon_sym_LPAREN,
    ACTIONS(794), 1,
      sym_object_name,
    ACTIONS(806), 1,
      aux_sym_delete_statement_token3,
    STATE(60), 1,
      sym_relation_element,
    STATE(270), 1,
      sym_relation_elements,
    STATE(353), 1,
      sym_function_call,
    STATE(53), 2,
      sym_relation_contains_key,
      sym_relation_contains,
  [8683] = 6,
    ACTIONS(798), 1,
      aux_sym_index_keys_spec_token1,
    ACTIONS(800), 1,
      aux_sym_index_entries_s_spec_token1,
    ACTIONS(802), 1,
      aux_sym_index_full_spec_token1,
    ACTIONS(804), 1,
      sym_object_name,
    STATE(831), 1,
      sym_index_column_spec,
    STATE(832), 3,
      sym_index_keys_spec,
      sym_index_entries_s_spec,
      sym_index_full_spec,
  [8704] = 7,
    ACTIONS(790), 1,
      anon_sym_LPAREN,
    ACTIONS(794), 1,
      sym_object_name,
    ACTIONS(808), 1,
      aux_sym_delete_statement_token3,
    STATE(60), 1,
      sym_relation_element,
    STATE(270), 1,
      sym_relation_elements,
    STATE(353), 1,
      sym_function_call,
    STATE(53), 2,
      sym_relation_contains_key,
      sym_relation_contains,
  [8727] = 6,
    ACTIONS(810), 1,
      aux_sym_compact_storage_token1,
    ACTIONS(812), 1,
      aux_sym_clustering_order_token1,
    ACTIONS(814), 1,
      sym_object_name,
    STATE(262), 1,
      sym_table_options,
    STATE(757), 1,
      sym_table_option_name,
    STATE(147), 3,
      sym_table_option_item,
      sym_compact_storage,
      sym_clustering_order,
  [8748] = 7,
    ACTIONS(790), 1,
      anon_sym_LPAREN,
    ACTIONS(794), 1,
      sym_object_name,
    ACTIONS(816), 1,
      aux_sym_delete_statement_token3,
    STATE(60), 1,
      sym_relation_element,
    STATE(270), 1,
      sym_relation_elements,
    STATE(353), 1,
      sym_function_call,
    STATE(53), 2,
      sym_relation_contains_key,
      sym_relation_contains,
  [8771] = 6,
    ACTIONS(798), 1,
      aux_sym_index_keys_spec_token1,
    ACTIONS(800), 1,
      aux_sym_index_entries_s_spec_token1,
    ACTIONS(802), 1,
      aux_sym_index_full_spec_token1,
    ACTIONS(804), 1,
      sym_object_name,
    STATE(779), 1,
      sym_index_column_spec,
    STATE(832), 3,
      sym_index_keys_spec,
      sym_index_entries_s_spec,
      sym_index_full_spec,
  [8792] = 6,
    ACTIONS(798), 1,
      aux_sym_index_keys_spec_token1,
    ACTIONS(800), 1,
      aux_sym_index_entries_s_spec_token1,
    ACTIONS(802), 1,
      aux_sym_index_full_spec_token1,
    ACTIONS(804), 1,
      sym_object_name,
    STATE(721), 1,
      sym_index_column_spec,
    STATE(832), 3,
      sym_index_keys_spec,
      sym_index_entries_s_spec,
      sym_index_full_spec,
  [8813] = 7,
    ACTIONS(790), 1,
      anon_sym_LPAREN,
    ACTIONS(794), 1,
      sym_object_name,
    ACTIONS(818), 1,
      aux_sym_delete_statement_token3,
    STATE(60), 1,
      sym_relation_element,
    STATE(270), 1,
      sym_relation_elements,
    STATE(353), 1,
      sym_function_call,
    STATE(53), 2,
      sym_relation_contains_key,
      sym_relation_contains,
  [8836] = 7,
    ACTIONS(790), 1,
      anon_sym_LPAREN,
    ACTIONS(794), 1,
      sym_object_name,
    ACTIONS(820), 1,
      aux_sym_delete_statement_token3,
    STATE(60), 1,
      sym_relation_element,
    STATE(270), 1,
      sym_relation_elements,
    STATE(353), 1,
      sym_function_call,
    STATE(53), 2,
      sym_relation_contains_key,
      sym_relation_contains,
  [8859] = 5,
    ACTIONS(167), 1,
      anon_sym_LBRACK,
    ACTIONS(169), 1,
      anon_sym_LBRACE,
    ACTIONS(822), 1,
      aux_sym__decimal_literal_token1,
    STATE(668), 1,
      sym__decimal_literal,
    STATE(661), 3,
      sym_assignment_map,
      sym_assignment_set,
      sym_assignment_list,
  [8877] = 7,
    ACTIONS(824), 1,
      aux_sym_truncate_token2,
    ACTIONS(826), 1,
      aux_sym_privilege_token1,
    ACTIONS(828), 1,
      aux_sym_resource_token2,
    ACTIONS(830), 1,
      aux_sym_resource_token5,
    ACTIONS(832), 1,
      aux_sym_resource_token6,
    ACTIONS(834), 1,
      sym_object_name,
    STATE(705), 1,
      sym_resource,
  [8899] = 7,
    ACTIONS(824), 1,
      aux_sym_truncate_token2,
    ACTIONS(826), 1,
      aux_sym_privilege_token1,
    ACTIONS(828), 1,
      aux_sym_resource_token2,
    ACTIONS(830), 1,
      aux_sym_resource_token5,
    ACTIONS(832), 1,
      aux_sym_resource_token6,
    ACTIONS(834), 1,
      sym_object_name,
    STATE(727), 1,
      sym_resource,
  [8921] = 6,
    ACTIONS(790), 1,
      anon_sym_LPAREN,
    ACTIONS(836), 1,
      sym_object_name,
    STATE(60), 1,
      sym_relation_element,
    STATE(81), 1,
      sym_relation_elements,
    STATE(353), 1,
      sym_function_call,
    STATE(53), 2,
      sym_relation_contains_key,
      sym_relation_contains,
  [8941] = 3,
    ACTIONS(842), 1,
      aux_sym_relation_element_token1,
    ACTIONS(838), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(840), 4,
      anon_sym_LT_EQ,
      anon_sym_LT_GT,
      anon_sym_EQ,
      anon_sym_GT_EQ,
  [8955] = 5,
    ACTIONS(844), 1,
      aux_sym_privilege_token3,
    ACTIONS(846), 1,
      aux_sym_alter_table_add_token1,
    ACTIONS(848), 1,
      aux_sym_alter_table_rename_token1,
    STATE(274), 1,
      sym_alter_type_operation,
    STATE(275), 3,
      sym_alter_type_alter_type,
      sym_alter_type_add,
      sym_alter_type_rename,
  [8973] = 7,
    ACTIONS(824), 1,
      aux_sym_truncate_token2,
    ACTIONS(826), 1,
      aux_sym_privilege_token1,
    ACTIONS(828), 1,
      aux_sym_resource_token2,
    ACTIONS(830), 1,
      aux_sym_resource_token5,
    ACTIONS(832), 1,
      aux_sym_resource_token6,
    ACTIONS(834), 1,
      sym_object_name,
    STATE(162), 1,
      sym_resource,
  [8995] = 5,
    ACTIONS(810), 1,
      aux_sym_compact_storage_token1,
    ACTIONS(812), 1,
      aux_sym_clustering_order_token1,
    ACTIONS(814), 1,
      sym_object_name,
    STATE(757), 1,
      sym_table_option_name,
    STATE(165), 3,
      sym_table_option_item,
      sym_compact_storage,
      sym_clustering_order,
  [9013] = 6,
    ACTIONS(790), 1,
      anon_sym_LPAREN,
    ACTIONS(850), 1,
      sym_object_name,
    STATE(48), 1,
      sym_relation_element,
    STATE(353), 1,
      sym_function_call,
    STATE(568), 1,
      sym_column_not_null,
    STATE(53), 2,
      sym_relation_contains_key,
      sym_relation_contains,
  [9033] = 7,
    ACTIONS(852), 1,
      aux_sym_select_statement_token2,
    ACTIONS(854), 1,
      aux_sym_select_statement_token3,
    ACTIONS(856), 1,
      anon_sym_STAR,
    ACTIONS(858), 1,
      sym_object_name,
    STATE(478), 1,
      sym_function_call,
    STATE(481), 1,
      sym_select_element,
    STATE(526), 1,
      sym_select_elements,
  [9055] = 3,
    ACTIONS(864), 1,
      aux_sym_relation_element_token1,
    ACTIONS(860), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(862), 4,
      anon_sym_LT_EQ,
      anon_sym_LT_GT,
      anon_sym_EQ,
      anon_sym_GT_EQ,
  [9069] = 2,
    ACTIONS(866), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(868), 4,
      anon_sym_LT_EQ,
      anon_sym_LT_GT,
      anon_sym_EQ,
      anon_sym_GT_EQ,
  [9080] = 6,
    ACTIONS(870), 1,
      aux_sym_truncate_token2,
    ACTIONS(872), 1,
      aux_sym_resource_token2,
    ACTIONS(874), 1,
      aux_sym_resource_token6,
    ACTIONS(876), 1,
      aux_sym_drop_materialized_view_token1,
    ACTIONS(878), 1,
      aux_sym_drop_type_token1,
    ACTIONS(880), 1,
      aux_sym_drop_user_token1,
  [9099] = 6,
    ACTIONS(856), 1,
      anon_sym_STAR,
    ACTIONS(858), 1,
      sym_object_name,
    ACTIONS(882), 1,
      aux_sym_select_statement_token3,
    STATE(478), 1,
      sym_function_call,
    STATE(481), 1,
      sym_select_element,
    STATE(554), 1,
      sym_select_elements,
  [9118] = 5,
    ACTIONS(790), 1,
      anon_sym_LPAREN,
    ACTIONS(836), 1,
      sym_object_name,
    STATE(48), 1,
      sym_relation_element,
    STATE(353), 1,
      sym_function_call,
    STATE(53), 2,
      sym_relation_contains_key,
      sym_relation_contains,
  [9135] = 4,
    ACTIONS(884), 1,
      anon_sym_COMMA,
    ACTIONS(886), 1,
      anon_sym_RPAREN,
    STATE(510), 1,
      aux_sym_clustering_order_repeat1,
    ACTIONS(888), 2,
      aux_sym_order_spec_token3,
      aux_sym_order_spec_token4,
  [9149] = 1,
    ACTIONS(890), 5,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      aux_sym_where_spec_token1,
      anon_sym_PLUS,
      anon_sym_DASH,
  [9157] = 1,
    ACTIONS(892), 5,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      aux_sym_where_spec_token1,
      anon_sym_PLUS,
      anon_sym_DASH,
  [9165] = 5,
    ACTIONS(894), 1,
      aux_sym_role_with_option_token1,
    ACTIONS(896), 1,
      aux_sym_role_with_option_token2,
    ACTIONS(898), 1,
      aux_sym_role_with_option_token3,
    ACTIONS(900), 1,
      aux_sym_role_with_option_token4,
    STATE(194), 1,
      sym_role_with_option,
  [9181] = 5,
    ACTIONS(902), 1,
      aux_sym_from_spec_token1,
    ACTIONS(904), 1,
      sym_object_name,
    STATE(385), 1,
      sym_from_spec,
    STATE(468), 1,
      sym_delete_column_item,
    STATE(530), 1,
      sym_delete_column_list,
  [9197] = 3,
    ACTIONS(908), 1,
      aux_sym_using_timestamp_spec_token1,
    STATE(474), 1,
      sym_using_timestamp_spec,
    ACTIONS(906), 3,
      aux_sym_delete_statement_token1,
      aux_sym_insert_statement_token1,
      aux_sym_update_token1,
  [9209] = 5,
    ACTIONS(856), 1,
      anon_sym_STAR,
    ACTIONS(910), 1,
      sym_object_name,
    STATE(478), 1,
      sym_function_call,
    STATE(481), 1,
      sym_select_element,
    STATE(588), 1,
      sym_select_elements,
  [9225] = 1,
    ACTIONS(912), 5,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      aux_sym_where_spec_token1,
      anon_sym_PLUS,
      anon_sym_DASH,
  [9233] = 3,
    ACTIONS(916), 1,
      anon_sym_LBRACE,
    ACTIONS(914), 2,
      sym__string_literal,
      sym__float_literal,
    STATE(166), 2,
      sym_option_hash,
      sym_table_option_value,
  [9245] = 1,
    ACTIONS(918), 5,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      aux_sym_where_spec_token1,
      anon_sym_PLUS,
      anon_sym_DASH,
  [9253] = 1,
    ACTIONS(920), 5,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      aux_sym_where_spec_token1,
      anon_sym_PLUS,
      anon_sym_DASH,
  [9261] = 1,
    ACTIONS(922), 5,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      aux_sym_where_spec_token1,
      anon_sym_PLUS,
      anon_sym_DASH,
  [9269] = 5,
    ACTIONS(894), 1,
      aux_sym_role_with_option_token1,
    ACTIONS(896), 1,
      aux_sym_role_with_option_token2,
    ACTIONS(898), 1,
      aux_sym_role_with_option_token3,
    ACTIONS(900), 1,
      aux_sym_role_with_option_token4,
    STATE(124), 1,
      sym_role_with_option,
  [9285] = 3,
    ACTIONS(908), 1,
      aux_sym_using_timestamp_spec_token1,
    STATE(498), 1,
      sym_using_timestamp_spec,
    ACTIONS(924), 3,
      aux_sym_delete_statement_token1,
      aux_sym_insert_statement_token1,
      aux_sym_update_token1,
  [9297] = 5,
    ACTIONS(926), 1,
      sym__string_literal,
    ACTIONS(928), 1,
      aux_sym_delete_statement_token2,
    ACTIONS(930), 1,
      aux_sym_create_index_token3,
    ACTIONS(932), 1,
      sym_object_name,
    STATE(900), 1,
      sym_short_index_name,
  [9313] = 4,
    ACTIONS(934), 1,
      anon_sym_LPAREN,
    ACTIONS(936), 1,
      sym_object_name,
    STATE(776), 1,
      sym_primary_key_definition,
    STATE(777), 2,
      sym_compound_key,
      sym_composite_key,
  [9327] = 5,
    ACTIONS(902), 1,
      aux_sym_from_spec_token1,
    ACTIONS(904), 1,
      sym_object_name,
    STATE(377), 1,
      sym_from_spec,
    STATE(468), 1,
      sym_delete_column_item,
    STATE(642), 1,
      sym_delete_column_list,
  [9343] = 5,
    ACTIONS(856), 1,
      anon_sym_STAR,
    ACTIONS(910), 1,
      sym_object_name,
    STATE(478), 1,
      sym_function_call,
    STATE(481), 1,
      sym_select_element,
    STATE(554), 1,
      sym_select_elements,
  [9359] = 1,
    ACTIONS(938), 5,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      aux_sym_where_spec_token1,
      anon_sym_PLUS,
      anon_sym_DASH,
  [9367] = 2,
    ACTIONS(940), 2,
      anon_sym_COMMA,
      aux_sym_where_spec_token1,
    ACTIONS(942), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
  [9376] = 4,
    ACTIONS(134), 1,
      aux_sym_where_spec_token1,
    ACTIONS(908), 1,
      aux_sym_using_timestamp_spec_token1,
    STATE(112), 1,
      sym_where_spec,
    STATE(595), 1,
      sym_using_timestamp_spec,
  [9389] = 3,
    ACTIONS(944), 1,
      anon_sym_COMMA,
    STATE(382), 1,
      aux_sym_relation_element_repeat1,
    ACTIONS(946), 2,
      anon_sym_RPAREN,
      aux_sym_from_spec_token1,
  [9400] = 4,
    ACTIONS(926), 1,
      sym__string_literal,
    ACTIONS(932), 1,
      sym_object_name,
    ACTIONS(948), 1,
      aux_sym_create_index_token3,
    STATE(671), 1,
      sym_short_index_name,
  [9413] = 4,
    ACTIONS(950), 1,
      aux_sym_relation_elements_token1,
    ACTIONS(952), 1,
      aux_sym_primary_key_column_token1,
    STATE(489), 1,
      aux_sym_materialized_view_where_repeat1,
    STATE(502), 1,
      aux_sym_relation_elements_repeat1,
  [9426] = 3,
    ACTIONS(954), 1,
      anon_sym_COMMA,
    STATE(381), 1,
      aux_sym_assignment_set_repeat1,
    ACTIONS(957), 2,
      anon_sym_RBRACK,
      anon_sym_RBRACE,
  [9437] = 3,
    ACTIONS(959), 1,
      anon_sym_COMMA,
    STATE(382), 1,
      aux_sym_relation_element_repeat1,
    ACTIONS(962), 2,
      anon_sym_RPAREN,
      aux_sym_from_spec_token1,
  [9448] = 4,
    ACTIONS(134), 1,
      aux_sym_where_spec_token1,
    ACTIONS(908), 1,
      aux_sym_using_timestamp_spec_token1,
    STATE(139), 1,
      sym_where_spec,
    STATE(618), 1,
      sym_using_timestamp_spec,
  [9461] = 3,
    ACTIONS(966), 1,
      aux_sym_primary_key_column_token1,
    STATE(558), 1,
      sym_primary_key_column,
    ACTIONS(964), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [9472] = 4,
    ACTIONS(134), 1,
      aux_sym_where_spec_token1,
    ACTIONS(908), 1,
      aux_sym_using_timestamp_spec_token1,
    STATE(138), 1,
      sym_where_spec,
    STATE(555), 1,
      sym_using_timestamp_spec,
  [9485] = 2,
    ACTIONS(968), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
    ACTIONS(970), 2,
      aux_sym_order_spec_token3,
      aux_sym_order_spec_token4,
  [9494] = 4,
    ACTIONS(972), 1,
      aux_sym_primary_key_column_token1,
    ACTIONS(974), 1,
      sym_object_name,
    STATE(561), 1,
      sym_column_definition,
    STATE(904), 1,
      sym_primary_key_element,
  [9507] = 4,
    ACTIONS(758), 1,
      anon_sym_LPAREN,
    ACTIONS(976), 1,
      anon_sym_COMMA,
    ACTIONS(978), 1,
      anon_sym_RPAREN,
    STATE(447), 1,
      aux_sym_function_args_repeat1,
  [9520] = 3,
    ACTIONS(758), 1,
      anon_sym_LPAREN,
    ACTIONS(982), 1,
      aux_sym_select_element_token1,
    ACTIONS(980), 2,
      anon_sym_COMMA,
      aux_sym_from_spec_token1,
  [9531] = 4,
    ACTIONS(257), 1,
      aux_sym_using_timestamp_spec_token1,
    ACTIONS(984), 1,
      aux_sym_update_assignments_token1,
    STATE(639), 1,
      sym_update_assignments,
    STATE(659), 1,
      sym_using_ttl_timestamp,
  [9544] = 4,
    ACTIONS(950), 1,
      aux_sym_relation_elements_token1,
    ACTIONS(986), 1,
      aux_sym_primary_key_column_token1,
    STATE(380), 1,
      aux_sym_materialized_view_where_repeat1,
    STATE(509), 1,
      aux_sym_relation_elements_repeat1,
  [9557] = 4,
    ACTIONS(257), 1,
      aux_sym_using_timestamp_spec_token1,
    ACTIONS(984), 1,
      aux_sym_update_assignments_token1,
    STATE(579), 1,
      sym_using_ttl_timestamp,
    STATE(580), 1,
      sym_update_assignments,
  [9570] = 1,
    ACTIONS(988), 4,
      aux_sym_where_spec_token1,
      aux_sym_delete_statement_token1,
      aux_sym_insert_statement_token1,
      aux_sym_update_token1,
  [9577] = 2,
    ACTIONS(992), 1,
      aux_sym_begin_batch_token5,
    ACTIONS(990), 3,
      aux_sym_begin_batch_token2,
      aux_sym_begin_batch_token3,
      aux_sym_begin_batch_token4,
  [9586] = 3,
    ACTIONS(944), 1,
      anon_sym_COMMA,
    STATE(378), 1,
      aux_sym_relation_element_repeat1,
    ACTIONS(994), 2,
      anon_sym_RPAREN,
      aux_sym_from_spec_token1,
  [9597] = 4,
    ACTIONS(972), 1,
      aux_sym_primary_key_column_token1,
    ACTIONS(974), 1,
      sym_object_name,
    STATE(561), 1,
      sym_column_definition,
    STATE(713), 1,
      sym_primary_key_element,
  [9610] = 3,
    ACTIONS(996), 1,
      anon_sym_COMMA,
    ACTIONS(998), 1,
      anon_sym_RBRACE,
    STATE(492), 1,
      aux_sym_option_hash_repeat1,
  [9620] = 3,
    ACTIONS(1000), 1,
      aux_sym_create_function_token1,
    ACTIONS(1002), 1,
      aux_sym_return_mode_token1,
    STATE(683), 1,
      sym_return_mode,
  [9630] = 3,
    ACTIONS(1004), 1,
      anon_sym_COMMA,
    ACTIONS(1006), 1,
      anon_sym_RPAREN,
    STATE(411), 1,
      aux_sym_init_cond_nested_list_repeat1,
  [9640] = 3,
    ACTIONS(822), 1,
      aux_sym__decimal_literal_token1,
    ACTIONS(1008), 1,
      sym__string_literal,
    STATE(812), 1,
      sym__decimal_literal,
  [9650] = 3,
    ACTIONS(1010), 1,
      anon_sym_COMMA,
    ACTIONS(1012), 1,
      anon_sym_RPAREN,
    STATE(426), 1,
      aux_sym_init_cond_hash_repeat1,
  [9660] = 3,
    ACTIONS(1014), 1,
      anon_sym_COMMA,
    ACTIONS(1017), 1,
      anon_sym_RBRACE,
    STATE(402), 1,
      aux_sym_assignment_map_repeat1,
  [9670] = 3,
    ACTIONS(1019), 1,
      anon_sym_COMMA,
    ACTIONS(1021), 1,
      aux_sym_from_spec_token1,
    STATE(516), 1,
      aux_sym_select_elements_repeat1,
  [9680] = 3,
    ACTIONS(910), 1,
      sym_object_name,
    STATE(478), 1,
      sym_function_call,
    STATE(590), 1,
      sym_select_element,
  [9690] = 3,
    ACTIONS(116), 1,
      anon_sym_COMMA,
    ACTIONS(1023), 1,
      anon_sym_RPAREN,
    STATE(469), 1,
      aux_sym_relation_element_repeat2,
  [9700] = 3,
    ACTIONS(1025), 1,
      anon_sym_COMMA,
    ACTIONS(1028), 1,
      anon_sym_RPAREN,
    STATE(406), 1,
      aux_sym_expression_list_repeat1,
  [9710] = 3,
    ACTIONS(301), 1,
      anon_sym_COMMA,
    ACTIONS(1030), 1,
      anon_sym_RPAREN,
    STATE(92), 1,
      aux_sym_create_function_repeat1,
  [9720] = 3,
    ACTIONS(822), 1,
      aux_sym__decimal_literal_token1,
    ACTIONS(1032), 1,
      sym__string_literal,
    STATE(612), 1,
      sym__decimal_literal,
  [9730] = 3,
    ACTIONS(1034), 1,
      anon_sym_COMMA,
    ACTIONS(1036), 1,
      anon_sym_RPAREN,
    STATE(465), 1,
      aux_sym_init_cond_list_repeat1,
  [9740] = 3,
    ACTIONS(1038), 1,
      anon_sym_COMMA,
    ACTIONS(1040), 1,
      anon_sym_RBRACE,
    STATE(490), 1,
      aux_sym_replication_list_repeat1,
  [9750] = 3,
    ACTIONS(1004), 1,
      anon_sym_COMMA,
    ACTIONS(1042), 1,
      anon_sym_RPAREN,
    STATE(477), 1,
      aux_sym_init_cond_nested_list_repeat1,
  [9760] = 2,
    ACTIONS(1044), 1,
      aux_sym_resource_token1,
    ACTIONS(1046), 2,
      aux_sym_resource_token3,
      aux_sym_resource_token4,
  [9768] = 3,
    ACTIONS(1000), 1,
      aux_sym_create_function_token1,
    ACTIONS(1002), 1,
      aux_sym_return_mode_token1,
    STATE(787), 1,
      sym_return_mode,
  [9778] = 3,
    ACTIONS(301), 1,
      anon_sym_COMMA,
    ACTIONS(1048), 1,
      anon_sym_RPAREN,
    STATE(92), 1,
      aux_sym_create_function_repeat1,
  [9788] = 3,
    ACTIONS(1050), 1,
      aux_sym_select_statement_token3,
    ACTIONS(1052), 1,
      aux_sym_insert_values_spec_token1,
    STATE(99), 1,
      sym_insert_values_spec,
  [9798] = 3,
    ACTIONS(1054), 1,
      anon_sym_COMMA,
    ACTIONS(1056), 1,
      anon_sym_RBRACE,
    STATE(461), 1,
      aux_sym_assignment_set_repeat1,
  [9808] = 2,
    ACTIONS(1060), 1,
      anon_sym_COLON,
    ACTIONS(1058), 2,
      anon_sym_COMMA,
      anon_sym_RBRACE,
  [9816] = 3,
    ACTIONS(1062), 1,
      aux_sym_delete_statement_token2,
    ACTIONS(1064), 1,
      sym_object_name,
    STATE(286), 1,
      sym_user_name,
  [9826] = 3,
    ACTIONS(1066), 1,
      aux_sym_delete_statement_token2,
    ACTIONS(1068), 1,
      sym_object_name,
    STATE(287), 1,
      sym_type_name,
  [9836] = 3,
    ACTIONS(1070), 1,
      anon_sym_COMMA,
    ACTIONS(1072), 1,
      aux_sym_where_spec_token1,
    STATE(438), 1,
      aux_sym_update_assignments_repeat1,
  [9846] = 2,
    ACTIONS(758), 1,
      anon_sym_LPAREN,
    ACTIONS(1074), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [9854] = 3,
    ACTIONS(1074), 1,
      anon_sym_RPAREN,
    ACTIONS(1076), 1,
      anon_sym_COMMA,
    STATE(422), 1,
      aux_sym_function_args_repeat1,
  [9864] = 3,
    ACTIONS(1079), 1,
      aux_sym_delete_statement_token2,
    ACTIONS(1081), 1,
      sym_object_name,
    STATE(847), 1,
      sym_trigger_name,
  [9874] = 3,
    ACTIONS(1054), 1,
      anon_sym_COMMA,
    ACTIONS(1083), 1,
      anon_sym_RBRACK,
    STATE(473), 1,
      aux_sym_assignment_set_repeat1,
  [9884] = 3,
    ACTIONS(944), 1,
      anon_sym_COMMA,
    ACTIONS(1085), 1,
      anon_sym_RPAREN,
    STATE(382), 1,
      aux_sym_relation_element_repeat1,
  [9894] = 3,
    ACTIONS(1010), 1,
      anon_sym_COMMA,
    ACTIONS(1087), 1,
      anon_sym_RPAREN,
    STATE(495), 1,
      aux_sym_init_cond_hash_repeat1,
  [9904] = 3,
    ACTIONS(1089), 1,
      anon_sym_COMMA,
    ACTIONS(1091), 1,
      anon_sym_GT,
    STATE(429), 1,
      aux_sym_tuple_type_repeat1,
  [9914] = 3,
    ACTIONS(1093), 1,
      aux_sym_delete_statement_token2,
    ACTIONS(1095), 1,
      sym_object_name,
    STATE(285), 1,
      sym_aggregate_name,
  [9924] = 3,
    ACTIONS(1097), 1,
      anon_sym_COMMA,
    ACTIONS(1100), 1,
      anon_sym_GT,
    STATE(429), 1,
      aux_sym_tuple_type_repeat1,
  [9934] = 3,
    ACTIONS(301), 1,
      anon_sym_COMMA,
    ACTIONS(1102), 1,
      anon_sym_RPAREN,
    STATE(92), 1,
      aux_sym_create_function_repeat1,
  [9944] = 3,
    ACTIONS(1104), 1,
      aux_sym_delete_statement_token2,
    ACTIONS(1106), 1,
      sym_object_name,
    STATE(256), 1,
      sym_role_name,
  [9954] = 3,
    ACTIONS(301), 1,
      anon_sym_COMMA,
    ACTIONS(1108), 1,
      anon_sym_RPAREN,
    STATE(484), 1,
      aux_sym_create_function_repeat1,
  [9964] = 3,
    ACTIONS(1110), 1,
      aux_sym_delete_statement_token2,
    ACTIONS(1112), 1,
      sym_object_name,
    STATE(216), 1,
      sym_function_name,
  [9974] = 3,
    ACTIONS(1114), 1,
      aux_sym_delete_statement_token2,
    ACTIONS(1116), 1,
      sym_object_name,
    STATE(212), 1,
      sym_keyspace_name,
  [9984] = 3,
    ACTIONS(1118), 1,
      aux_sym_delete_statement_token2,
    ACTIONS(1120), 1,
      sym_object_name,
    STATE(211), 1,
      sym_index_name,
  [9994] = 3,
    ACTIONS(1048), 1,
      anon_sym_RPAREN,
    ACTIONS(1122), 1,
      sym_object_name,
    STATE(501), 1,
      sym_typed_name,
  [10004] = 3,
    ACTIONS(1124), 1,
      sym_object_name,
    STATE(420), 1,
      sym_assignment_element,
    STATE(740), 1,
      sym_indexed_column,
  [10014] = 3,
    ACTIONS(1070), 1,
      anon_sym_COMMA,
    ACTIONS(1126), 1,
      aux_sym_where_spec_token1,
    STATE(508), 1,
      aux_sym_update_assignments_repeat1,
  [10024] = 1,
    ACTIONS(957), 3,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_RBRACE,
  [10030] = 3,
    ACTIONS(1128), 1,
      aux_sym_delete_statement_token2,
    ACTIONS(1130), 1,
      sym_object_name,
    STATE(196), 1,
      sym_table_name,
  [10040] = 3,
    ACTIONS(1124), 1,
      sym_object_name,
    STATE(534), 1,
      sym_assignment_element,
    STATE(740), 1,
      sym_indexed_column,
  [10050] = 3,
    ACTIONS(884), 1,
      anon_sym_COMMA,
    ACTIONS(1132), 1,
      anon_sym_RPAREN,
    STATE(456), 1,
      aux_sym_clustering_order_repeat1,
  [10060] = 3,
    ACTIONS(1134), 1,
      anon_sym_COMMA,
    ACTIONS(1136), 1,
      anon_sym_RBRACE,
    STATE(506), 1,
      aux_sym_assignment_map_repeat1,
  [10070] = 3,
    ACTIONS(1064), 1,
      sym_object_name,
    ACTIONS(1138), 1,
      aux_sym_delete_statement_token2,
    STATE(574), 1,
      sym_user_name,
  [10080] = 3,
    ACTIONS(1140), 1,
      anon_sym_COMMA,
    ACTIONS(1142), 1,
      aux_sym_from_spec_token1,
    STATE(500), 1,
      aux_sym_delete_column_list_repeat1,
  [10090] = 3,
    ACTIONS(1068), 1,
      sym_object_name,
    ACTIONS(1144), 1,
      aux_sym_delete_statement_token2,
    STATE(868), 1,
      sym_type_name,
  [10100] = 3,
    ACTIONS(976), 1,
      anon_sym_COMMA,
    ACTIONS(1146), 1,
      anon_sym_RPAREN,
    STATE(422), 1,
      aux_sym_function_args_repeat1,
  [10110] = 3,
    ACTIONS(1148), 1,
      anon_sym_COMMA,
    ACTIONS(1150), 1,
      anon_sym_RPAREN,
    STATE(470), 1,
      aux_sym_column_definition_list_repeat1,
  [10120] = 3,
    ACTIONS(1089), 1,
      anon_sym_COMMA,
    ACTIONS(1152), 1,
      anon_sym_GT,
    STATE(427), 1,
      aux_sym_tuple_type_repeat1,
  [10130] = 3,
    ACTIONS(1081), 1,
      sym_object_name,
    ACTIONS(1154), 1,
      aux_sym_delete_statement_token2,
    STATE(873), 1,
      sym_trigger_name,
  [10140] = 3,
    ACTIONS(1095), 1,
      sym_object_name,
    ACTIONS(1156), 1,
      aux_sym_delete_statement_token2,
    STATE(742), 1,
      sym_aggregate_name,
  [10150] = 3,
    ACTIONS(1095), 1,
      sym_object_name,
    ACTIONS(1158), 1,
      aux_sym_delete_statement_token2,
    STATE(879), 1,
      sym_aggregate_name,
  [10160] = 3,
    ACTIONS(1106), 1,
      sym_object_name,
    ACTIONS(1160), 1,
      aux_sym_delete_statement_token2,
    STATE(116), 1,
      sym_role_name,
  [10170] = 3,
    ACTIONS(1112), 1,
      sym_object_name,
    ACTIONS(1162), 1,
      aux_sym_delete_statement_token2,
    STATE(887), 1,
      sym_function_name,
  [10180] = 3,
    ACTIONS(1116), 1,
      sym_object_name,
    ACTIONS(1164), 1,
      aux_sym_delete_statement_token2,
    STATE(889), 1,
      sym_keyspace_name,
  [10190] = 3,
    ACTIONS(1166), 1,
      anon_sym_COMMA,
    ACTIONS(1169), 1,
      anon_sym_RPAREN,
    STATE(456), 1,
      aux_sym_clustering_order_repeat1,
  [10200] = 3,
    ACTIONS(1171), 1,
      aux_sym_delete_statement_token2,
    ACTIONS(1173), 1,
      sym_object_name,
    STATE(248), 1,
      sym_materialized_view_name,
  [10210] = 3,
    ACTIONS(1112), 1,
      sym_object_name,
    ACTIONS(1175), 1,
      aux_sym_delete_statement_token2,
    STATE(728), 1,
      sym_function_name,
  [10220] = 3,
    ACTIONS(1130), 1,
      sym_object_name,
    ACTIONS(1177), 1,
      aux_sym_delete_statement_token2,
    STATE(907), 1,
      sym_table_name,
  [10230] = 3,
    ACTIONS(1034), 1,
      anon_sym_COMMA,
    ACTIONS(1179), 1,
      anon_sym_RPAREN,
    STATE(409), 1,
      aux_sym_init_cond_list_repeat1,
  [10240] = 3,
    ACTIONS(1054), 1,
      anon_sym_COMMA,
    ACTIONS(1181), 1,
      anon_sym_RBRACE,
    STATE(381), 1,
      aux_sym_assignment_set_repeat1,
  [10250] = 3,
    ACTIONS(944), 1,
      anon_sym_COMMA,
    ACTIONS(1183), 1,
      anon_sym_RPAREN,
    STATE(425), 1,
      aux_sym_relation_element_repeat1,
  [10260] = 3,
    ACTIONS(1108), 1,
      anon_sym_RPAREN,
    ACTIONS(1122), 1,
      sym_object_name,
    STATE(518), 1,
      sym_typed_name,
  [10270] = 3,
    ACTIONS(326), 1,
      anon_sym_COMMA,
    ACTIONS(1185), 1,
      anon_sym_RPAREN,
    STATE(98), 1,
      aux_sym_clustering_key_list_repeat1,
  [10280] = 3,
    ACTIONS(1187), 1,
      anon_sym_COMMA,
    ACTIONS(1190), 1,
      anon_sym_RPAREN,
    STATE(465), 1,
      aux_sym_init_cond_list_repeat1,
  [10290] = 3,
    ACTIONS(1000), 1,
      aux_sym_create_function_token1,
    ACTIONS(1002), 1,
      aux_sym_return_mode_token1,
    STATE(843), 1,
      sym_return_mode,
  [10300] = 3,
    ACTIONS(301), 1,
      anon_sym_COMMA,
    ACTIONS(1192), 1,
      anon_sym_RPAREN,
    STATE(92), 1,
      aux_sym_create_function_repeat1,
  [10310] = 3,
    ACTIONS(1140), 1,
      anon_sym_COMMA,
    ACTIONS(1194), 1,
      aux_sym_from_spec_token1,
    STATE(445), 1,
      aux_sym_delete_column_list_repeat1,
  [10320] = 3,
    ACTIONS(116), 1,
      anon_sym_COMMA,
    ACTIONS(1196), 1,
      anon_sym_RPAREN,
    STATE(36), 1,
      aux_sym_relation_element_repeat2,
  [10330] = 3,
    ACTIONS(1198), 1,
      anon_sym_COMMA,
    ACTIONS(1201), 1,
      anon_sym_RPAREN,
    STATE(470), 1,
      aux_sym_column_definition_list_repeat1,
  [10340] = 3,
    ACTIONS(1000), 1,
      aux_sym_create_function_token1,
    ACTIONS(1002), 1,
      aux_sym_return_mode_token1,
    STATE(867), 1,
      sym_return_mode,
  [10350] = 3,
    ACTIONS(116), 1,
      anon_sym_COMMA,
    ACTIONS(1196), 1,
      anon_sym_RPAREN,
    STATE(513), 1,
      aux_sym_relation_element_repeat2,
  [10360] = 3,
    ACTIONS(1054), 1,
      anon_sym_COMMA,
    ACTIONS(1203), 1,
      anon_sym_RBRACK,
    STATE(381), 1,
      aux_sym_assignment_set_repeat1,
  [10370] = 1,
    ACTIONS(924), 3,
      aux_sym_delete_statement_token1,
      aux_sym_insert_statement_token1,
      aux_sym_update_token1,
  [10376] = 3,
    ACTIONS(1205), 1,
      sym_object_name,
    STATE(482), 1,
      sym_column_definition,
    STATE(716), 1,
      sym_column_definition_list,
  [10386] = 2,
    ACTIONS(1209), 1,
      anon_sym_LBRACK,
    ACTIONS(1207), 2,
      anon_sym_COMMA,
      aux_sym_from_spec_token1,
  [10394] = 3,
    ACTIONS(1211), 1,
      anon_sym_COMMA,
    ACTIONS(1214), 1,
      anon_sym_RPAREN,
    STATE(477), 1,
      aux_sym_init_cond_nested_list_repeat1,
  [10404] = 2,
    ACTIONS(1218), 1,
      aux_sym_select_element_token1,
    ACTIONS(1216), 2,
      anon_sym_COMMA,
      aux_sym_from_spec_token1,
  [10412] = 3,
    ACTIONS(326), 1,
      anon_sym_COMMA,
    ACTIONS(1220), 1,
      anon_sym_RPAREN,
    STATE(517), 1,
      aux_sym_clustering_key_list_repeat1,
  [10422] = 3,
    ACTIONS(1222), 1,
      anon_sym_COMMA,
    ACTIONS(1224), 1,
      anon_sym_RPAREN,
    STATE(499), 1,
      aux_sym_expression_list_repeat1,
  [10432] = 3,
    ACTIONS(1019), 1,
      anon_sym_COMMA,
    ACTIONS(1226), 1,
      aux_sym_from_spec_token1,
    STATE(403), 1,
      aux_sym_select_elements_repeat1,
  [10442] = 3,
    ACTIONS(1228), 1,
      anon_sym_COMMA,
    ACTIONS(1230), 1,
      anon_sym_RPAREN,
    STATE(448), 1,
      aux_sym_column_definition_list_repeat1,
  [10452] = 3,
    ACTIONS(301), 1,
      anon_sym_COMMA,
    ACTIONS(1232), 1,
      anon_sym_RPAREN,
    STATE(488), 1,
      aux_sym_create_function_repeat1,
  [10462] = 3,
    ACTIONS(301), 1,
      anon_sym_COMMA,
    ACTIONS(1234), 1,
      anon_sym_RPAREN,
    STATE(92), 1,
      aux_sym_create_function_repeat1,
  [10472] = 3,
    ACTIONS(1236), 1,
      aux_sym_delete_statement_token1,
    ACTIONS(1238), 1,
      aux_sym_insert_statement_token1,
    ACTIONS(1240), 1,
      aux_sym_update_token1,
  [10482] = 3,
    ACTIONS(301), 1,
      anon_sym_COMMA,
    ACTIONS(1242), 1,
      anon_sym_RPAREN,
    STATE(430), 1,
      aux_sym_create_function_repeat1,
  [10492] = 3,
    ACTIONS(1122), 1,
      sym_object_name,
    ACTIONS(1244), 1,
      anon_sym_RPAREN,
    STATE(505), 1,
      sym_typed_name,
  [10502] = 3,
    ACTIONS(301), 1,
      anon_sym_COMMA,
    ACTIONS(1246), 1,
      anon_sym_RPAREN,
    STATE(92), 1,
      aux_sym_create_function_repeat1,
  [10512] = 3,
    ACTIONS(1248), 1,
      aux_sym_relation_elements_token1,
    ACTIONS(1251), 1,
      aux_sym_primary_key_column_token1,
    STATE(489), 1,
      aux_sym_materialized_view_where_repeat1,
  [10522] = 3,
    ACTIONS(1253), 1,
      anon_sym_COMMA,
    ACTIONS(1256), 1,
      anon_sym_RBRACE,
    STATE(490), 1,
      aux_sym_replication_list_repeat1,
  [10532] = 3,
    ACTIONS(1000), 1,
      aux_sym_create_function_token1,
    ACTIONS(1002), 1,
      aux_sym_return_mode_token1,
    STATE(826), 1,
      sym_return_mode,
  [10542] = 3,
    ACTIONS(1258), 1,
      anon_sym_COMMA,
    ACTIONS(1261), 1,
      anon_sym_RBRACE,
    STATE(492), 1,
      aux_sym_option_hash_repeat1,
  [10552] = 1,
    ACTIONS(1263), 3,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      aux_sym_from_spec_token1,
  [10558] = 3,
    ACTIONS(1122), 1,
      sym_object_name,
    ACTIONS(1192), 1,
      anon_sym_RPAREN,
    STATE(432), 1,
      sym_typed_name,
  [10568] = 3,
    ACTIONS(1265), 1,
      anon_sym_COMMA,
    ACTIONS(1268), 1,
      anon_sym_RPAREN,
    STATE(495), 1,
      aux_sym_init_cond_hash_repeat1,
  [10578] = 3,
    ACTIONS(1205), 1,
      sym_object_name,
    STATE(482), 1,
      sym_column_definition,
    STATE(700), 1,
      sym_column_definition_list,
  [10588] = 3,
    ACTIONS(1050), 1,
      aux_sym_select_statement_token3,
    ACTIONS(1052), 1,
      aux_sym_insert_values_spec_token1,
    STATE(90), 1,
      sym_insert_values_spec,
  [10598] = 1,
    ACTIONS(1270), 3,
      aux_sym_delete_statement_token1,
      aux_sym_insert_statement_token1,
      aux_sym_update_token1,
  [10604] = 3,
    ACTIONS(1222), 1,
      anon_sym_COMMA,
    ACTIONS(1272), 1,
      anon_sym_RPAREN,
    STATE(406), 1,
      aux_sym_expression_list_repeat1,
  [10614] = 3,
    ACTIONS(1274), 1,
      anon_sym_COMMA,
    ACTIONS(1277), 1,
      aux_sym_from_spec_token1,
    STATE(500), 1,
      aux_sym_delete_column_list_repeat1,
  [10624] = 3,
    ACTIONS(301), 1,
      anon_sym_COMMA,
    ACTIONS(1279), 1,
      anon_sym_RPAREN,
    STATE(407), 1,
      aux_sym_create_function_repeat1,
  [10634] = 3,
    ACTIONS(183), 1,
      aux_sym_relation_elements_token1,
    ACTIONS(1281), 1,
      aux_sym_primary_key_column_token1,
    STATE(45), 1,
      aux_sym_relation_elements_repeat1,
  [10644] = 3,
    ACTIONS(1000), 1,
      aux_sym_create_function_token1,
    ACTIONS(1002), 1,
      aux_sym_return_mode_token1,
    STATE(952), 1,
      sym_return_mode,
  [10654] = 3,
    ACTIONS(1038), 1,
      anon_sym_COMMA,
    ACTIONS(1283), 1,
      anon_sym_RBRACE,
    STATE(410), 1,
      aux_sym_replication_list_repeat1,
  [10664] = 3,
    ACTIONS(301), 1,
      anon_sym_COMMA,
    ACTIONS(1285), 1,
      anon_sym_RPAREN,
    STATE(467), 1,
      aux_sym_create_function_repeat1,
  [10674] = 3,
    ACTIONS(1134), 1,
      anon_sym_COMMA,
    ACTIONS(1287), 1,
      anon_sym_RBRACE,
    STATE(402), 1,
      aux_sym_assignment_map_repeat1,
  [10684] = 3,
    ACTIONS(884), 1,
      anon_sym_COMMA,
    ACTIONS(1289), 1,
      anon_sym_RPAREN,
    STATE(442), 1,
      aux_sym_clustering_order_repeat1,
  [10694] = 3,
    ACTIONS(1291), 1,
      anon_sym_COMMA,
    ACTIONS(1294), 1,
      aux_sym_where_spec_token1,
    STATE(508), 1,
      aux_sym_update_assignments_repeat1,
  [10704] = 3,
    ACTIONS(183), 1,
      aux_sym_relation_elements_token1,
    ACTIONS(952), 1,
      aux_sym_primary_key_column_token1,
    STATE(45), 1,
      aux_sym_relation_elements_repeat1,
  [10714] = 3,
    ACTIONS(884), 1,
      anon_sym_COMMA,
    ACTIONS(1289), 1,
      anon_sym_RPAREN,
    STATE(456), 1,
      aux_sym_clustering_order_repeat1,
  [10724] = 3,
    ACTIONS(976), 1,
      anon_sym_COMMA,
    ACTIONS(978), 1,
      anon_sym_RPAREN,
    STATE(447), 1,
      aux_sym_function_args_repeat1,
  [10734] = 3,
    ACTIONS(1000), 1,
      aux_sym_create_function_token1,
    ACTIONS(1002), 1,
      aux_sym_return_mode_token1,
    STATE(733), 1,
      sym_return_mode,
  [10744] = 3,
    ACTIONS(116), 1,
      anon_sym_COMMA,
    ACTIONS(1296), 1,
      anon_sym_RPAREN,
    STATE(36), 1,
      aux_sym_relation_element_repeat2,
  [10754] = 3,
    ACTIONS(1130), 1,
      sym_object_name,
    ACTIONS(1298), 1,
      aux_sym_truncate_token2,
    STATE(237), 1,
      sym_table_name,
  [10764] = 3,
    ACTIONS(326), 1,
      anon_sym_COMMA,
    ACTIONS(1300), 1,
      anon_sym_RPAREN,
    STATE(464), 1,
      aux_sym_clustering_key_list_repeat1,
  [10774] = 3,
    ACTIONS(1302), 1,
      anon_sym_COMMA,
    ACTIONS(1305), 1,
      aux_sym_from_spec_token1,
    STATE(516), 1,
      aux_sym_select_elements_repeat1,
  [10784] = 3,
    ACTIONS(326), 1,
      anon_sym_COMMA,
    ACTIONS(1307), 1,
      anon_sym_RPAREN,
    STATE(98), 1,
      aux_sym_clustering_key_list_repeat1,
  [10794] = 3,
    ACTIONS(301), 1,
      anon_sym_COMMA,
    ACTIONS(1234), 1,
      anon_sym_RPAREN,
    STATE(414), 1,
      aux_sym_create_function_repeat1,
  [10804] = 3,
    ACTIONS(1173), 1,
      sym_object_name,
    ACTIONS(1309), 1,
      aux_sym_delete_statement_token2,
    STATE(771), 1,
      sym_materialized_view_name,
  [10814] = 3,
    ACTIONS(996), 1,
      anon_sym_COMMA,
    ACTIONS(1311), 1,
      anon_sym_RBRACE,
    STATE(397), 1,
      aux_sym_option_hash_repeat1,
  [10824] = 2,
    ACTIONS(1315), 1,
      anon_sym_DOT,
    ACTIONS(1313), 2,
      aux_sym_using_timestamp_spec_token1,
      aux_sym_create_index_token3,
  [10832] = 3,
    ACTIONS(1000), 1,
      aux_sym_create_function_token1,
    ACTIONS(1002), 1,
      aux_sym_return_mode_token1,
    STATE(890), 1,
      sym_return_mode,
  [10842] = 2,
    ACTIONS(1317), 1,
      sym_object_name,
    STATE(293), 1,
      sym_aggregate_name,
  [10849] = 2,
    ACTIONS(1319), 1,
      sym_object_name,
    STATE(839), 1,
      sym_function_name,
  [10856] = 2,
    ACTIONS(1321), 1,
      sym_object_name,
    STATE(392), 1,
      sym_table_name,
  [10863] = 2,
    ACTIONS(1323), 1,
      aux_sym_from_spec_token1,
    STATE(46), 1,
      sym_from_spec,
  [10870] = 2,
    ACTIONS(1325), 1,
      anon_sym_LBRACE,
    STATE(169), 1,
      sym_replication_list,
  [10877] = 2,
    ACTIONS(1321), 1,
      sym_object_name,
    STATE(76), 1,
      sym_table_name,
  [10884] = 1,
    ACTIONS(1268), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [10889] = 2,
    ACTIONS(1323), 1,
      aux_sym_from_spec_token1,
    STATE(377), 1,
      sym_from_spec,
  [10896] = 2,
    ACTIONS(1327), 1,
      sym_object_name,
    STATE(177), 1,
      sym_alter_type_rename_item,
  [10903] = 1,
    ACTIONS(1214), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [10908] = 2,
    ACTIONS(1321), 1,
      sym_object_name,
    STATE(557), 1,
      sym_table_name,
  [10915] = 1,
    ACTIONS(1294), 2,
      anon_sym_COMMA,
      aux_sym_where_spec_token1,
  [10920] = 2,
    ACTIONS(1321), 1,
      sym_object_name,
    STATE(247), 1,
      sym_table_name,
  [10927] = 1,
    ACTIONS(940), 2,
      anon_sym_COMMA,
      aux_sym_where_spec_token1,
  [10932] = 1,
    ACTIONS(1329), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
  [10937] = 1,
    ACTIONS(1190), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [10942] = 1,
    ACTIONS(1331), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [10947] = 2,
    ACTIONS(1319), 1,
      sym_object_name,
    STATE(955), 1,
      sym_function_name,
  [10954] = 2,
    ACTIONS(1321), 1,
      sym_object_name,
    STATE(250), 1,
      sym_table_name,
  [10961] = 2,
    ACTIONS(1333), 1,
      sym_object_name,
    STATE(529), 1,
      sym_init_cond_hash_item,
  [10968] = 2,
    ACTIONS(155), 1,
      anon_sym_LPAREN,
    STATE(42), 1,
      sym_assignment_tuple,
  [10975] = 2,
    ACTIONS(1321), 1,
      sym_object_name,
    STATE(320), 1,
      sym_table_name,
  [10982] = 2,
    ACTIONS(1335), 1,
      sym_object_name,
    STATE(841), 1,
      sym_keyspace_name,
  [10989] = 2,
    ACTIONS(1337), 1,
      aux_sym_create_keyspace_token1,
    STATE(244), 1,
      sym_user_with,
  [10996] = 2,
    ACTIONS(1339), 1,
      sym_object_name,
    STATE(158), 1,
      sym_role_name,
  [11003] = 2,
    ACTIONS(1341), 1,
      sym_object_name,
    STATE(347), 1,
      sym_type_name,
  [11010] = 2,
    ACTIONS(1343), 1,
      sym_object_name,
    STATE(582), 1,
      sym_user_name,
  [11017] = 2,
    ACTIONS(1345), 1,
      sym_object_name,
    STATE(807), 1,
      sym_column_list,
  [11024] = 2,
    ACTIONS(1347), 1,
      sym_object_name,
    STATE(808), 1,
      sym_materialized_view_name,
  [11031] = 1,
    ACTIONS(1349), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [11036] = 2,
    ACTIONS(1321), 1,
      sym_object_name,
    STATE(390), 1,
      sym_table_name,
  [11043] = 2,
    ACTIONS(1323), 1,
      aux_sym_from_spec_token1,
    STATE(47), 1,
      sym_from_spec,
  [11050] = 2,
    ACTIONS(134), 1,
      aux_sym_where_spec_token1,
    STATE(112), 1,
      sym_where_spec,
  [11057] = 2,
    ACTIONS(1351), 1,
      sym_object_name,
    STATE(598), 1,
      sym_delete_column_item,
  [11064] = 2,
    ACTIONS(1353), 1,
      anon_sym_LPAREN,
    STATE(497), 1,
      sym_insert_column_spec,
  [11071] = 1,
    ACTIONS(1355), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [11076] = 2,
    ACTIONS(1357), 1,
      sym_object_name,
    STATE(568), 1,
      sym_column_not_null,
  [11083] = 1,
    ACTIONS(1359), 2,
      aux_sym_relation_elements_token1,
      aux_sym_primary_key_column_token1,
  [11088] = 1,
    ACTIONS(1201), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [11093] = 2,
    ACTIONS(1321), 1,
      sym_object_name,
    STATE(796), 1,
      sym_table_name,
  [11100] = 2,
    ACTIONS(916), 1,
      anon_sym_LBRACE,
    STATE(190), 1,
      sym_option_hash,
  [11107] = 2,
    ACTIONS(1319), 1,
      sym_object_name,
    STATE(913), 1,
      sym_function_name,
  [11114] = 1,
    ACTIONS(1361), 2,
      anon_sym_COMMA,
      anon_sym_RBRACE,
  [11119] = 2,
    ACTIONS(1321), 1,
      sym_object_name,
    STATE(711), 1,
      sym_table_name,
  [11126] = 2,
    ACTIONS(1319), 1,
      sym_object_name,
    STATE(909), 1,
      sym_function_name,
  [11133] = 1,
    ACTIONS(1251), 2,
      aux_sym_relation_elements_token1,
      aux_sym_primary_key_column_token1,
  [11138] = 2,
    ACTIONS(1363), 1,
      aux_sym_primary_key_column_token1,
    STATE(109), 1,
      sym_primary_key_element,
  [11145] = 2,
    ACTIONS(1365), 1,
      sym_object_name,
    STATE(894), 1,
      sym_clustering_key_list,
  [11152] = 1,
    ACTIONS(1367), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [11157] = 2,
    ACTIONS(1319), 1,
      sym_object_name,
    STATE(891), 1,
      sym_function_name,
  [11164] = 2,
    ACTIONS(1369), 1,
      sym__string_literal,
    STATE(504), 1,
      sym_replication_list_item,
  [11171] = 2,
    ACTIONS(1337), 1,
      aux_sym_create_keyspace_token1,
    STATE(239), 1,
      sym_user_with,
  [11178] = 2,
    ACTIONS(1122), 1,
      sym_object_name,
    STATE(131), 1,
      sym_typed_name,
  [11185] = 2,
    ACTIONS(1371), 1,
      aux_sym_resource_token5,
    ACTIONS(1373), 1,
      aux_sym_drop_aggregate_token1,
  [11192] = 2,
    ACTIONS(1375), 1,
      aux_sym_where_spec_token1,
    STATE(569), 1,
      sym_materialized_view_where,
  [11199] = 2,
    ACTIONS(1377), 1,
      aux_sym_using_timestamp_spec_token2,
    ACTIONS(1379), 1,
      aux_sym_using_ttl_timestamp_token1,
  [11206] = 2,
    ACTIONS(984), 1,
      aux_sym_update_assignments_token1,
    STATE(639), 1,
      sym_update_assignments,
  [11213] = 2,
    ACTIONS(134), 1,
      aux_sym_where_spec_token1,
    STATE(151), 1,
      sym_where_spec,
  [11220] = 2,
    ACTIONS(1347), 1,
      sym_object_name,
    STATE(155), 1,
      sym_materialized_view_name,
  [11227] = 2,
    ACTIONS(1337), 1,
      aux_sym_create_keyspace_token1,
    STATE(276), 1,
      sym_user_with,
  [11234] = 2,
    ACTIONS(1325), 1,
      anon_sym_LBRACE,
    STATE(168), 1,
      sym_replication_list,
  [11241] = 2,
    ACTIONS(1321), 1,
      sym_object_name,
    STATE(577), 1,
      sym_table_name,
  [11248] = 2,
    ACTIONS(1319), 1,
      sym_object_name,
    STATE(860), 1,
      sym_function_name,
  [11255] = 2,
    ACTIONS(1321), 1,
      sym_object_name,
    STATE(657), 1,
      sym_table_name,
  [11262] = 2,
    ACTIONS(1381), 1,
      sym__string_literal,
    STATE(520), 1,
      sym_option_hash_item,
  [11269] = 2,
    ACTIONS(1323), 1,
      aux_sym_from_spec_token1,
    STATE(44), 1,
      sym_from_spec,
  [11276] = 2,
    ACTIONS(1383), 1,
      aux_sym_durable_writes_token1,
    STATE(215), 1,
      sym_durable_writes,
  [11283] = 1,
    ACTIONS(1305), 2,
      anon_sym_COMMA,
      aux_sym_from_spec_token1,
  [11288] = 1,
    ACTIONS(1385), 2,
      anon_sym_COMMA,
      aux_sym_from_spec_token1,
  [11293] = 2,
    ACTIONS(1365), 1,
      sym_object_name,
    STATE(851), 1,
      sym_clustering_key_list,
  [11300] = 2,
    ACTIONS(822), 1,
      aux_sym__decimal_literal_token1,
    STATE(170), 1,
      sym__decimal_literal,
  [11307] = 1,
    ACTIONS(1387), 2,
      anon_sym_COMMA,
      aux_sym_from_spec_token1,
  [11312] = 2,
    ACTIONS(134), 1,
      aux_sym_where_spec_token1,
    STATE(139), 1,
      sym_where_spec,
  [11319] = 2,
    ACTIONS(1319), 1,
      sym_object_name,
    STATE(692), 1,
      sym_function_name,
  [11326] = 2,
    ACTIONS(1321), 1,
      sym_object_name,
    STATE(899), 1,
      sym_table_name,
  [11333] = 1,
    ACTIONS(1277), 2,
      anon_sym_COMMA,
      aux_sym_from_spec_token1,
  [11338] = 2,
    ACTIONS(1345), 1,
      sym_object_name,
    STATE(702), 1,
      sym_column_list,
  [11345] = 2,
    ACTIONS(1389), 1,
      sym__string_literal,
    STATE(206), 1,
      sym_trigger_class,
  [11352] = 2,
    ACTIONS(1122), 1,
      sym_object_name,
    STATE(486), 1,
      sym_typed_name,
  [11359] = 2,
    ACTIONS(1363), 1,
      aux_sym_primary_key_column_token1,
    STATE(150), 1,
      sym_primary_key_element,
  [11366] = 2,
    ACTIONS(1357), 1,
      sym_object_name,
    STATE(391), 1,
      sym_column_not_null,
  [11373] = 2,
    ACTIONS(1319), 1,
      sym_object_name,
    STATE(695), 1,
      sym_function_name,
  [11380] = 1,
    ACTIONS(1391), 2,
      aux_sym_select_statement_token3,
      aux_sym_insert_values_spec_token1,
  [11385] = 2,
    ACTIONS(1317), 1,
      sym_object_name,
    STATE(696), 1,
      sym_aggregate_name,
  [11392] = 2,
    ACTIONS(1319), 1,
      sym_object_name,
    STATE(830), 1,
      sym_function_name,
  [11399] = 2,
    ACTIONS(1321), 1,
      sym_object_name,
    STATE(699), 1,
      sym_table_name,
  [11406] = 1,
    ACTIONS(1261), 2,
      anon_sym_COMMA,
      anon_sym_RBRACE,
  [11411] = 1,
    ACTIONS(1393), 2,
      anon_sym_COMMA,
      anon_sym_RBRACE,
  [11416] = 1,
    ACTIONS(1256), 2,
      anon_sym_COMMA,
      anon_sym_RBRACE,
  [11421] = 1,
    ACTIONS(1395), 2,
      anon_sym_COMMA,
      anon_sym_RBRACE,
  [11426] = 1,
    ACTIONS(1074), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [11431] = 2,
    ACTIONS(1397), 1,
      anon_sym_COMMA,
    ACTIONS(1399), 1,
      anon_sym_RPAREN,
  [11438] = 2,
    ACTIONS(134), 1,
      aux_sym_where_spec_token1,
    STATE(136), 1,
      sym_where_spec,
  [11445] = 2,
    ACTIONS(1401), 1,
      sym_object_name,
    STATE(818), 1,
      sym_partition_key_list,
  [11452] = 2,
    ACTIONS(1389), 1,
      sym__string_literal,
    STATE(218), 1,
      sym_trigger_class,
  [11459] = 2,
    ACTIONS(134), 1,
      aux_sym_where_spec_token1,
    STATE(133), 1,
      sym_where_spec,
  [11466] = 2,
    ACTIONS(1122), 1,
      sym_object_name,
    STATE(483), 1,
      sym_typed_name,
  [11473] = 2,
    ACTIONS(1403), 1,
      aux_sym_role_with_option_token1,
    STATE(97), 1,
      sym_user_password,
  [11480] = 2,
    ACTIONS(1321), 1,
      sym_object_name,
    STATE(263), 1,
      sym_table_name,
  [11487] = 2,
    ACTIONS(1405), 1,
      sym_object_name,
    STATE(280), 1,
      sym_index_name,
  [11494] = 2,
    ACTIONS(1335), 1,
      sym_object_name,
    STATE(297), 1,
      sym_keyspace_name,
  [11501] = 2,
    ACTIONS(1319), 1,
      sym_object_name,
    STATE(295), 1,
      sym_function_name,
  [11508] = 2,
    ACTIONS(1319), 1,
      sym_object_name,
    STATE(806), 1,
      sym_function_name,
  [11515] = 2,
    ACTIONS(1339), 1,
      sym_object_name,
    STATE(294), 1,
      sym_role_name,
  [11522] = 2,
    ACTIONS(1407), 1,
      sym_object_name,
    STATE(747), 1,
      sym_trigger_name,
  [11529] = 2,
    ACTIONS(1321), 1,
      sym_object_name,
    STATE(292), 1,
      sym_table_name,
  [11536] = 2,
    ACTIONS(1375), 1,
      aux_sym_where_spec_token1,
    STATE(602), 1,
      sym_materialized_view_where,
  [11543] = 2,
    ACTIONS(1345), 1,
      sym_object_name,
    STATE(800), 1,
      sym_column_list,
  [11550] = 2,
    ACTIONS(1341), 1,
      sym_object_name,
    STATE(290), 1,
      sym_type_name,
  [11557] = 2,
    ACTIONS(1343), 1,
      sym_object_name,
    STATE(288), 1,
      sym_user_name,
  [11564] = 1,
    ACTIONS(1100), 2,
      anon_sym_COMMA,
      anon_sym_GT,
  [11569] = 2,
    ACTIONS(822), 1,
      aux_sym__decimal_literal_token1,
    STATE(946), 1,
      sym__decimal_literal,
  [11576] = 2,
    ACTIONS(1409), 1,
      anon_sym_EQ,
    ACTIONS(1411), 1,
      anon_sym_LBRACK,
  [11583] = 2,
    ACTIONS(1381), 1,
      sym__string_literal,
    STATE(609), 1,
      sym_option_hash_item,
  [11590] = 2,
    ACTIONS(1347), 1,
      sym_object_name,
    STATE(221), 1,
      sym_materialized_view_name,
  [11597] = 1,
    ACTIONS(1413), 2,
      sym__string_literal,
      sym__float_literal,
  [11602] = 2,
    ACTIONS(134), 1,
      aux_sym_where_spec_token1,
    STATE(140), 1,
      sym_where_spec,
  [11609] = 2,
    ACTIONS(1369), 1,
      sym__string_literal,
    STATE(611), 1,
      sym_replication_list_item,
  [11616] = 2,
    ACTIONS(1325), 1,
      anon_sym_LBRACE,
    STATE(187), 1,
      sym_replication_list,
  [11623] = 2,
    ACTIONS(1323), 1,
      aux_sym_from_spec_token1,
    STATE(383), 1,
      sym_from_spec,
  [11630] = 2,
    ACTIONS(155), 1,
      anon_sym_LPAREN,
    STATE(405), 1,
      sym_assignment_tuple,
  [11637] = 2,
    ACTIONS(155), 1,
      anon_sym_LPAREN,
    STATE(37), 1,
      sym_assignment_tuple,
  [11644] = 2,
    ACTIONS(1415), 1,
      aux_sym_compact_storage_token1,
    ACTIONS(1417), 1,
      sym_object_name,
  [11651] = 2,
    ACTIONS(1122), 1,
      sym_object_name,
    STATE(106), 1,
      sym_typed_name,
  [11658] = 1,
    ACTIONS(1028), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [11663] = 2,
    ACTIONS(1343), 1,
      sym_object_name,
    STATE(546), 1,
      sym_user_name,
  [11670] = 2,
    ACTIONS(1341), 1,
      sym_object_name,
    STATE(932), 1,
      sym_type_name,
  [11677] = 1,
    ACTIONS(1419), 2,
      aux_sym_using_timestamp_spec_token1,
      aux_sym_create_index_token3,
  [11682] = 2,
    ACTIONS(1407), 1,
      sym_object_name,
    STATE(929), 1,
      sym_trigger_name,
  [11689] = 2,
    ACTIONS(155), 1,
      anon_sym_LPAREN,
    STATE(472), 1,
      sym_assignment_tuple,
  [11696] = 1,
    ACTIONS(1421), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [11701] = 2,
    ACTIONS(1122), 1,
      sym_object_name,
    STATE(120), 1,
      sym_typed_name,
  [11708] = 2,
    ACTIONS(1327), 1,
      sym_object_name,
    STATE(115), 1,
      sym_alter_type_rename_item,
  [11715] = 2,
    ACTIONS(1205), 1,
      sym_object_name,
    STATE(561), 1,
      sym_column_definition,
  [11722] = 2,
    ACTIONS(1353), 1,
      anon_sym_LPAREN,
    STATE(415), 1,
      sym_insert_column_spec,
  [11729] = 2,
    ACTIONS(155), 1,
      anon_sym_LPAREN,
    STATE(38), 1,
      sym_assignment_tuple,
  [11736] = 2,
    ACTIONS(984), 1,
      aux_sym_update_assignments_token1,
    STATE(615), 1,
      sym_update_assignments,
  [11743] = 2,
    ACTIONS(1321), 1,
      sym_object_name,
    STATE(804), 1,
      sym_table_name,
  [11750] = 1,
    ACTIONS(1423), 2,
      anon_sym_COMMA,
      aux_sym_where_spec_token1,
  [11755] = 1,
    ACTIONS(1425), 2,
      anon_sym_COMMA,
      aux_sym_from_spec_token1,
  [11760] = 2,
    ACTIONS(1335), 1,
      sym_object_name,
    STATE(714), 1,
      sym_keyspace_name,
  [11767] = 2,
    ACTIONS(1321), 1,
      sym_object_name,
    STATE(629), 1,
      sym_table_name,
  [11774] = 2,
    ACTIONS(1383), 1,
      aux_sym_durable_writes_token1,
    STATE(236), 1,
      sym_durable_writes,
  [11781] = 2,
    ACTIONS(1383), 1,
      aux_sym_durable_writes_token1,
    STATE(255), 1,
      sym_durable_writes,
  [11788] = 2,
    ACTIONS(1339), 1,
      sym_object_name,
    STATE(152), 1,
      sym_role_name,
  [11795] = 1,
    ACTIONS(1427), 2,
      anon_sym_COMMA,
      aux_sym_where_spec_token1,
  [11800] = 2,
    ACTIONS(1317), 1,
      sym_object_name,
    STATE(914), 1,
      sym_aggregate_name,
  [11807] = 1,
    ACTIONS(1429), 1,
      sym_object_name,
  [11811] = 1,
    ACTIONS(1431), 1,
      aux_sym_create_index_token3,
  [11815] = 1,
    ACTIONS(1433), 1,
      anon_sym_RPAREN,
  [11819] = 1,
    ACTIONS(1435), 1,
      sym_object_name,
  [11823] = 1,
    ACTIONS(1437), 1,
      anon_sym_EQ,
  [11827] = 1,
    ACTIONS(1439), 1,
      anon_sym_COLON,
  [11831] = 1,
    ACTIONS(1441), 1,
      aux_sym_delete_statement_token3,
  [11835] = 1,
    ACTIONS(1443), 1,
      anon_sym_DOT,
  [11839] = 1,
    ACTIONS(1445), 1,
      anon_sym_RPAREN,
  [11843] = 1,
    ACTIONS(1447), 1,
      aux_sym_constant_token2,
  [11847] = 1,
    ACTIONS(1449), 1,
      aux_sym_return_mode_token2,
  [11851] = 1,
    ACTIONS(1451), 1,
      aux_sym_create_function_token2,
  [11855] = 1,
    ACTIONS(1453), 1,
      anon_sym_LT,
  [11859] = 1,
    ACTIONS(1455), 1,
      aux_sym_create_function_token1,
  [11863] = 1,
    ACTIONS(1457), 1,
      anon_sym_COLON,
  [11867] = 1,
    ACTIONS(1459), 1,
      anon_sym_LT,
  [11871] = 1,
    ACTIONS(1461), 1,
      anon_sym_RPAREN,
  [11875] = 1,
    ACTIONS(1463), 1,
      anon_sym_LT,
  [11879] = 1,
    ACTIONS(1465), 1,
      anon_sym_LT,
  [11883] = 1,
    ACTIONS(1467), 1,
      anon_sym_EQ,
  [11887] = 1,
    ACTIONS(1469), 1,
      anon_sym_EQ,
  [11891] = 1,
    ACTIONS(1471), 1,
      anon_sym_EQ,
  [11895] = 1,
    ACTIONS(1473), 1,
      aux_sym_create_aggregate_token4,
  [11899] = 1,
    ACTIONS(1475), 1,
      aux_sym_select_statement_token1,
  [11903] = 1,
    ACTIONS(1477), 1,
      anon_sym_EQ,
  [11907] = 1,
    ACTIONS(1479), 1,
      anon_sym_LPAREN,
  [11911] = 1,
    ACTIONS(1481), 1,
      anon_sym_LPAREN,
  [11915] = 1,
    ACTIONS(1483), 1,
      aux_sym_create_aggregate_token3,
  [11919] = 1,
    ACTIONS(1485), 1,
      anon_sym_EQ,
  [11923] = 1,
    ACTIONS(1487), 1,
      anon_sym_LPAREN,
  [11927] = 1,
    ACTIONS(1489), 1,
      anon_sym_RPAREN,
  [11931] = 1,
    ACTIONS(1491), 1,
      anon_sym_LPAREN,
  [11935] = 1,
    ACTIONS(1493), 1,
      anon_sym_RPAREN,
  [11939] = 1,
    ACTIONS(1495), 1,
      anon_sym_LPAREN,
  [11943] = 1,
    ACTIONS(1497), 1,
      sym_object_name,
  [11947] = 1,
    ACTIONS(1499), 1,
      aux_sym_from_spec_token1,
  [11951] = 1,
    ACTIONS(1501), 1,
      aux_sym_delete_statement_token3,
  [11955] = 1,
    ACTIONS(1503), 1,
      aux_sym_select_statement_token5,
  [11959] = 1,
    ACTIONS(1505), 1,
      anon_sym_LPAREN,
  [11963] = 1,
    ACTIONS(1507), 1,
      aux_sym_select_statement_token5,
  [11967] = 1,
    ACTIONS(1509), 1,
      anon_sym_RPAREN,
  [11971] = 1,
    ACTIONS(1511), 1,
      anon_sym_LPAREN,
  [11975] = 1,
    ACTIONS(1513), 1,
      aux_sym_select_statement_token1,
  [11979] = 1,
    ACTIONS(1515), 1,
      anon_sym_RPAREN,
  [11983] = 1,
    ACTIONS(1517), 1,
      aux_sym_create_keyspace_token1,
  [11987] = 1,
    ACTIONS(1519), 1,
      sym_object_name,
  [11991] = 1,
    ACTIONS(1521), 1,
      anon_sym_RPAREN,
  [11995] = 1,
    ACTIONS(1523), 1,
      aux_sym_create_keyspace_token2,
  [11999] = 1,
    ACTIONS(1525), 1,
      sym_object_name,
  [12003] = 1,
    ACTIONS(1527), 1,
      anon_sym_RPAREN,
  [12007] = 1,
    ACTIONS(1529), 1,
      sym__string_literal,
  [12011] = 1,
    ACTIONS(1531), 1,
      anon_sym_RPAREN,
  [12015] = 1,
    ACTIONS(1533), 1,
      anon_sym_LPAREN,
  [12019] = 1,
    ACTIONS(1535), 1,
      anon_sym_RPAREN,
  [12023] = 1,
    ACTIONS(1537), 1,
      anon_sym_RPAREN,
  [12027] = 1,
    ACTIONS(1539), 1,
      anon_sym_RPAREN,
  [12031] = 1,
    ACTIONS(1541), 1,
      aux_sym_insert_statement_token3,
  [12035] = 1,
    ACTIONS(1543), 1,
      aux_sym_grant_token2,
  [12039] = 1,
    ACTIONS(1545), 1,
      anon_sym_LPAREN,
  [12043] = 1,
    ACTIONS(1547), 1,
      sym_object_name,
  [12047] = 1,
    ACTIONS(1549), 1,
      sym_object_name,
  [12051] = 1,
    ACTIONS(1551), 1,
      anon_sym_EQ,
  [12055] = 1,
    ACTIONS(1553), 1,
      sym_object_name,
  [12059] = 1,
    ACTIONS(1555), 1,
      aux_sym_create_function_token1,
  [12063] = 1,
    ACTIONS(1557), 1,
      sym_object_name,
  [12067] = 1,
    ACTIONS(1559), 1,
      aux_sym_select_statement_token5,
  [12071] = 1,
    ACTIONS(1561), 1,
      aux_sym_return_mode_token2,
  [12075] = 1,
    ACTIONS(1563), 1,
      aux_sym_create_function_token1,
  [12079] = 1,
    ACTIONS(1565), 1,
      sym_object_name,
  [12083] = 1,
    ACTIONS(1567), 1,
      aux_sym_create_function_token2,
  [12087] = 1,
    ACTIONS(1569), 1,
      anon_sym_EQ,
  [12091] = 1,
    ACTIONS(1571), 1,
      aux_sym_insert_statement_token3,
  [12095] = 1,
    ACTIONS(1573), 1,
      anon_sym_LPAREN,
  [12099] = 1,
    ACTIONS(1575), 1,
      aux_sym_insert_statement_token3,
  [12103] = 1,
    ACTIONS(1577), 1,
      aux_sym__decimal_literal_token1,
  [12107] = 1,
    ACTIONS(1579), 1,
      aux_sym_create_aggregate_token3,
  [12111] = 1,
    ACTIONS(1581), 1,
      anon_sym_GT,
  [12115] = 1,
    ACTIONS(1583), 1,
      aux_sym_create_index_token3,
  [12119] = 1,
    ACTIONS(1585), 1,
      aux_sym__decimal_literal_token1,
  [12123] = 1,
    ACTIONS(1587), 1,
      sym_object_name,
  [12127] = 1,
    ACTIONS(1589), 1,
      sym_object_name,
  [12131] = 1,
    ACTIONS(1591), 1,
      sym_object_name,
  [12135] = 1,
    ACTIONS(1593), 1,
      aux_sym_compact_storage_token2,
  [12139] = 1,
    ACTIONS(1595), 1,
      aux_sym_compact_storage_token2,
  [12143] = 1,
    ACTIONS(1597), 1,
      aux_sym_order_spec_token1,
  [12147] = 1,
    ACTIONS(1599), 1,
      aux_sym_delete_statement_token3,
  [12151] = 1,
    ACTIONS(1601), 1,
      anon_sym_EQ,
  [12155] = 1,
    ACTIONS(1603), 1,
      anon_sym_EQ,
  [12159] = 1,
    ACTIONS(1605), 1,
      aux_sym_grant_token2,
  [12163] = 1,
    ACTIONS(1607), 1,
      anon_sym_LPAREN,
  [12167] = 1,
    ACTIONS(1609), 1,
      sym_object_name,
  [12171] = 1,
    ACTIONS(1611), 1,
      anon_sym_EQ,
  [12175] = 1,
    ACTIONS(1613), 1,
      aux_sym_drop_type_token1,
  [12179] = 1,
    ACTIONS(1615), 1,
      aux_sym_grant_token2,
  [12183] = 1,
    ACTIONS(1617), 1,
      aux_sym_delete_statement_token3,
  [12187] = 1,
    ACTIONS(1619), 1,
      sym_object_name,
  [12191] = 1,
    ACTIONS(1621), 1,
      sym_object_name,
  [12195] = 1,
    ACTIONS(1623), 1,
      aux_sym_delete_statement_token3,
  [12199] = 1,
    ACTIONS(1625), 1,
      sym_object_name,
  [12203] = 1,
    ACTIONS(1627), 1,
      sym_object_name,
  [12207] = 1,
    ACTIONS(1629), 1,
      aux_sym_delete_statement_token3,
  [12211] = 1,
    ACTIONS(1631), 1,
      aux_sym_select_element_token1,
  [12215] = 1,
    ACTIONS(1633), 1,
      aux_sym_insert_statement_token3,
  [12219] = 1,
    ACTIONS(1635), 1,
      sym_object_name,
  [12223] = 1,
    ACTIONS(1637), 1,
      anon_sym_EQ,
  [12227] = 1,
    ACTIONS(1639), 1,
      sym_object_name,
  [12231] = 1,
    ACTIONS(1641), 1,
      anon_sym_RPAREN,
  [12235] = 1,
    ACTIONS(1643), 1,
      anon_sym_RPAREN,
  [12239] = 1,
    ACTIONS(1645), 1,
      aux_sym_delete_statement_token3,
  [12243] = 1,
    ACTIONS(1647), 1,
      anon_sym_RPAREN,
  [12247] = 1,
    ACTIONS(1649), 1,
      aux_sym_delete_statement_token3,
  [12251] = 1,
    ACTIONS(1651), 1,
      aux_sym_select_statement_token5,
  [12255] = 1,
    ACTIONS(1653), 1,
      sym_object_name,
  [12259] = 1,
    ACTIONS(1655), 1,
      sym_object_name,
  [12263] = 1,
    ACTIONS(1657), 1,
      aux_sym_delete_statement_token3,
  [12267] = 1,
    ACTIONS(1659), 1,
      sym__boolean_literal,
  [12271] = 1,
    ACTIONS(1661), 1,
      aux_sym_create_keyspace_token2,
  [12275] = 1,
    ACTIONS(1663), 1,
      aux_sym_create_function_token1,
  [12279] = 1,
    ACTIONS(1665), 1,
      aux_sym_delete_statement_token3,
  [12283] = 1,
    ACTIONS(1667), 1,
      aux_sym_create_function_token1,
  [12287] = 1,
    ACTIONS(1669), 1,
      aux_sym_select_element_token1,
  [12291] = 1,
    ACTIONS(1671), 1,
      sym_object_name,
  [12295] = 1,
    ACTIONS(1673), 1,
      aux_sym_create_function_token2,
  [12299] = 1,
    ACTIONS(1675), 1,
      sym_object_name,
  [12303] = 1,
    ACTIONS(1677), 1,
      aux_sym__decimal_literal_token1,
  [12307] = 1,
    ACTIONS(1679), 1,
      aux_sym__decimal_literal_token1,
  [12311] = 1,
    ACTIONS(1681), 1,
      anon_sym_LPAREN,
  [12315] = 1,
    ACTIONS(758), 1,
      anon_sym_LPAREN,
  [12319] = 1,
    ACTIONS(1683), 1,
      aux_sym_delete_statement_token3,
  [12323] = 1,
    ACTIONS(1685), 1,
      aux_sym_create_aggregate_token5,
  [12327] = 1,
    ACTIONS(1687), 1,
      aux_sym_from_spec_token1,
  [12331] = 1,
    ACTIONS(1689), 1,
      anon_sym_RPAREN,
  [12335] = 1,
    ACTIONS(1691), 1,
      aux_sym_insert_statement_token3,
  [12339] = 1,
    ACTIONS(1693), 1,
      aux_sym_delete_statement_token3,
  [12343] = 1,
    ACTIONS(1695), 1,
      anon_sym_LPAREN,
  [12347] = 1,
    ACTIONS(1697), 1,
      anon_sym_RPAREN,
  [12351] = 1,
    ACTIONS(1699), 1,
      aux_sym_create_aggregate_token4,
  [12355] = 1,
    ACTIONS(1701), 1,
      aux_sym_from_spec_token1,
  [12359] = 1,
    ACTIONS(1703), 1,
      aux_sym_select_element_token1,
  [12363] = 1,
    ACTIONS(1705), 1,
      aux_sym__decimal_literal_token1,
  [12367] = 1,
    ACTIONS(1707), 1,
      sym_object_name,
  [12371] = 1,
    ACTIONS(1709), 1,
      sym_object_name,
  [12375] = 1,
    ACTIONS(1711), 1,
      anon_sym_RBRACK,
  [12379] = 1,
    ACTIONS(1713), 1,
      anon_sym_GT,
  [12383] = 1,
    ACTIONS(1715), 1,
      aux_sym_order_spec_token2,
  [12387] = 1,
    ACTIONS(1717), 1,
      anon_sym_RPAREN,
  [12391] = 1,
    ACTIONS(1719), 1,
      aux_sym_select_statement_token5,
  [12395] = 1,
    ACTIONS(1721), 1,
      anon_sym_RPAREN,
  [12399] = 1,
    ACTIONS(1723), 1,
      anon_sym_RPAREN,
  [12403] = 1,
    ACTIONS(1725), 1,
      anon_sym_COMMA,
  [12407] = 1,
    ACTIONS(1727), 1,
      anon_sym_GT,
  [12411] = 1,
    ACTIONS(1729), 1,
      anon_sym_LPAREN,
  [12415] = 1,
    ACTIONS(1731), 1,
      anon_sym_LPAREN,
  [12419] = 1,
    ACTIONS(1733), 1,
      anon_sym_LPAREN,
  [12423] = 1,
    ACTIONS(1735), 1,
      aux_sym_create_function_token2,
  [12427] = 1,
    ACTIONS(1737), 1,
      anon_sym_RPAREN,
  [12431] = 1,
    ACTIONS(1739), 1,
      aux_sym_create_function_token1,
  [12435] = 1,
    ACTIONS(1741), 1,
      sym__code_block,
  [12439] = 1,
    ACTIONS(1743), 1,
      aux_sym_select_element_token1,
  [12443] = 1,
    ACTIONS(1745), 1,
      sym_object_name,
  [12447] = 1,
    ACTIONS(1747), 1,
      aux_sym_create_aggregate_token4,
  [12451] = 1,
    ACTIONS(1749), 1,
      anon_sym_RPAREN,
  [12455] = 1,
    ACTIONS(1751), 1,
      anon_sym_RPAREN,
  [12459] = 1,
    ACTIONS(768), 1,
      aux_sym_column_not_null_token1,
  [12463] = 1,
    ACTIONS(1753), 1,
      aux_sym_delete_statement_token3,
  [12467] = 1,
    ACTIONS(1755), 1,
      sym_object_name,
  [12471] = 1,
    ACTIONS(1757), 1,
      sym_object_name,
  [12475] = 1,
    ACTIONS(1759), 1,
      aux_sym_order_spec_token2,
  [12479] = 1,
    ACTIONS(1761), 1,
      aux_sym_create_aggregate_token3,
  [12483] = 1,
    ACTIONS(1763), 1,
      anon_sym_LPAREN,
  [12487] = 1,
    ACTIONS(1765), 1,
      anon_sym_COLON,
  [12491] = 1,
    ACTIONS(1767), 1,
      aux_sym_create_keyspace_token1,
  [12495] = 1,
    ACTIONS(1769), 1,
      aux_sym_constant_token2,
  [12499] = 1,
    ACTIONS(1771), 1,
      aux_sym_create_function_token1,
  [12503] = 1,
    ACTIONS(1773), 1,
      aux_sym_create_index_token3,
  [12507] = 1,
    ACTIONS(1775), 1,
      aux_sym_delete_statement_token3,
  [12511] = 1,
    ACTIONS(1777), 1,
      aux_sym_delete_statement_token3,
  [12515] = 1,
    ACTIONS(1779), 1,
      aux_sym_create_index_token3,
  [12519] = 1,
    ACTIONS(1781), 1,
      aux_sym_delete_statement_token3,
  [12523] = 1,
    ACTIONS(1783), 1,
      anon_sym_COMMA,
  [12527] = 1,
    ACTIONS(1785), 1,
      aux_sym_delete_statement_token3,
  [12531] = 1,
    ACTIONS(1787), 1,
      anon_sym_RPAREN,
  [12535] = 1,
    ACTIONS(1789), 1,
      aux_sym_delete_statement_token3,
  [12539] = 1,
    ACTIONS(1791), 1,
      sym_object_name,
  [12543] = 1,
    ACTIONS(1793), 1,
      aux_sym_create_function_token2,
  [12547] = 1,
    ACTIONS(1795), 1,
      aux_sym_delete_statement_token3,
  [12551] = 1,
    ACTIONS(1797), 1,
      aux_sym_insert_statement_token2,
  [12555] = 1,
    ACTIONS(1799), 1,
      sym__code_block,
  [12559] = 1,
    ACTIONS(1801), 1,
      aux_sym_select_element_token1,
  [12563] = 1,
    ACTIONS(1803), 1,
      aux_sym_delete_statement_token3,
  [12567] = 1,
    ACTIONS(1805), 1,
      aux_sym_create_aggregate_token6,
  [12571] = 1,
    ACTIONS(1807), 1,
      sym_object_name,
  [12575] = 1,
    ACTIONS(1809), 1,
      aux_sym_insert_statement_token3,
  [12579] = 1,
    ACTIONS(1811), 1,
      aux_sym_delete_statement_token3,
  [12583] = 1,
    ACTIONS(1813), 1,
      aux_sym_constant_token2,
  [12587] = 1,
    ACTIONS(1815), 1,
      aux_sym_create_index_token3,
  [12591] = 1,
    ACTIONS(1817), 1,
      aux_sym_insert_statement_token3,
  [12595] = 1,
    ACTIONS(1819), 1,
      aux_sym_create_function_token1,
  [12599] = 1,
    ACTIONS(1821), 1,
      anon_sym_LPAREN,
  [12603] = 1,
    ACTIONS(1823), 1,
      sym__string_literal,
  [12607] = 1,
    ACTIONS(1825), 1,
      aux_sym_create_aggregate_token5,
  [12611] = 1,
    ACTIONS(1827), 1,
      aux_sym_insert_statement_token3,
  [12615] = 1,
    ACTIONS(1829), 1,
      aux_sym_create_keyspace_token2,
  [12619] = 1,
    ACTIONS(1831), 1,
      aux_sym_using_timestamp_spec_token1,
  [12623] = 1,
    ACTIONS(1833), 1,
      anon_sym_RPAREN,
  [12627] = 1,
    ACTIONS(1835), 1,
      aux_sym_insert_statement_token3,
  [12631] = 1,
    ACTIONS(1837), 1,
      aux_sym_select_element_token1,
  [12635] = 1,
    ACTIONS(1839), 1,
      sym_object_name,
  [12639] = 1,
    ACTIONS(1841), 1,
      aux_sym_create_function_token2,
  [12643] = 1,
    ACTIONS(1843), 1,
      anon_sym_LPAREN,
  [12647] = 1,
    ACTIONS(1845), 1,
      sym__code_block,
  [12651] = 1,
    ACTIONS(1847), 1,
      aux_sym_create_aggregate_token5,
  [12655] = 1,
    ACTIONS(1849), 1,
      aux_sym_insert_statement_token3,
  [12659] = 1,
    ACTIONS(1851), 1,
      sym__boolean_literal,
  [12663] = 1,
    ACTIONS(1853), 1,
      aux_sym_constant_token2,
  [12667] = 1,
    ACTIONS(1855), 1,
      aux_sym_insert_statement_token3,
  [12671] = 1,
    ACTIONS(1857), 1,
      sym_object_name,
  [12675] = 1,
    ACTIONS(1859), 1,
      anon_sym_LPAREN,
  [12679] = 1,
    ACTIONS(1861), 1,
      aux_sym_insert_statement_token3,
  [12683] = 1,
    ACTIONS(1863), 1,
      aux_sym_create_keyspace_token1,
  [12687] = 1,
    ACTIONS(1865), 1,
      aux_sym_create_function_token1,
  [12691] = 1,
    ACTIONS(1867), 1,
      aux_sym_create_aggregate_token4,
  [12695] = 1,
    ACTIONS(1869), 1,
      sym_object_name,
  [12699] = 1,
    ACTIONS(1871), 1,
      sym_object_name,
  [12703] = 1,
    ACTIONS(1873), 1,
      anon_sym_RPAREN,
  [12707] = 1,
    ACTIONS(1875), 1,
      sym__code_block,
  [12711] = 1,
    ACTIONS(1877), 1,
      aux_sym_select_element_token1,
  [12715] = 1,
    ACTIONS(1879), 1,
      sym_object_name,
  [12719] = 1,
    ACTIONS(1881), 1,
      aux_sym_insert_statement_token3,
  [12723] = 1,
    ACTIONS(1883), 1,
      anon_sym_LPAREN,
  [12727] = 1,
    ACTIONS(1885), 1,
      aux_sym_create_index_token3,
  [12731] = 1,
    ACTIONS(1887), 1,
      sym__boolean_literal,
  [12735] = 1,
    ACTIONS(1889), 1,
      aux_sym_insert_statement_token3,
  [12739] = 1,
    ACTIONS(1891), 1,
      aux_sym_create_index_token3,
  [12743] = 1,
    ACTIONS(1893), 1,
      anon_sym_RPAREN,
  [12747] = 1,
    ACTIONS(1895), 1,
      aux_sym_relation_contains_key_token2,
  [12751] = 1,
    ACTIONS(1897), 1,
      aux_sym_create_function_token2,
  [12755] = 1,
    ACTIONS(1899), 1,
      anon_sym_LPAREN,
  [12759] = 1,
    ACTIONS(1901), 1,
      aux_sym_insert_statement_token3,
  [12763] = 1,
    ACTIONS(1903), 1,
      aux_sym_create_aggregate_token6,
  [12767] = 1,
    ACTIONS(1905), 1,
      sym_object_name,
  [12771] = 1,
    ACTIONS(1907), 1,
      sym__code_block,
  [12775] = 1,
    ACTIONS(1909), 1,
      aux_sym_select_element_token1,
  [12779] = 1,
    ACTIONS(1911), 1,
      aux_sym_create_aggregate_token6,
  [12783] = 1,
    ACTIONS(1913), 1,
      anon_sym_LPAREN,
  [12787] = 1,
    ACTIONS(1915), 1,
      anon_sym_COLON,
  [12791] = 1,
    ACTIONS(1917), 1,
      aux_sym_relation_contains_key_token2,
  [12795] = 1,
    ACTIONS(1919), 1,
      aux_sym_create_aggregate_token3,
  [12799] = 1,
    ACTIONS(1921), 1,
      aux_sym_using_timestamp_spec_token2,
  [12803] = 1,
    ACTIONS(1923), 1,
      sym_object_name,
  [12807] = 1,
    ACTIONS(1925), 1,
      sym_object_name,
  [12811] = 1,
    ACTIONS(1927), 1,
      aux_sym_create_function_token2,
  [12815] = 1,
    ACTIONS(1929), 1,
      aux_sym_create_aggregate_token5,
  [12819] = 1,
    ACTIONS(1931), 1,
      sym_object_name,
  [12823] = 1,
    ACTIONS(1933), 1,
      aux_sym_delete_statement_token3,
  [12827] = 1,
    ACTIONS(1935), 1,
      sym__code_block,
  [12831] = 1,
    ACTIONS(1937), 1,
      sym_object_name,
  [12835] = 1,
    ACTIONS(1939), 1,
      aux_sym_insert_statement_token2,
  [12839] = 1,
    ACTIONS(1941), 1,
      anon_sym_RPAREN,
  [12843] = 1,
    ACTIONS(1943), 1,
      aux_sym_using_timestamp_spec_token1,
  [12847] = 1,
    ACTIONS(1945), 1,
      aux_sym_drop_materialized_view_token2,
  [12851] = 1,
    ACTIONS(1947), 1,
      anon_sym_RPAREN,
  [12855] = 1,
    ACTIONS(1949), 1,
      anon_sym_LPAREN,
  [12859] = 1,
    ACTIONS(1951), 1,
      aux_sym_delete_statement_token3,
  [12863] = 1,
    ACTIONS(1953), 1,
      anon_sym_LPAREN,
  [12867] = 1,
    ACTIONS(1955), 1,
      aux_sym_create_index_token3,
  [12871] = 1,
    ACTIONS(1957), 1,
      aux_sym_create_index_token3,
  [12875] = 1,
    ACTIONS(1959), 1,
      aux_sym_select_element_token1,
  [12879] = 1,
    ACTIONS(1961), 1,
      sym_object_name,
  [12883] = 1,
    ACTIONS(1963), 1,
      aux_sym_delete_statement_token3,
  [12887] = 1,
    ACTIONS(1965), 1,
      aux_sym_drop_materialized_view_token2,
  [12891] = 1,
    ACTIONS(1967), 1,
      aux_sym_create_aggregate_token2,
  [12895] = 1,
    ACTIONS(1969), 1,
      aux_sym_drop_materialized_view_token2,
  [12899] = 1,
    ACTIONS(1971), 1,
      aux_sym_using_ttl_timestamp_token1,
  [12903] = 1,
    ACTIONS(1973), 1,
      aux_sym_using_timestamp_spec_token2,
  [12907] = 1,
    ACTIONS(1975), 1,
      aux_sym_select_statement_token5,
  [12911] = 1,
    ACTIONS(1977), 1,
      anon_sym_RBRACK,
  [12915] = 1,
    ACTIONS(1979), 1,
      sym_object_name,
  [12919] = 1,
    ACTIONS(1981), 1,
      aux_sym_begin_batch_token5,
  [12923] = 1,
    ACTIONS(1983), 1,
      aux_sym_resource_token2,
  [12927] = 1,
    ACTIONS(1985), 1,
      sym_object_name,
  [12931] = 1,
    ACTIONS(1987), 1,
      sym_object_name,
  [12935] = 1,
    ACTIONS(1989), 1,
      aux_sym_create_function_token1,
  [12939] = 1,
    ACTIONS(1991), 1,
      sym__code_block,
  [12943] = 1,
    ACTIONS(1993), 1,
      aux_sym_select_element_token1,
  [12947] = 1,
    ACTIONS(1995), 1,
      aux_sym_create_aggregate_token6,
  [12951] = 1,
    ACTIONS(1997), 1,
      ts_builtin_sym_end,
  [12955] = 1,
    ACTIONS(1999), 1,
      sym__code_block,
  [12959] = 1,
    ACTIONS(2001), 1,
      aux_sym_begin_batch_token5,
  [12963] = 1,
    ACTIONS(2003), 1,
      sym_object_name,
  [12967] = 1,
    ACTIONS(2005), 1,
      sym_object_name,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 92,
  [SMALL_STATE(4)] = 184,
  [SMALL_STATE(5)] = 243,
  [SMALL_STATE(6)] = 302,
  [SMALL_STATE(7)] = 361,
  [SMALL_STATE(8)] = 420,
  [SMALL_STATE(9)] = 479,
  [SMALL_STATE(10)] = 538,
  [SMALL_STATE(11)] = 597,
  [SMALL_STATE(12)] = 656,
  [SMALL_STATE(13)] = 715,
  [SMALL_STATE(14)] = 774,
  [SMALL_STATE(15)] = 833,
  [SMALL_STATE(16)] = 892,
  [SMALL_STATE(17)] = 951,
  [SMALL_STATE(18)] = 1010,
  [SMALL_STATE(19)] = 1069,
  [SMALL_STATE(20)] = 1128,
  [SMALL_STATE(21)] = 1187,
  [SMALL_STATE(22)] = 1246,
  [SMALL_STATE(23)] = 1305,
  [SMALL_STATE(24)] = 1361,
  [SMALL_STATE(25)] = 1417,
  [SMALL_STATE(26)] = 1473,
  [SMALL_STATE(27)] = 1529,
  [SMALL_STATE(28)] = 1585,
  [SMALL_STATE(29)] = 1641,
  [SMALL_STATE(30)] = 1678,
  [SMALL_STATE(31)] = 1710,
  [SMALL_STATE(32)] = 1742,
  [SMALL_STATE(33)] = 1774,
  [SMALL_STATE(34)] = 1803,
  [SMALL_STATE(35)] = 1832,
  [SMALL_STATE(36)] = 1861,
  [SMALL_STATE(37)] = 1893,
  [SMALL_STATE(38)] = 1924,
  [SMALL_STATE(39)] = 1951,
  [SMALL_STATE(40)] = 1982,
  [SMALL_STATE(41)] = 2009,
  [SMALL_STATE(42)] = 2040,
  [SMALL_STATE(43)] = 2071,
  [SMALL_STATE(44)] = 2099,
  [SMALL_STATE(45)] = 2139,
  [SMALL_STATE(46)] = 2169,
  [SMALL_STATE(47)] = 2209,
  [SMALL_STATE(48)] = 2249,
  [SMALL_STATE(49)] = 2274,
  [SMALL_STATE(50)] = 2299,
  [SMALL_STATE(51)] = 2324,
  [SMALL_STATE(52)] = 2371,
  [SMALL_STATE(53)] = 2396,
  [SMALL_STATE(54)] = 2421,
  [SMALL_STATE(55)] = 2446,
  [SMALL_STATE(56)] = 2471,
  [SMALL_STATE(57)] = 2496,
  [SMALL_STATE(58)] = 2525,
  [SMALL_STATE(59)] = 2550,
  [SMALL_STATE(60)] = 2575,
  [SMALL_STATE(61)] = 2604,
  [SMALL_STATE(62)] = 2629,
  [SMALL_STATE(63)] = 2676,
  [SMALL_STATE(64)] = 2701,
  [SMALL_STATE(65)] = 2726,
  [SMALL_STATE(66)] = 2751,
  [SMALL_STATE(67)] = 2776,
  [SMALL_STATE(68)] = 2801,
  [SMALL_STATE(69)] = 2826,
  [SMALL_STATE(70)] = 2851,
  [SMALL_STATE(71)] = 2876,
  [SMALL_STATE(72)] = 2900,
  [SMALL_STATE(73)] = 2934,
  [SMALL_STATE(74)] = 2978,
  [SMALL_STATE(75)] = 3012,
  [SMALL_STATE(76)] = 3046,
  [SMALL_STATE(77)] = 3070,
  [SMALL_STATE(78)] = 3095,
  [SMALL_STATE(79)] = 3120,
  [SMALL_STATE(80)] = 3145,
  [SMALL_STATE(81)] = 3170,
  [SMALL_STATE(82)] = 3193,
  [SMALL_STATE(83)] = 3218,
  [SMALL_STATE(84)] = 3243,
  [SMALL_STATE(85)] = 3268,
  [SMALL_STATE(86)] = 3290,
  [SMALL_STATE(87)] = 3312,
  [SMALL_STATE(88)] = 3334,
  [SMALL_STATE(89)] = 3356,
  [SMALL_STATE(90)] = 3378,
  [SMALL_STATE(91)] = 3406,
  [SMALL_STATE(92)] = 3428,
  [SMALL_STATE(93)] = 3454,
  [SMALL_STATE(94)] = 3482,
  [SMALL_STATE(95)] = 3510,
  [SMALL_STATE(96)] = 3534,
  [SMALL_STATE(97)] = 3562,
  [SMALL_STATE(98)] = 3588,
  [SMALL_STATE(99)] = 3614,
  [SMALL_STATE(100)] = 3642,
  [SMALL_STATE(101)] = 3664,
  [SMALL_STATE(102)] = 3692,
  [SMALL_STATE(103)] = 3714,
  [SMALL_STATE(104)] = 3738,
  [SMALL_STATE(105)] = 3760,
  [SMALL_STATE(106)] = 3781,
  [SMALL_STATE(107)] = 3806,
  [SMALL_STATE(108)] = 3831,
  [SMALL_STATE(109)] = 3856,
  [SMALL_STATE(110)] = 3881,
  [SMALL_STATE(111)] = 3902,
  [SMALL_STATE(112)] = 3923,
  [SMALL_STATE(113)] = 3948,
  [SMALL_STATE(114)] = 3973,
  [SMALL_STATE(115)] = 3998,
  [SMALL_STATE(116)] = 4023,
  [SMALL_STATE(117)] = 4048,
  [SMALL_STATE(118)] = 4069,
  [SMALL_STATE(119)] = 4092,
  [SMALL_STATE(120)] = 4113,
  [SMALL_STATE(121)] = 4138,
  [SMALL_STATE(122)] = 4159,
  [SMALL_STATE(123)] = 4184,
  [SMALL_STATE(124)] = 4205,
  [SMALL_STATE(125)] = 4230,
  [SMALL_STATE(126)] = 4255,
  [SMALL_STATE(127)] = 4276,
  [SMALL_STATE(128)] = 4301,
  [SMALL_STATE(129)] = 4324,
  [SMALL_STATE(130)] = 4347,
  [SMALL_STATE(131)] = 4372,
  [SMALL_STATE(132)] = 4393,
  [SMALL_STATE(133)] = 4418,
  [SMALL_STATE(134)] = 4443,
  [SMALL_STATE(135)] = 4464,
  [SMALL_STATE(136)] = 4485,
  [SMALL_STATE(137)] = 4510,
  [SMALL_STATE(138)] = 4531,
  [SMALL_STATE(139)] = 4556,
  [SMALL_STATE(140)] = 4581,
  [SMALL_STATE(141)] = 4606,
  [SMALL_STATE(142)] = 4627,
  [SMALL_STATE(143)] = 4652,
  [SMALL_STATE(144)] = 4673,
  [SMALL_STATE(145)] = 4698,
  [SMALL_STATE(146)] = 4723,
  [SMALL_STATE(147)] = 4744,
  [SMALL_STATE(148)] = 4769,
  [SMALL_STATE(149)] = 4790,
  [SMALL_STATE(150)] = 4811,
  [SMALL_STATE(151)] = 4836,
  [SMALL_STATE(152)] = 4861,
  [SMALL_STATE(153)] = 4886,
  [SMALL_STATE(154)] = 4907,
  [SMALL_STATE(155)] = 4932,
  [SMALL_STATE(156)] = 4957,
  [SMALL_STATE(157)] = 4982,
  [SMALL_STATE(158)] = 5007,
  [SMALL_STATE(159)] = 5032,
  [SMALL_STATE(160)] = 5057,
  [SMALL_STATE(161)] = 5079,
  [SMALL_STATE(162)] = 5101,
  [SMALL_STATE(163)] = 5123,
  [SMALL_STATE(164)] = 5145,
  [SMALL_STATE(165)] = 5165,
  [SMALL_STATE(166)] = 5185,
  [SMALL_STATE(167)] = 5205,
  [SMALL_STATE(168)] = 5225,
  [SMALL_STATE(169)] = 5247,
  [SMALL_STATE(170)] = 5269,
  [SMALL_STATE(171)] = 5289,
  [SMALL_STATE(172)] = 5309,
  [SMALL_STATE(173)] = 5331,
  [SMALL_STATE(174)] = 5353,
  [SMALL_STATE(175)] = 5373,
  [SMALL_STATE(176)] = 5393,
  [SMALL_STATE(177)] = 5413,
  [SMALL_STATE(178)] = 5433,
  [SMALL_STATE(179)] = 5453,
  [SMALL_STATE(180)] = 5473,
  [SMALL_STATE(181)] = 5493,
  [SMALL_STATE(182)] = 5513,
  [SMALL_STATE(183)] = 5535,
  [SMALL_STATE(184)] = 5555,
  [SMALL_STATE(185)] = 5575,
  [SMALL_STATE(186)] = 5595,
  [SMALL_STATE(187)] = 5615,
  [SMALL_STATE(188)] = 5637,
  [SMALL_STATE(189)] = 5657,
  [SMALL_STATE(190)] = 5677,
  [SMALL_STATE(191)] = 5697,
  [SMALL_STATE(192)] = 5717,
  [SMALL_STATE(193)] = 5739,
  [SMALL_STATE(194)] = 5759,
  [SMALL_STATE(195)] = 5779,
  [SMALL_STATE(196)] = 5799,
  [SMALL_STATE(197)] = 5818,
  [SMALL_STATE(198)] = 5837,
  [SMALL_STATE(199)] = 5856,
  [SMALL_STATE(200)] = 5875,
  [SMALL_STATE(201)] = 5894,
  [SMALL_STATE(202)] = 5913,
  [SMALL_STATE(203)] = 5932,
  [SMALL_STATE(204)] = 5951,
  [SMALL_STATE(205)] = 5970,
  [SMALL_STATE(206)] = 5989,
  [SMALL_STATE(207)] = 6008,
  [SMALL_STATE(208)] = 6027,
  [SMALL_STATE(209)] = 6046,
  [SMALL_STATE(210)] = 6065,
  [SMALL_STATE(211)] = 6084,
  [SMALL_STATE(212)] = 6103,
  [SMALL_STATE(213)] = 6122,
  [SMALL_STATE(214)] = 6141,
  [SMALL_STATE(215)] = 6160,
  [SMALL_STATE(216)] = 6179,
  [SMALL_STATE(217)] = 6198,
  [SMALL_STATE(218)] = 6217,
  [SMALL_STATE(219)] = 6236,
  [SMALL_STATE(220)] = 6255,
  [SMALL_STATE(221)] = 6274,
  [SMALL_STATE(222)] = 6293,
  [SMALL_STATE(223)] = 6312,
  [SMALL_STATE(224)] = 6331,
  [SMALL_STATE(225)] = 6350,
  [SMALL_STATE(226)] = 6369,
  [SMALL_STATE(227)] = 6390,
  [SMALL_STATE(228)] = 6409,
  [SMALL_STATE(229)] = 6428,
  [SMALL_STATE(230)] = 6447,
  [SMALL_STATE(231)] = 6466,
  [SMALL_STATE(232)] = 6485,
  [SMALL_STATE(233)] = 6504,
  [SMALL_STATE(234)] = 6523,
  [SMALL_STATE(235)] = 6542,
  [SMALL_STATE(236)] = 6561,
  [SMALL_STATE(237)] = 6580,
  [SMALL_STATE(238)] = 6599,
  [SMALL_STATE(239)] = 6618,
  [SMALL_STATE(240)] = 6637,
  [SMALL_STATE(241)] = 6656,
  [SMALL_STATE(242)] = 6675,
  [SMALL_STATE(243)] = 6694,
  [SMALL_STATE(244)] = 6713,
  [SMALL_STATE(245)] = 6732,
  [SMALL_STATE(246)] = 6751,
  [SMALL_STATE(247)] = 6770,
  [SMALL_STATE(248)] = 6789,
  [SMALL_STATE(249)] = 6808,
  [SMALL_STATE(250)] = 6827,
  [SMALL_STATE(251)] = 6846,
  [SMALL_STATE(252)] = 6865,
  [SMALL_STATE(253)] = 6884,
  [SMALL_STATE(254)] = 6903,
  [SMALL_STATE(255)] = 6922,
  [SMALL_STATE(256)] = 6941,
  [SMALL_STATE(257)] = 6960,
  [SMALL_STATE(258)] = 6979,
  [SMALL_STATE(259)] = 6998,
  [SMALL_STATE(260)] = 7017,
  [SMALL_STATE(261)] = 7036,
  [SMALL_STATE(262)] = 7055,
  [SMALL_STATE(263)] = 7074,
  [SMALL_STATE(264)] = 7093,
  [SMALL_STATE(265)] = 7112,
  [SMALL_STATE(266)] = 7131,
  [SMALL_STATE(267)] = 7150,
  [SMALL_STATE(268)] = 7169,
  [SMALL_STATE(269)] = 7188,
  [SMALL_STATE(270)] = 7207,
  [SMALL_STATE(271)] = 7226,
  [SMALL_STATE(272)] = 7245,
  [SMALL_STATE(273)] = 7264,
  [SMALL_STATE(274)] = 7283,
  [SMALL_STATE(275)] = 7302,
  [SMALL_STATE(276)] = 7321,
  [SMALL_STATE(277)] = 7340,
  [SMALL_STATE(278)] = 7359,
  [SMALL_STATE(279)] = 7378,
  [SMALL_STATE(280)] = 7397,
  [SMALL_STATE(281)] = 7416,
  [SMALL_STATE(282)] = 7435,
  [SMALL_STATE(283)] = 7454,
  [SMALL_STATE(284)] = 7489,
  [SMALL_STATE(285)] = 7508,
  [SMALL_STATE(286)] = 7527,
  [SMALL_STATE(287)] = 7546,
  [SMALL_STATE(288)] = 7565,
  [SMALL_STATE(289)] = 7584,
  [SMALL_STATE(290)] = 7603,
  [SMALL_STATE(291)] = 7622,
  [SMALL_STATE(292)] = 7641,
  [SMALL_STATE(293)] = 7660,
  [SMALL_STATE(294)] = 7679,
  [SMALL_STATE(295)] = 7698,
  [SMALL_STATE(296)] = 7717,
  [SMALL_STATE(297)] = 7750,
  [SMALL_STATE(298)] = 7769,
  [SMALL_STATE(299)] = 7799,
  [SMALL_STATE(300)] = 7829,
  [SMALL_STATE(301)] = 7859,
  [SMALL_STATE(302)] = 7889,
  [SMALL_STATE(303)] = 7923,
  [SMALL_STATE(304)] = 7941,
  [SMALL_STATE(305)] = 7971,
  [SMALL_STATE(306)] = 8000,
  [SMALL_STATE(307)] = 8031,
  [SMALL_STATE(308)] = 8060,
  [SMALL_STATE(309)] = 8089,
  [SMALL_STATE(310)] = 8118,
  [SMALL_STATE(311)] = 8147,
  [SMALL_STATE(312)] = 8180,
  [SMALL_STATE(313)] = 8208,
  [SMALL_STATE(314)] = 8233,
  [SMALL_STATE(315)] = 8258,
  [SMALL_STATE(316)] = 8282,
  [SMALL_STATE(317)] = 8302,
  [SMALL_STATE(318)] = 8336,
  [SMALL_STATE(319)] = 8357,
  [SMALL_STATE(320)] = 8378,
  [SMALL_STATE(321)] = 8401,
  [SMALL_STATE(322)] = 8422,
  [SMALL_STATE(323)] = 8439,
  [SMALL_STATE(324)] = 8456,
  [SMALL_STATE(325)] = 8479,
  [SMALL_STATE(326)] = 8500,
  [SMALL_STATE(327)] = 8521,
  [SMALL_STATE(328)] = 8552,
  [SMALL_STATE(329)] = 8573,
  [SMALL_STATE(330)] = 8593,
  [SMALL_STATE(331)] = 8616,
  [SMALL_STATE(332)] = 8639,
  [SMALL_STATE(333)] = 8660,
  [SMALL_STATE(334)] = 8683,
  [SMALL_STATE(335)] = 8704,
  [SMALL_STATE(336)] = 8727,
  [SMALL_STATE(337)] = 8748,
  [SMALL_STATE(338)] = 8771,
  [SMALL_STATE(339)] = 8792,
  [SMALL_STATE(340)] = 8813,
  [SMALL_STATE(341)] = 8836,
  [SMALL_STATE(342)] = 8859,
  [SMALL_STATE(343)] = 8877,
  [SMALL_STATE(344)] = 8899,
  [SMALL_STATE(345)] = 8921,
  [SMALL_STATE(346)] = 8941,
  [SMALL_STATE(347)] = 8955,
  [SMALL_STATE(348)] = 8973,
  [SMALL_STATE(349)] = 8995,
  [SMALL_STATE(350)] = 9013,
  [SMALL_STATE(351)] = 9033,
  [SMALL_STATE(352)] = 9055,
  [SMALL_STATE(353)] = 9069,
  [SMALL_STATE(354)] = 9080,
  [SMALL_STATE(355)] = 9099,
  [SMALL_STATE(356)] = 9118,
  [SMALL_STATE(357)] = 9135,
  [SMALL_STATE(358)] = 9149,
  [SMALL_STATE(359)] = 9157,
  [SMALL_STATE(360)] = 9165,
  [SMALL_STATE(361)] = 9181,
  [SMALL_STATE(362)] = 9197,
  [SMALL_STATE(363)] = 9209,
  [SMALL_STATE(364)] = 9225,
  [SMALL_STATE(365)] = 9233,
  [SMALL_STATE(366)] = 9245,
  [SMALL_STATE(367)] = 9253,
  [SMALL_STATE(368)] = 9261,
  [SMALL_STATE(369)] = 9269,
  [SMALL_STATE(370)] = 9285,
  [SMALL_STATE(371)] = 9297,
  [SMALL_STATE(372)] = 9313,
  [SMALL_STATE(373)] = 9327,
  [SMALL_STATE(374)] = 9343,
  [SMALL_STATE(375)] = 9359,
  [SMALL_STATE(376)] = 9367,
  [SMALL_STATE(377)] = 9376,
  [SMALL_STATE(378)] = 9389,
  [SMALL_STATE(379)] = 9400,
  [SMALL_STATE(380)] = 9413,
  [SMALL_STATE(381)] = 9426,
  [SMALL_STATE(382)] = 9437,
  [SMALL_STATE(383)] = 9448,
  [SMALL_STATE(384)] = 9461,
  [SMALL_STATE(385)] = 9472,
  [SMALL_STATE(386)] = 9485,
  [SMALL_STATE(387)] = 9494,
  [SMALL_STATE(388)] = 9507,
  [SMALL_STATE(389)] = 9520,
  [SMALL_STATE(390)] = 9531,
  [SMALL_STATE(391)] = 9544,
  [SMALL_STATE(392)] = 9557,
  [SMALL_STATE(393)] = 9570,
  [SMALL_STATE(394)] = 9577,
  [SMALL_STATE(395)] = 9586,
  [SMALL_STATE(396)] = 9597,
  [SMALL_STATE(397)] = 9610,
  [SMALL_STATE(398)] = 9620,
  [SMALL_STATE(399)] = 9630,
  [SMALL_STATE(400)] = 9640,
  [SMALL_STATE(401)] = 9650,
  [SMALL_STATE(402)] = 9660,
  [SMALL_STATE(403)] = 9670,
  [SMALL_STATE(404)] = 9680,
  [SMALL_STATE(405)] = 9690,
  [SMALL_STATE(406)] = 9700,
  [SMALL_STATE(407)] = 9710,
  [SMALL_STATE(408)] = 9720,
  [SMALL_STATE(409)] = 9730,
  [SMALL_STATE(410)] = 9740,
  [SMALL_STATE(411)] = 9750,
  [SMALL_STATE(412)] = 9760,
  [SMALL_STATE(413)] = 9768,
  [SMALL_STATE(414)] = 9778,
  [SMALL_STATE(415)] = 9788,
  [SMALL_STATE(416)] = 9798,
  [SMALL_STATE(417)] = 9808,
  [SMALL_STATE(418)] = 9816,
  [SMALL_STATE(419)] = 9826,
  [SMALL_STATE(420)] = 9836,
  [SMALL_STATE(421)] = 9846,
  [SMALL_STATE(422)] = 9854,
  [SMALL_STATE(423)] = 9864,
  [SMALL_STATE(424)] = 9874,
  [SMALL_STATE(425)] = 9884,
  [SMALL_STATE(426)] = 9894,
  [SMALL_STATE(427)] = 9904,
  [SMALL_STATE(428)] = 9914,
  [SMALL_STATE(429)] = 9924,
  [SMALL_STATE(430)] = 9934,
  [SMALL_STATE(431)] = 9944,
  [SMALL_STATE(432)] = 9954,
  [SMALL_STATE(433)] = 9964,
  [SMALL_STATE(434)] = 9974,
  [SMALL_STATE(435)] = 9984,
  [SMALL_STATE(436)] = 9994,
  [SMALL_STATE(437)] = 10004,
  [SMALL_STATE(438)] = 10014,
  [SMALL_STATE(439)] = 10024,
  [SMALL_STATE(440)] = 10030,
  [SMALL_STATE(441)] = 10040,
  [SMALL_STATE(442)] = 10050,
  [SMALL_STATE(443)] = 10060,
  [SMALL_STATE(444)] = 10070,
  [SMALL_STATE(445)] = 10080,
  [SMALL_STATE(446)] = 10090,
  [SMALL_STATE(447)] = 10100,
  [SMALL_STATE(448)] = 10110,
  [SMALL_STATE(449)] = 10120,
  [SMALL_STATE(450)] = 10130,
  [SMALL_STATE(451)] = 10140,
  [SMALL_STATE(452)] = 10150,
  [SMALL_STATE(453)] = 10160,
  [SMALL_STATE(454)] = 10170,
  [SMALL_STATE(455)] = 10180,
  [SMALL_STATE(456)] = 10190,
  [SMALL_STATE(457)] = 10200,
  [SMALL_STATE(458)] = 10210,
  [SMALL_STATE(459)] = 10220,
  [SMALL_STATE(460)] = 10230,
  [SMALL_STATE(461)] = 10240,
  [SMALL_STATE(462)] = 10250,
  [SMALL_STATE(463)] = 10260,
  [SMALL_STATE(464)] = 10270,
  [SMALL_STATE(465)] = 10280,
  [SMALL_STATE(466)] = 10290,
  [SMALL_STATE(467)] = 10300,
  [SMALL_STATE(468)] = 10310,
  [SMALL_STATE(469)] = 10320,
  [SMALL_STATE(470)] = 10330,
  [SMALL_STATE(471)] = 10340,
  [SMALL_STATE(472)] = 10350,
  [SMALL_STATE(473)] = 10360,
  [SMALL_STATE(474)] = 10370,
  [SMALL_STATE(475)] = 10376,
  [SMALL_STATE(476)] = 10386,
  [SMALL_STATE(477)] = 10394,
  [SMALL_STATE(478)] = 10404,
  [SMALL_STATE(479)] = 10412,
  [SMALL_STATE(480)] = 10422,
  [SMALL_STATE(481)] = 10432,
  [SMALL_STATE(482)] = 10442,
  [SMALL_STATE(483)] = 10452,
  [SMALL_STATE(484)] = 10462,
  [SMALL_STATE(485)] = 10472,
  [SMALL_STATE(486)] = 10482,
  [SMALL_STATE(487)] = 10492,
  [SMALL_STATE(488)] = 10502,
  [SMALL_STATE(489)] = 10512,
  [SMALL_STATE(490)] = 10522,
  [SMALL_STATE(491)] = 10532,
  [SMALL_STATE(492)] = 10542,
  [SMALL_STATE(493)] = 10552,
  [SMALL_STATE(494)] = 10558,
  [SMALL_STATE(495)] = 10568,
  [SMALL_STATE(496)] = 10578,
  [SMALL_STATE(497)] = 10588,
  [SMALL_STATE(498)] = 10598,
  [SMALL_STATE(499)] = 10604,
  [SMALL_STATE(500)] = 10614,
  [SMALL_STATE(501)] = 10624,
  [SMALL_STATE(502)] = 10634,
  [SMALL_STATE(503)] = 10644,
  [SMALL_STATE(504)] = 10654,
  [SMALL_STATE(505)] = 10664,
  [SMALL_STATE(506)] = 10674,
  [SMALL_STATE(507)] = 10684,
  [SMALL_STATE(508)] = 10694,
  [SMALL_STATE(509)] = 10704,
  [SMALL_STATE(510)] = 10714,
  [SMALL_STATE(511)] = 10724,
  [SMALL_STATE(512)] = 10734,
  [SMALL_STATE(513)] = 10744,
  [SMALL_STATE(514)] = 10754,
  [SMALL_STATE(515)] = 10764,
  [SMALL_STATE(516)] = 10774,
  [SMALL_STATE(517)] = 10784,
  [SMALL_STATE(518)] = 10794,
  [SMALL_STATE(519)] = 10804,
  [SMALL_STATE(520)] = 10814,
  [SMALL_STATE(521)] = 10824,
  [SMALL_STATE(522)] = 10832,
  [SMALL_STATE(523)] = 10842,
  [SMALL_STATE(524)] = 10849,
  [SMALL_STATE(525)] = 10856,
  [SMALL_STATE(526)] = 10863,
  [SMALL_STATE(527)] = 10870,
  [SMALL_STATE(528)] = 10877,
  [SMALL_STATE(529)] = 10884,
  [SMALL_STATE(530)] = 10889,
  [SMALL_STATE(531)] = 10896,
  [SMALL_STATE(532)] = 10903,
  [SMALL_STATE(533)] = 10908,
  [SMALL_STATE(534)] = 10915,
  [SMALL_STATE(535)] = 10920,
  [SMALL_STATE(536)] = 10927,
  [SMALL_STATE(537)] = 10932,
  [SMALL_STATE(538)] = 10937,
  [SMALL_STATE(539)] = 10942,
  [SMALL_STATE(540)] = 10947,
  [SMALL_STATE(541)] = 10954,
  [SMALL_STATE(542)] = 10961,
  [SMALL_STATE(543)] = 10968,
  [SMALL_STATE(544)] = 10975,
  [SMALL_STATE(545)] = 10982,
  [SMALL_STATE(546)] = 10989,
  [SMALL_STATE(547)] = 10996,
  [SMALL_STATE(548)] = 11003,
  [SMALL_STATE(549)] = 11010,
  [SMALL_STATE(550)] = 11017,
  [SMALL_STATE(551)] = 11024,
  [SMALL_STATE(552)] = 11031,
  [SMALL_STATE(553)] = 11036,
  [SMALL_STATE(554)] = 11043,
  [SMALL_STATE(555)] = 11050,
  [SMALL_STATE(556)] = 11057,
  [SMALL_STATE(557)] = 11064,
  [SMALL_STATE(558)] = 11071,
  [SMALL_STATE(559)] = 11076,
  [SMALL_STATE(560)] = 11083,
  [SMALL_STATE(561)] = 11088,
  [SMALL_STATE(562)] = 11093,
  [SMALL_STATE(563)] = 11100,
  [SMALL_STATE(564)] = 11107,
  [SMALL_STATE(565)] = 11114,
  [SMALL_STATE(566)] = 11119,
  [SMALL_STATE(567)] = 11126,
  [SMALL_STATE(568)] = 11133,
  [SMALL_STATE(569)] = 11138,
  [SMALL_STATE(570)] = 11145,
  [SMALL_STATE(571)] = 11152,
  [SMALL_STATE(572)] = 11157,
  [SMALL_STATE(573)] = 11164,
  [SMALL_STATE(574)] = 11171,
  [SMALL_STATE(575)] = 11178,
  [SMALL_STATE(576)] = 11185,
  [SMALL_STATE(577)] = 11192,
  [SMALL_STATE(578)] = 11199,
  [SMALL_STATE(579)] = 11206,
  [SMALL_STATE(580)] = 11213,
  [SMALL_STATE(581)] = 11220,
  [SMALL_STATE(582)] = 11227,
  [SMALL_STATE(583)] = 11234,
  [SMALL_STATE(584)] = 11241,
  [SMALL_STATE(585)] = 11248,
  [SMALL_STATE(586)] = 11255,
  [SMALL_STATE(587)] = 11262,
  [SMALL_STATE(588)] = 11269,
  [SMALL_STATE(589)] = 11276,
  [SMALL_STATE(590)] = 11283,
  [SMALL_STATE(591)] = 11288,
  [SMALL_STATE(592)] = 11293,
  [SMALL_STATE(593)] = 11300,
  [SMALL_STATE(594)] = 11307,
  [SMALL_STATE(595)] = 11312,
  [SMALL_STATE(596)] = 11319,
  [SMALL_STATE(597)] = 11326,
  [SMALL_STATE(598)] = 11333,
  [SMALL_STATE(599)] = 11338,
  [SMALL_STATE(600)] = 11345,
  [SMALL_STATE(601)] = 11352,
  [SMALL_STATE(602)] = 11359,
  [SMALL_STATE(603)] = 11366,
  [SMALL_STATE(604)] = 11373,
  [SMALL_STATE(605)] = 11380,
  [SMALL_STATE(606)] = 11385,
  [SMALL_STATE(607)] = 11392,
  [SMALL_STATE(608)] = 11399,
  [SMALL_STATE(609)] = 11406,
  [SMALL_STATE(610)] = 11411,
  [SMALL_STATE(611)] = 11416,
  [SMALL_STATE(612)] = 11421,
  [SMALL_STATE(613)] = 11426,
  [SMALL_STATE(614)] = 11431,
  [SMALL_STATE(615)] = 11438,
  [SMALL_STATE(616)] = 11445,
  [SMALL_STATE(617)] = 11452,
  [SMALL_STATE(618)] = 11459,
  [SMALL_STATE(619)] = 11466,
  [SMALL_STATE(620)] = 11473,
  [SMALL_STATE(621)] = 11480,
  [SMALL_STATE(622)] = 11487,
  [SMALL_STATE(623)] = 11494,
  [SMALL_STATE(624)] = 11501,
  [SMALL_STATE(625)] = 11508,
  [SMALL_STATE(626)] = 11515,
  [SMALL_STATE(627)] = 11522,
  [SMALL_STATE(628)] = 11529,
  [SMALL_STATE(629)] = 11536,
  [SMALL_STATE(630)] = 11543,
  [SMALL_STATE(631)] = 11550,
  [SMALL_STATE(632)] = 11557,
  [SMALL_STATE(633)] = 11564,
  [SMALL_STATE(634)] = 11569,
  [SMALL_STATE(635)] = 11576,
  [SMALL_STATE(636)] = 11583,
  [SMALL_STATE(637)] = 11590,
  [SMALL_STATE(638)] = 11597,
  [SMALL_STATE(639)] = 11602,
  [SMALL_STATE(640)] = 11609,
  [SMALL_STATE(641)] = 11616,
  [SMALL_STATE(642)] = 11623,
  [SMALL_STATE(643)] = 11630,
  [SMALL_STATE(644)] = 11637,
  [SMALL_STATE(645)] = 11644,
  [SMALL_STATE(646)] = 11651,
  [SMALL_STATE(647)] = 11658,
  [SMALL_STATE(648)] = 11663,
  [SMALL_STATE(649)] = 11670,
  [SMALL_STATE(650)] = 11677,
  [SMALL_STATE(651)] = 11682,
  [SMALL_STATE(652)] = 11689,
  [SMALL_STATE(653)] = 11696,
  [SMALL_STATE(654)] = 11701,
  [SMALL_STATE(655)] = 11708,
  [SMALL_STATE(656)] = 11715,
  [SMALL_STATE(657)] = 11722,
  [SMALL_STATE(658)] = 11729,
  [SMALL_STATE(659)] = 11736,
  [SMALL_STATE(660)] = 11743,
  [SMALL_STATE(661)] = 11750,
  [SMALL_STATE(662)] = 11755,
  [SMALL_STATE(663)] = 11760,
  [SMALL_STATE(664)] = 11767,
  [SMALL_STATE(665)] = 11774,
  [SMALL_STATE(666)] = 11781,
  [SMALL_STATE(667)] = 11788,
  [SMALL_STATE(668)] = 11795,
  [SMALL_STATE(669)] = 11800,
  [SMALL_STATE(670)] = 11807,
  [SMALL_STATE(671)] = 11811,
  [SMALL_STATE(672)] = 11815,
  [SMALL_STATE(673)] = 11819,
  [SMALL_STATE(674)] = 11823,
  [SMALL_STATE(675)] = 11827,
  [SMALL_STATE(676)] = 11831,
  [SMALL_STATE(677)] = 11835,
  [SMALL_STATE(678)] = 11839,
  [SMALL_STATE(679)] = 11843,
  [SMALL_STATE(680)] = 11847,
  [SMALL_STATE(681)] = 11851,
  [SMALL_STATE(682)] = 11855,
  [SMALL_STATE(683)] = 11859,
  [SMALL_STATE(684)] = 11863,
  [SMALL_STATE(685)] = 11867,
  [SMALL_STATE(686)] = 11871,
  [SMALL_STATE(687)] = 11875,
  [SMALL_STATE(688)] = 11879,
  [SMALL_STATE(689)] = 11883,
  [SMALL_STATE(690)] = 11887,
  [SMALL_STATE(691)] = 11891,
  [SMALL_STATE(692)] = 11895,
  [SMALL_STATE(693)] = 11899,
  [SMALL_STATE(694)] = 11903,
  [SMALL_STATE(695)] = 11907,
  [SMALL_STATE(696)] = 11911,
  [SMALL_STATE(697)] = 11915,
  [SMALL_STATE(698)] = 11919,
  [SMALL_STATE(699)] = 11923,
  [SMALL_STATE(700)] = 11927,
  [SMALL_STATE(701)] = 11931,
  [SMALL_STATE(702)] = 11935,
  [SMALL_STATE(703)] = 11939,
  [SMALL_STATE(704)] = 11943,
  [SMALL_STATE(705)] = 11947,
  [SMALL_STATE(706)] = 11951,
  [SMALL_STATE(707)] = 11955,
  [SMALL_STATE(708)] = 11959,
  [SMALL_STATE(709)] = 11963,
  [SMALL_STATE(710)] = 11967,
  [SMALL_STATE(711)] = 11971,
  [SMALL_STATE(712)] = 11975,
  [SMALL_STATE(713)] = 11979,
  [SMALL_STATE(714)] = 11983,
  [SMALL_STATE(715)] = 11987,
  [SMALL_STATE(716)] = 11991,
  [SMALL_STATE(717)] = 11995,
  [SMALL_STATE(718)] = 11999,
  [SMALL_STATE(719)] = 12003,
  [SMALL_STATE(720)] = 12007,
  [SMALL_STATE(721)] = 12011,
  [SMALL_STATE(722)] = 12015,
  [SMALL_STATE(723)] = 12019,
  [SMALL_STATE(724)] = 12023,
  [SMALL_STATE(725)] = 12027,
  [SMALL_STATE(726)] = 12031,
  [SMALL_STATE(727)] = 12035,
  [SMALL_STATE(728)] = 12039,
  [SMALL_STATE(729)] = 12043,
  [SMALL_STATE(730)] = 12047,
  [SMALL_STATE(731)] = 12051,
  [SMALL_STATE(732)] = 12055,
  [SMALL_STATE(733)] = 12059,
  [SMALL_STATE(734)] = 12063,
  [SMALL_STATE(735)] = 12067,
  [SMALL_STATE(736)] = 12071,
  [SMALL_STATE(737)] = 12075,
  [SMALL_STATE(738)] = 12079,
  [SMALL_STATE(739)] = 12083,
  [SMALL_STATE(740)] = 12087,
  [SMALL_STATE(741)] = 12091,
  [SMALL_STATE(742)] = 12095,
  [SMALL_STATE(743)] = 12099,
  [SMALL_STATE(744)] = 12103,
  [SMALL_STATE(745)] = 12107,
  [SMALL_STATE(746)] = 12111,
  [SMALL_STATE(747)] = 12115,
  [SMALL_STATE(748)] = 12119,
  [SMALL_STATE(749)] = 12123,
  [SMALL_STATE(750)] = 12127,
  [SMALL_STATE(751)] = 12131,
  [SMALL_STATE(752)] = 12135,
  [SMALL_STATE(753)] = 12139,
  [SMALL_STATE(754)] = 12143,
  [SMALL_STATE(755)] = 12147,
  [SMALL_STATE(756)] = 12151,
  [SMALL_STATE(757)] = 12155,
  [SMALL_STATE(758)] = 12159,
  [SMALL_STATE(759)] = 12163,
  [SMALL_STATE(760)] = 12167,
  [SMALL_STATE(761)] = 12171,
  [SMALL_STATE(762)] = 12175,
  [SMALL_STATE(763)] = 12179,
  [SMALL_STATE(764)] = 12183,
  [SMALL_STATE(765)] = 12187,
  [SMALL_STATE(766)] = 12191,
  [SMALL_STATE(767)] = 12195,
  [SMALL_STATE(768)] = 12199,
  [SMALL_STATE(769)] = 12203,
  [SMALL_STATE(770)] = 12207,
  [SMALL_STATE(771)] = 12211,
  [SMALL_STATE(772)] = 12215,
  [SMALL_STATE(773)] = 12219,
  [SMALL_STATE(774)] = 12223,
  [SMALL_STATE(775)] = 12227,
  [SMALL_STATE(776)] = 12231,
  [SMALL_STATE(777)] = 12235,
  [SMALL_STATE(778)] = 12239,
  [SMALL_STATE(779)] = 12243,
  [SMALL_STATE(780)] = 12247,
  [SMALL_STATE(781)] = 12251,
  [SMALL_STATE(782)] = 12255,
  [SMALL_STATE(783)] = 12259,
  [SMALL_STATE(784)] = 12263,
  [SMALL_STATE(785)] = 12267,
  [SMALL_STATE(786)] = 12271,
  [SMALL_STATE(787)] = 12275,
  [SMALL_STATE(788)] = 12279,
  [SMALL_STATE(789)] = 12283,
  [SMALL_STATE(790)] = 12287,
  [SMALL_STATE(791)] = 12291,
  [SMALL_STATE(792)] = 12295,
  [SMALL_STATE(793)] = 12299,
  [SMALL_STATE(794)] = 12303,
  [SMALL_STATE(795)] = 12307,
  [SMALL_STATE(796)] = 12311,
  [SMALL_STATE(797)] = 12315,
  [SMALL_STATE(798)] = 12319,
  [SMALL_STATE(799)] = 12323,
  [SMALL_STATE(800)] = 12327,
  [SMALL_STATE(801)] = 12331,
  [SMALL_STATE(802)] = 12335,
  [SMALL_STATE(803)] = 12339,
  [SMALL_STATE(804)] = 12343,
  [SMALL_STATE(805)] = 12347,
  [SMALL_STATE(806)] = 12351,
  [SMALL_STATE(807)] = 12355,
  [SMALL_STATE(808)] = 12359,
  [SMALL_STATE(809)] = 12363,
  [SMALL_STATE(810)] = 12367,
  [SMALL_STATE(811)] = 12371,
  [SMALL_STATE(812)] = 12375,
  [SMALL_STATE(813)] = 12379,
  [SMALL_STATE(814)] = 12383,
  [SMALL_STATE(815)] = 12387,
  [SMALL_STATE(816)] = 12391,
  [SMALL_STATE(817)] = 12395,
  [SMALL_STATE(818)] = 12399,
  [SMALL_STATE(819)] = 12403,
  [SMALL_STATE(820)] = 12407,
  [SMALL_STATE(821)] = 12411,
  [SMALL_STATE(822)] = 12415,
  [SMALL_STATE(823)] = 12419,
  [SMALL_STATE(824)] = 12423,
  [SMALL_STATE(825)] = 12427,
  [SMALL_STATE(826)] = 12431,
  [SMALL_STATE(827)] = 12435,
  [SMALL_STATE(828)] = 12439,
  [SMALL_STATE(829)] = 12443,
  [SMALL_STATE(830)] = 12447,
  [SMALL_STATE(831)] = 12451,
  [SMALL_STATE(832)] = 12455,
  [SMALL_STATE(833)] = 12459,
  [SMALL_STATE(834)] = 12463,
  [SMALL_STATE(835)] = 12467,
  [SMALL_STATE(836)] = 12471,
  [SMALL_STATE(837)] = 12475,
  [SMALL_STATE(838)] = 12479,
  [SMALL_STATE(839)] = 12483,
  [SMALL_STATE(840)] = 12487,
  [SMALL_STATE(841)] = 12491,
  [SMALL_STATE(842)] = 12495,
  [SMALL_STATE(843)] = 12499,
  [SMALL_STATE(844)] = 12503,
  [SMALL_STATE(845)] = 12507,
  [SMALL_STATE(846)] = 12511,
  [SMALL_STATE(847)] = 12515,
  [SMALL_STATE(848)] = 12519,
  [SMALL_STATE(849)] = 12523,
  [SMALL_STATE(850)] = 12527,
  [SMALL_STATE(851)] = 12531,
  [SMALL_STATE(852)] = 12535,
  [SMALL_STATE(853)] = 12539,
  [SMALL_STATE(854)] = 12543,
  [SMALL_STATE(855)] = 12547,
  [SMALL_STATE(856)] = 12551,
  [SMALL_STATE(857)] = 12555,
  [SMALL_STATE(858)] = 12559,
  [SMALL_STATE(859)] = 12563,
  [SMALL_STATE(860)] = 12567,
  [SMALL_STATE(861)] = 12571,
  [SMALL_STATE(862)] = 12575,
  [SMALL_STATE(863)] = 12579,
  [SMALL_STATE(864)] = 12583,
  [SMALL_STATE(865)] = 12587,
  [SMALL_STATE(866)] = 12591,
  [SMALL_STATE(867)] = 12595,
  [SMALL_STATE(868)] = 12599,
  [SMALL_STATE(869)] = 12603,
  [SMALL_STATE(870)] = 12607,
  [SMALL_STATE(871)] = 12611,
  [SMALL_STATE(872)] = 12615,
  [SMALL_STATE(873)] = 12619,
  [SMALL_STATE(874)] = 12623,
  [SMALL_STATE(875)] = 12627,
  [SMALL_STATE(876)] = 12631,
  [SMALL_STATE(877)] = 12635,
  [SMALL_STATE(878)] = 12639,
  [SMALL_STATE(879)] = 12643,
  [SMALL_STATE(880)] = 12647,
  [SMALL_STATE(881)] = 12651,
  [SMALL_STATE(882)] = 12655,
  [SMALL_STATE(883)] = 12659,
  [SMALL_STATE(884)] = 12663,
  [SMALL_STATE(885)] = 12667,
  [SMALL_STATE(886)] = 12671,
  [SMALL_STATE(887)] = 12675,
  [SMALL_STATE(888)] = 12679,
  [SMALL_STATE(889)] = 12683,
  [SMALL_STATE(890)] = 12687,
  [SMALL_STATE(891)] = 12691,
  [SMALL_STATE(892)] = 12695,
  [SMALL_STATE(893)] = 12699,
  [SMALL_STATE(894)] = 12703,
  [SMALL_STATE(895)] = 12707,
  [SMALL_STATE(896)] = 12711,
  [SMALL_STATE(897)] = 12715,
  [SMALL_STATE(898)] = 12719,
  [SMALL_STATE(899)] = 12723,
  [SMALL_STATE(900)] = 12727,
  [SMALL_STATE(901)] = 12731,
  [SMALL_STATE(902)] = 12735,
  [SMALL_STATE(903)] = 12739,
  [SMALL_STATE(904)] = 12743,
  [SMALL_STATE(905)] = 12747,
  [SMALL_STATE(906)] = 12751,
  [SMALL_STATE(907)] = 12755,
  [SMALL_STATE(908)] = 12759,
  [SMALL_STATE(909)] = 12763,
  [SMALL_STATE(910)] = 12767,
  [SMALL_STATE(911)] = 12771,
  [SMALL_STATE(912)] = 12775,
  [SMALL_STATE(913)] = 12779,
  [SMALL_STATE(914)] = 12783,
  [SMALL_STATE(915)] = 12787,
  [SMALL_STATE(916)] = 12791,
  [SMALL_STATE(917)] = 12795,
  [SMALL_STATE(918)] = 12799,
  [SMALL_STATE(919)] = 12803,
  [SMALL_STATE(920)] = 12807,
  [SMALL_STATE(921)] = 12811,
  [SMALL_STATE(922)] = 12815,
  [SMALL_STATE(923)] = 12819,
  [SMALL_STATE(924)] = 12823,
  [SMALL_STATE(925)] = 12827,
  [SMALL_STATE(926)] = 12831,
  [SMALL_STATE(927)] = 12835,
  [SMALL_STATE(928)] = 12839,
  [SMALL_STATE(929)] = 12843,
  [SMALL_STATE(930)] = 12847,
  [SMALL_STATE(931)] = 12851,
  [SMALL_STATE(932)] = 12855,
  [SMALL_STATE(933)] = 12859,
  [SMALL_STATE(934)] = 12863,
  [SMALL_STATE(935)] = 12867,
  [SMALL_STATE(936)] = 12871,
  [SMALL_STATE(937)] = 12875,
  [SMALL_STATE(938)] = 12879,
  [SMALL_STATE(939)] = 12883,
  [SMALL_STATE(940)] = 12887,
  [SMALL_STATE(941)] = 12891,
  [SMALL_STATE(942)] = 12895,
  [SMALL_STATE(943)] = 12899,
  [SMALL_STATE(944)] = 12903,
  [SMALL_STATE(945)] = 12907,
  [SMALL_STATE(946)] = 12911,
  [SMALL_STATE(947)] = 12915,
  [SMALL_STATE(948)] = 12919,
  [SMALL_STATE(949)] = 12923,
  [SMALL_STATE(950)] = 12927,
  [SMALL_STATE(951)] = 12931,
  [SMALL_STATE(952)] = 12935,
  [SMALL_STATE(953)] = 12939,
  [SMALL_STATE(954)] = 12943,
  [SMALL_STATE(955)] = 12947,
  [SMALL_STATE(956)] = 12951,
  [SMALL_STATE(957)] = 12955,
  [SMALL_STATE(958)] = 12959,
  [SMALL_STATE(959)] = 12963,
  [SMALL_STATE(960)] = 12967,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0, 0, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(351),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(361),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(394),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(856),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(514),
  [15] = {.entry = {.count = 1, .reusable = true}}, SHIFT(317),
  [17] = {.entry = {.count = 1, .reusable = true}}, SHIFT(327),
  [19] = {.entry = {.count = 1, .reusable = true}}, SHIFT(525),
  [21] = {.entry = {.count = 1, .reusable = true}}, SHIFT(959),
  [23] = {.entry = {.count = 1, .reusable = true}}, SHIFT(323),
  [25] = {.entry = {.count = 1, .reusable = true}}, SHIFT(322),
  [27] = {.entry = {.count = 1, .reusable = true}}, SHIFT(354),
  [29] = {.entry = {.count = 1, .reusable = true}}, SHIFT(316),
  [31] = {.entry = {.count = 1, .reusable = true}}, SHIFT(958),
  [33] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0),
  [35] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(351),
  [38] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(361),
  [41] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(394),
  [44] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(856),
  [47] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(514),
  [50] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(317),
  [53] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(327),
  [56] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(525),
  [59] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(959),
  [62] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(323),
  [65] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(322),
  [68] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(354),
  [71] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(316),
  [74] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(958),
  [77] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1, 0, 0),
  [79] = {.entry = {.count = 1, .reusable = false}}, SHIFT(68),
  [81] = {.entry = {.count = 1, .reusable = false}}, SHIFT(688),
  [83] = {.entry = {.count = 1, .reusable = false}}, SHIFT(687),
  [85] = {.entry = {.count = 1, .reusable = false}}, SHIFT(685),
  [87] = {.entry = {.count = 1, .reusable = false}}, SHIFT(682),
  [89] = {.entry = {.count = 1, .reusable = false}}, SHIFT(43),
  [91] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_function_call, 4, 0, 17),
  [93] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_function_call, 4, 0, 17),
  [95] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__decimal_literal, 1, 0, 0),
  [97] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_constant, 1, 0, 0),
  [99] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_table_name, 1, 0, 2),
  [101] = {.entry = {.count = 1, .reusable = true}}, SHIFT(910),
  [103] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bind_marker, 2, 0, 0),
  [105] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_table_name, 3, 0, 14),
  [107] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bind_marker, 1, 0, 0),
  [109] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_relation_element_repeat2, 2, 0, 0),
  [111] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_relation_element_repeat2, 2, 0, 0), SHIFT_REPEAT(658),
  [114] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_relation_element, 6, 0, 33),
  [116] = {.entry = {.count = 1, .reusable = true}}, SHIFT(658),
  [118] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_assignment_tuple, 3, 0, 0),
  [120] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_relation_element, 7, 0, 33),
  [122] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_relation_element, 5, 0, 33),
  [124] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_udt_name, 1, 0, 0),
  [126] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_keyspace_name, 1, 0, 5),
  [128] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_select_statement, 5, 0, 0),
  [130] = {.entry = {.count = 1, .reusable = true}}, SHIFT(781),
  [132] = {.entry = {.count = 1, .reusable = true}}, SHIFT(593),
  [134] = {.entry = {.count = 1, .reusable = true}}, SHIFT(345),
  [136] = {.entry = {.count = 1, .reusable = true}}, SHIFT(814),
  [138] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_relation_elements_repeat1, 2, 0, 0),
  [140] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_relation_elements_repeat1, 2, 0, 0), SHIFT_REPEAT(356),
  [143] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_select_statement, 3, 0, 0),
  [145] = {.entry = {.count = 1, .reusable = true}}, SHIFT(816),
  [147] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_select_statement, 4, 0, 0),
  [149] = {.entry = {.count = 1, .reusable = true}}, SHIFT(707),
  [151] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_relation_element, 8, 0, 33),
  [153] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_udt_name, 3, 0, 0),
  [155] = {.entry = {.count = 1, .reusable = true}}, SHIFT(62),
  [157] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
  [159] = {.entry = {.count = 1, .reusable = true}}, SHIFT(35),
  [161] = {.entry = {.count = 1, .reusable = true}}, SHIFT(793),
  [163] = {.entry = {.count = 1, .reusable = false}}, SHIFT(31),
  [165] = {.entry = {.count = 1, .reusable = false}}, SHIFT(30),
  [167] = {.entry = {.count = 1, .reusable = true}}, SHIFT(310),
  [169] = {.entry = {.count = 1, .reusable = true}}, SHIFT(302),
  [171] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_tuple_type, 5, 0, 0),
  [173] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_relation_element, 1, 0, 0),
  [175] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_relation_element, 3, 0, 0),
  [177] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_relation_contains, 3, 0, 1),
  [179] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_relation_element, 3, 0, 1),
  [181] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_relation_elements, 2, 0, 0),
  [183] = {.entry = {.count = 1, .reusable = true}}, SHIFT(356),
  [185] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cql_type, 1, 0, 0),
  [187] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_relation_element, 9, 0, 33),
  [189] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_relation_elements, 1, 0, 0),
  [191] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_frozen_type, 4, 0, 0),
  [193] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_relation_contains_key, 4, 0, 1),
  [195] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_user_defined_type, 1, 0, 0),
  [197] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_collection_type, 4, 0, 0),
  [199] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_tuple_type, 4, 0, 0),
  [201] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_native_type, 1, 0, 0),
  [203] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_relation_element, 5, 0, 1),
  [205] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_collection_type, 6, 0, 0),
  [207] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_data_type, 1, 0, 0),
  [209] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_select_statement, 6, 0, 0),
  [211] = {.entry = {.count = 1, .reusable = true}}, SHIFT(945),
  [213] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_from_spec, 2, 0, 0),
  [215] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type_name, 1, 0, 10),
  [217] = {.entry = {.count = 1, .reusable = true}}, SHIFT(766),
  [219] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_resource, 2, 0, 27),
  [221] = {.entry = {.count = 1, .reusable = true}}, SHIFT(947),
  [223] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_resource, 1, 0, 2),
  [225] = {.entry = {.count = 1, .reusable = true}}, SHIFT(861),
  [227] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_function_name, 1, 0, 6),
  [229] = {.entry = {.count = 1, .reusable = true}}, SHIFT(783),
  [231] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_where_spec, 2, 0, 0),
  [233] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_order_spec, 3, 0, 0),
  [235] = {.entry = {.count = 1, .reusable = true}}, SHIFT(143),
  [237] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_resource, 2, 0, 28),
  [239] = {.entry = {.count = 1, .reusable = true}}, SHIFT(951),
  [241] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_resource, 2, 0, 0),
  [243] = {.entry = {.count = 1, .reusable = false}}, SHIFT(949),
  [245] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_resource, 3, 0, 14),
  [247] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_resource, 2, 0, 29),
  [249] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_resource, 5, 0, 45),
  [251] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_resource, 2, 0, 3),
  [253] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_insert_statement, 5, 0, 0),
  [255] = {.entry = {.count = 1, .reusable = true}}, SHIFT(802),
  [257] = {.entry = {.count = 1, .reusable = true}}, SHIFT(578),
  [259] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_function_name, 3, 0, 21),
  [261] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_create_function_repeat1, 2, 0, 0),
  [263] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_create_function_repeat1, 2, 0, 0), SHIFT_REPEAT(575),
  [266] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_materialized_view_name, 1, 0, 15),
  [268] = {.entry = {.count = 1, .reusable = true}}, SHIFT(673),
  [270] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_select_statement, 7, 0, 0),
  [272] = {.entry = {.count = 1, .reusable = true}}, SHIFT(735),
  [274] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_user_with, 2, 0, 0),
  [276] = {.entry = {.count = 1, .reusable = true}}, SHIFT(225),
  [278] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_clustering_key_list_repeat1, 2, 0, 0),
  [280] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_clustering_key_list_repeat1, 2, 0, 0), SHIFT_REPEAT(750),
  [283] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_insert_statement, 6, 0, 0),
  [285] = {.entry = {.count = 1, .reusable = true}}, SHIFT(743),
  [287] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_resource, 4, 0, 39),
  [289] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type_name, 3, 0, 24),
  [291] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_privilege, 1, 0, 0),
  [293] = {.entry = {.count = 1, .reusable = true}}, SHIFT(153),
  [295] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_resource, 4, 0, 38),
  [297] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_init_cond_hash, 4, 0, 0),
  [299] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_alter_table_add, 2, 0, 0),
  [301] = {.entry = {.count = 1, .reusable = true}}, SHIFT(575),
  [303] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_table_options, 2, 0, 0),
  [305] = {.entry = {.count = 1, .reusable = true}}, SHIFT(349),
  [307] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_role_with_repeat1, 2, 0, 0),
  [309] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_role_with_repeat1, 2, 0, 0), SHIFT_REPEAT(360),
  [312] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_create_materialized_view, 14, 0, 0),
  [314] = {.entry = {.count = 1, .reusable = true}}, SHIFT(336),
  [316] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_init_cond_definition, 1, 0, 0),
  [318] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_insert_values_spec, 4, 0, 0),
  [320] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_delete_statement, 4, 0, 0),
  [322] = {.entry = {.count = 1, .reusable = true}}, SHIFT(337),
  [324] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_alter_table_drop_columns, 3, 0, 0),
  [326] = {.entry = {.count = 1, .reusable = true}}, SHIFT(750),
  [328] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_insert_statement, 8, 0, 0),
  [330] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_alter_type_rename, 2, 0, 0),
  [332] = {.entry = {.count = 1, .reusable = true}}, SHIFT(531),
  [334] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_create_role, 3, 0, 0),
  [336] = {.entry = {.count = 1, .reusable = true}}, SHIFT(369),
  [338] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_aggregate_name, 1, 0, 8),
  [340] = {.entry = {.count = 1, .reusable = true}}, SHIFT(773),
  [342] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_init_cond_hash, 3, 0, 0),
  [344] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_alter_type_add, 2, 0, 0),
  [346] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_init_cond_nested_list, 3, 0, 0),
  [348] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_insert_statement, 9, 0, 0),
  [350] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_insert_values_spec, 2, 0, 0),
  [352] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_role_with, 2, 0, 0),
  [354] = {.entry = {.count = 1, .reusable = true}}, SHIFT(360),
  [356] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_alter_type_add, 3, 0, 0),
  [358] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_alter_type_rename_repeat1, 2, 0, 0),
  [360] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_alter_type_rename_repeat1, 2, 0, 0), SHIFT_REPEAT(531),
  [363] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_using_ttl_timestamp, 3, 0, 20),
  [365] = {.entry = {.count = 1, .reusable = true}}, SHIFT(943),
  [367] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_using_ttl_timestamp, 3, 0, 26),
  [369] = {.entry = {.count = 1, .reusable = true}}, SHIFT(944),
  [371] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_alter_table_add, 3, 0, 0),
  [373] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_alter_type_rename, 3, 0, 0),
  [375] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_delete_statement, 6, 0, 0),
  [377] = {.entry = {.count = 1, .reusable = true}}, SHIFT(333),
  [379] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_init_cond_list, 4, 0, 0),
  [381] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_init_cond_list, 3, 0, 0),
  [383] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_update, 6, 0, 0),
  [385] = {.entry = {.count = 1, .reusable = true}}, SHIFT(330),
  [387] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_typed_name, 2, 0, 1),
  [389] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_delete_statement, 3, 0, 0),
  [391] = {.entry = {.count = 1, .reusable = true}}, SHIFT(341),
  [393] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_delete_statement, 5, 0, 0),
  [395] = {.entry = {.count = 1, .reusable = true}}, SHIFT(335),
  [397] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_update, 5, 0, 0),
  [399] = {.entry = {.count = 1, .reusable = true}}, SHIFT(340),
  [401] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_primary_key_element, 5, 0, 0),
  [403] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_list_roles, 2, 0, 0),
  [405] = {.entry = {.count = 1, .reusable = true}}, SHIFT(836),
  [407] = {.entry = {.count = 1, .reusable = true}}, SHIFT(198),
  [409] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_order_spec, 4, 0, 0),
  [411] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_list_permissions, 2, 0, 0),
  [413] = {.entry = {.count = 1, .reusable = true}}, SHIFT(348),
  [415] = {.entry = {.count = 1, .reusable = true}}, SHIFT(835),
  [417] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_alter_table_drop_columns, 2, 0, 0),
  [419] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_user_password, 2, 0, 31),
  [421] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_table_options, 1, 0, 0),
  [423] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_materialized_view_name, 3, 0, 30),
  [425] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_init_cond_nested_list, 4, 0, 0),
  [427] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_create_materialized_view, 11, 0, 0),
  [429] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_update, 4, 0, 0),
  [431] = {.entry = {.count = 1, .reusable = true}}, SHIFT(331),
  [433] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_create_role, 6, 0, 0),
  [435] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_privilege, 2, 0, 0),
  [437] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_role_with, 3, 0, 0),
  [439] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_alter_materialized_view, 4, 0, 0),
  [441] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_create_table, 6, 0, 0),
  [443] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_table_options_repeat1, 2, 0, 0),
  [445] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_table_options_repeat1, 2, 0, 0), SHIFT_REPEAT(349),
  [448] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_alter_role, 3, 0, 0),
  [450] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_create_table, 9, 0, 0),
  [452] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_index_name, 1, 0, 4),
  [454] = {.entry = {.count = 1, .reusable = true}}, SHIFT(760),
  [456] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_list_roles, 4, 0, 16),
  [458] = {.entry = {.count = 1, .reusable = true}}, SHIFT(253),
  [460] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_list_permissions, 4, 0, 0),
  [462] = {.entry = {.count = 1, .reusable = true}}, SHIFT(768),
  [464] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_clustering_order, 7, 0, 51),
  [466] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_table_option_item, 3, 0, 0),
  [468] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_option_hash, 3, 0, 0),
  [470] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_create_keyspace, 7, 0, 0),
  [472] = {.entry = {.count = 1, .reusable = true}}, SHIFT(666),
  [474] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_alter_keyspace, 7, 0, 0),
  [476] = {.entry = {.count = 1, .reusable = true}}, SHIFT(665),
  [478] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_limit_spec, 2, 0, 18),
  [480] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_alter_type_rename_item, 3, 0, 41),
  [482] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_select_statement, 8, 0, 0),
  [484] = {.entry = {.count = 1, .reusable = true}}, SHIFT(709),
  [486] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_using_ttl_timestamp, 6, 0, 43),
  [488] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_using_ttl_timestamp, 6, 0, 42),
  [490] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_option_hash, 4, 0, 0),
  [492] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_role_with_option, 3, 0, 36),
  [494] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_user_name, 1, 0, 11),
  [496] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_role_with_option, 3, 0, 34),
  [498] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_role_with_option, 3, 0, 35),
  [500] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_aggregate_name, 3, 0, 22),
  [502] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_clustering_order, 8, 0, 51),
  [504] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_replication_list, 4, 0, 0),
  [506] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_clustering_order, 6, 0, 51),
  [508] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_create_keyspace, 10, 0, 0),
  [510] = {.entry = {.count = 1, .reusable = true}}, SHIFT(589),
  [512] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_table_option_value, 1, 0, 0),
  [514] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_replication_list, 3, 0, 0),
  [516] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_role_with_option, 3, 0, 0),
  [518] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_role_name, 1, 0, 7),
  [520] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_compact_storage, 2, 0, 0),
  [522] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_drop_table, 3, 0, 0),
  [524] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_list_roles, 3, 0, 0),
  [526] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_create_aggregate, 19, 0, 66),
  [528] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_alter_table_drop_compact_storage, 3, 0, 0),
  [530] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_durable_writes, 3, 0, 52),
  [532] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_revoke, 6, 0, 32),
  [534] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_create_index, 11, 0, 0),
  [536] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_grant, 6, 0, 32),
  [538] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_create_materialized_view, 12, 0, 0),
  [540] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_create_trigger, 8, 0, 0),
  [542] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_create_function, 19, 0, 65),
  [544] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_insert_statement, 10, 0, 0),
  [546] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_list_permissions, 6, 0, 32),
  [548] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_drop_index, 3, 0, 0),
  [550] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_drop_keyspace, 3, 0, 0),
  [552] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_create_index, 8, 0, 0),
  [554] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_trigger_class, 1, 0, 0),
  [556] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_create_keyspace, 12, 0, 0),
  [558] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_drop_function, 3, 0, 0),
  [560] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_create_trigger, 5, 0, 0),
  [562] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_create_function, 14, 0, 56),
  [564] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_drop_materialized_view, 6, 0, 0),
  [566] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_create_type, 10, 0, 0),
  [568] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_create_function, 18, 0, 64),
  [570] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_user_with, 3, 0, 0),
  [572] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_user_super_user, 1, 0, 0),
  [574] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__statement, 1, 0, 0),
  [576] = {.entry = {.count = 1, .reusable = true}}, SHIFT(303),
  [578] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_create_type, 6, 0, 0),
  [580] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_delete_statement, 7, 0, 0),
  [582] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_create_index, 10, 0, 0),
  [584] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_create_table, 7, 0, 0),
  [586] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_create_role, 4, 0, 0),
  [588] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_create_table, 10, 0, 0),
  [590] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_create_index, 7, 0, 0),
  [592] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_create_aggregate, 17, 0, 62),
  [594] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_select_statement, 10, 0, 0),
  [596] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_alter_keyspace, 9, 0, 0),
  [598] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_truncate, 2, 0, 0),
  [600] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_create_role, 7, 0, 0),
  [602] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_create_user, 4, 0, 0),
  [604] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_create_function, 17, 0, 61),
  [606] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_create_type, 7, 0, 0),
  [608] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_create_aggregate, 16, 0, 60),
  [610] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_create_user, 7, 0, 0),
  [612] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_create_aggregate, 14, 0, 57),
  [614] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_truncate, 3, 0, 0),
  [616] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_drop_materialized_view, 4, 0, 0),
  [618] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_create_type, 9, 0, 0),
  [620] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_drop_trigger, 7, 0, 0),
  [622] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_update, 7, 0, 0),
  [624] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_list_roles, 5, 0, 16),
  [626] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_use, 2, 0, 3),
  [628] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_create_keyspace, 9, 0, 0),
  [630] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_drop_role, 3, 0, 0),
  [632] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_alter_materialized_view, 5, 0, 0),
  [634] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_create_function, 15, 0, 58),
  [636] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_apply_batch, 2, 0, 0),
  [638] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_insert_statement, 7, 0, 0),
  [640] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_with_element, 2, 0, 0),
  [642] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_drop_table, 5, 0, 0),
  [644] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_create_function, 13, 0, 55),
  [646] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_create_function, 16, 0, 59),
  [648] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_alter_table_operation, 1, 0, 0),
  [650] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_alter_table, 4, 0, 0),
  [652] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_create_function, 12, 0, 54),
  [654] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_alter_role, 4, 0, 0),
  [656] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_if_spec, 2, 0, 0),
  [658] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_alter_table_rename, 4, 0, 40),
  [660] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_alter_type_alter_type, 4, 0, 33),
  [662] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_create_materialized_view, 15, 0, 0),
  [664] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_alter_type, 4, 0, 0),
  [666] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_alter_type_operation, 1, 0, 0),
  [668] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_alter_user, 4, 0, 0),
  [670] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_list_permissions, 4, 0, 16),
  [672] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_drop_index, 5, 0, 0),
  [674] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_select_statement, 9, 0, 0),
  [676] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_update, 8, 0, 0),
  [678] = {.entry = {.count = 1, .reusable = false}}, SHIFT(537),
  [680] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_delete_statement, 8, 0, 0),
  [682] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_drop_aggregate, 3, 0, 0),
  [684] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_drop_user, 3, 0, 0),
  [686] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_drop_type, 3, 0, 0),
  [688] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_drop_user, 5, 0, 0),
  [690] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_index_name, 3, 0, 25),
  [692] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_drop_type, 5, 0, 0),
  [694] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_drop_trigger, 5, 0, 0),
  [696] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_drop_aggregate, 5, 0, 0),
  [698] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_drop_role, 5, 0, 0),
  [700] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_drop_function, 5, 0, 0),
  [702] = {.entry = {.count = 1, .reusable = false}}, SHIFT(797),
  [704] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_drop_keyspace, 5, 0, 0),
  [706] = {.entry = {.count = 1, .reusable = true}}, SHIFT(311),
  [708] = {.entry = {.count = 1, .reusable = true}}, SHIFT(364),
  [710] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__statement, 2, 0, 0),
  [712] = {.entry = {.count = 1, .reusable = true}}, SHIFT(817),
  [714] = {.entry = {.count = 1, .reusable = false}}, SHIFT(388),
  [716] = {.entry = {.count = 1, .reusable = true}}, SHIFT(326),
  [718] = {.entry = {.count = 1, .reusable = false}}, SHIFT(915),
  [720] = {.entry = {.count = 1, .reusable = false}}, SHIFT(421),
  [722] = {.entry = {.count = 1, .reusable = true}}, SHIFT(318),
  [724] = {.entry = {.count = 1, .reusable = true}}, SHIFT(117),
  [726] = {.entry = {.count = 1, .reusable = true}}, SHIFT(103),
  [728] = {.entry = {.count = 1, .reusable = true}}, SHIFT(142),
  [730] = {.entry = {.count = 1, .reusable = true}}, SHIFT(459),
  [732] = {.entry = {.count = 1, .reusable = true}}, SHIFT(371),
  [734] = {.entry = {.count = 1, .reusable = true}}, SHIFT(455),
  [736] = {.entry = {.count = 1, .reusable = true}}, SHIFT(454),
  [738] = {.entry = {.count = 1, .reusable = true}}, SHIFT(453),
  [740] = {.entry = {.count = 1, .reusable = true}}, SHIFT(452),
  [742] = {.entry = {.count = 1, .reusable = true}}, SHIFT(942),
  [744] = {.entry = {.count = 1, .reusable = true}}, SHIFT(450),
  [746] = {.entry = {.count = 1, .reusable = true}}, SHIFT(446),
  [748] = {.entry = {.count = 1, .reusable = true}}, SHIFT(444),
  [750] = {.entry = {.count = 1, .reusable = true}}, SHIFT(941),
  [752] = {.entry = {.count = 1, .reusable = true}}, SHIFT(645),
  [754] = {.entry = {.count = 1, .reusable = true}}, SHIFT(646),
  [756] = {.entry = {.count = 1, .reusable = true}}, SHIFT(718),
  [758] = {.entry = {.count = 1, .reusable = true}}, SHIFT(306),
  [760] = {.entry = {.count = 1, .reusable = false}}, SHIFT(309),
  [762] = {.entry = {.count = 1, .reusable = true}}, SHIFT(309),
  [764] = {.entry = {.count = 1, .reusable = true}}, SHIFT(703),
  [766] = {.entry = {.count = 1, .reusable = true}}, SHIFT(315),
  [768] = {.entry = {.count = 1, .reusable = true}}, SHIFT(862),
  [770] = {.entry = {.count = 1, .reusable = true}}, SHIFT(440),
  [772] = {.entry = {.count = 1, .reusable = true}}, SHIFT(435),
  [774] = {.entry = {.count = 1, .reusable = true}}, SHIFT(434),
  [776] = {.entry = {.count = 1, .reusable = true}}, SHIFT(433),
  [778] = {.entry = {.count = 1, .reusable = true}}, SHIFT(431),
  [780] = {.entry = {.count = 1, .reusable = true}}, SHIFT(428),
  [782] = {.entry = {.count = 1, .reusable = true}}, SHIFT(940),
  [784] = {.entry = {.count = 1, .reusable = true}}, SHIFT(423),
  [786] = {.entry = {.count = 1, .reusable = true}}, SHIFT(419),
  [788] = {.entry = {.count = 1, .reusable = true}}, SHIFT(418),
  [790] = {.entry = {.count = 1, .reusable = true}}, SHIFT(811),
  [792] = {.entry = {.count = 1, .reusable = false}}, SHIFT(282),
  [794] = {.entry = {.count = 1, .reusable = false}}, SHIFT(329),
  [796] = {.entry = {.count = 1, .reusable = false}}, SHIFT(208),
  [798] = {.entry = {.count = 1, .reusable = false}}, SHIFT(821),
  [800] = {.entry = {.count = 1, .reusable = false}}, SHIFT(822),
  [802] = {.entry = {.count = 1, .reusable = false}}, SHIFT(823),
  [804] = {.entry = {.count = 1, .reusable = false}}, SHIFT(825),
  [806] = {.entry = {.count = 1, .reusable = false}}, SHIFT(284),
  [808] = {.entry = {.count = 1, .reusable = false}}, SHIFT(228),
  [810] = {.entry = {.count = 1, .reusable = false}}, SHIFT(753),
  [812] = {.entry = {.count = 1, .reusable = false}}, SHIFT(754),
  [814] = {.entry = {.count = 1, .reusable = false}}, SHIFT(756),
  [816] = {.entry = {.count = 1, .reusable = false}}, SHIFT(245),
  [818] = {.entry = {.count = 1, .reusable = false}}, SHIFT(252),
  [820] = {.entry = {.count = 1, .reusable = false}}, SHIFT(277),
  [822] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [824] = {.entry = {.count = 1, .reusable = false}}, SHIFT(734),
  [826] = {.entry = {.count = 1, .reusable = false}}, SHIFT(412),
  [828] = {.entry = {.count = 1, .reusable = false}}, SHIFT(732),
  [830] = {.entry = {.count = 1, .reusable = false}}, SHIFT(730),
  [832] = {.entry = {.count = 1, .reusable = false}}, SHIFT(729),
  [834] = {.entry = {.count = 1, .reusable = false}}, SHIFT(79),
  [836] = {.entry = {.count = 1, .reusable = true}}, SHIFT(329),
  [838] = {.entry = {.count = 1, .reusable = false}}, SHIFT(644),
  [840] = {.entry = {.count = 1, .reusable = true}}, SHIFT(644),
  [842] = {.entry = {.count = 1, .reusable = true}}, SHIFT(722),
  [844] = {.entry = {.count = 1, .reusable = true}}, SHIFT(715),
  [846] = {.entry = {.count = 1, .reusable = true}}, SHIFT(654),
  [848] = {.entry = {.count = 1, .reusable = true}}, SHIFT(655),
  [850] = {.entry = {.count = 1, .reusable = true}}, SHIFT(324),
  [852] = {.entry = {.count = 1, .reusable = false}}, SHIFT(355),
  [854] = {.entry = {.count = 1, .reusable = false}}, SHIFT(374),
  [856] = {.entry = {.count = 1, .reusable = true}}, SHIFT(481),
  [858] = {.entry = {.count = 1, .reusable = false}}, SHIFT(389),
  [860] = {.entry = {.count = 1, .reusable = false}}, SHIFT(543),
  [862] = {.entry = {.count = 1, .reusable = true}}, SHIFT(543),
  [864] = {.entry = {.count = 1, .reusable = true}}, SHIFT(934),
  [866] = {.entry = {.count = 1, .reusable = false}}, SHIFT(296),
  [868] = {.entry = {.count = 1, .reusable = true}}, SHIFT(296),
  [870] = {.entry = {.count = 1, .reusable = true}}, SHIFT(544),
  [872] = {.entry = {.count = 1, .reusable = true}}, SHIFT(545),
  [874] = {.entry = {.count = 1, .reusable = true}}, SHIFT(547),
  [876] = {.entry = {.count = 1, .reusable = true}}, SHIFT(930),
  [878] = {.entry = {.count = 1, .reusable = true}}, SHIFT(548),
  [880] = {.entry = {.count = 1, .reusable = true}}, SHIFT(549),
  [882] = {.entry = {.count = 1, .reusable = false}}, SHIFT(363),
  [884] = {.entry = {.count = 1, .reusable = true}}, SHIFT(810),
  [886] = {.entry = {.count = 1, .reusable = true}}, SHIFT(186),
  [888] = {.entry = {.count = 1, .reusable = true}}, SHIFT(507),
  [890] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_assignment_map, 5, 0, 0),
  [892] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_assignment_list, 3, 0, 0),
  [894] = {.entry = {.count = 1, .reusable = true}}, SHIFT(694),
  [896] = {.entry = {.count = 1, .reusable = true}}, SHIFT(691),
  [898] = {.entry = {.count = 1, .reusable = true}}, SHIFT(690),
  [900] = {.entry = {.count = 1, .reusable = true}}, SHIFT(689),
  [902] = {.entry = {.count = 1, .reusable = false}}, SHIFT(528),
  [904] = {.entry = {.count = 1, .reusable = false}}, SHIFT(476),
  [906] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_begin_batch, 2, 0, 0),
  [908] = {.entry = {.count = 1, .reusable = true}}, SHIFT(918),
  [910] = {.entry = {.count = 1, .reusable = true}}, SHIFT(389),
  [912] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_assignment_set, 2, 0, 0),
  [914] = {.entry = {.count = 1, .reusable = false}}, SHIFT(188),
  [916] = {.entry = {.count = 1, .reusable = true}}, SHIFT(587),
  [918] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_assignment_set, 3, 0, 0),
  [920] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_assignment_set, 4, 0, 0),
  [922] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_assignment_map, 6, 0, 0),
  [924] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_begin_batch, 3, 0, 0),
  [926] = {.entry = {.count = 1, .reusable = true}}, SHIFT(903),
  [928] = {.entry = {.count = 1, .reusable = false}}, SHIFT(902),
  [930] = {.entry = {.count = 1, .reusable = false}}, SHIFT(562),
  [932] = {.entry = {.count = 1, .reusable = false}}, SHIFT(903),
  [934] = {.entry = {.count = 1, .reusable = true}}, SHIFT(616),
  [936] = {.entry = {.count = 1, .reusable = true}}, SHIFT(614),
  [938] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_assignment_list, 4, 0, 0),
  [940] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_assignment_element, 3, 0, 0),
  [942] = {.entry = {.count = 1, .reusable = true}}, SHIFT(775),
  [944] = {.entry = {.count = 1, .reusable = true}}, SHIFT(782),
  [946] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_column_list, 2, 0, 1),
  [948] = {.entry = {.count = 1, .reusable = false}}, SHIFT(597),
  [950] = {.entry = {.count = 1, .reusable = true}}, SHIFT(350),
  [952] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_materialized_view_where, 3, 0, 0),
  [954] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_assignment_set_repeat1, 2, 0, 0), SHIFT_REPEAT(305),
  [957] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_assignment_set_repeat1, 2, 0, 0),
  [959] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_relation_element_repeat1, 2, 0, 0), SHIFT_REPEAT(782),
  [962] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_relation_element_repeat1, 2, 0, 0),
  [964] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_column_definition, 2, 0, 1),
  [966] = {.entry = {.count = 1, .reusable = true}}, SHIFT(916),
  [968] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_clustering_order_repeat1, 2, 0, 33),
  [970] = {.entry = {.count = 1, .reusable = true}}, SHIFT(571),
  [972] = {.entry = {.count = 1, .reusable = false}}, SHIFT(905),
  [974] = {.entry = {.count = 1, .reusable = false}}, SHIFT(5),
  [976] = {.entry = {.count = 1, .reusable = true}}, SHIFT(314),
  [978] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_function_args, 1, 0, 0),
  [980] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_select_element, 1, 0, 1),
  [982] = {.entry = {.count = 1, .reusable = true}}, SHIFT(923),
  [984] = {.entry = {.count = 1, .reusable = true}}, SHIFT(437),
  [986] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_materialized_view_where, 2, 0, 0),
  [988] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_using_timestamp_spec, 3, 0, 20),
  [990] = {.entry = {.count = 1, .reusable = true}}, SHIFT(948),
  [992] = {.entry = {.count = 1, .reusable = true}}, SHIFT(362),
  [994] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_column_list, 1, 0, 1),
  [996] = {.entry = {.count = 1, .reusable = true}}, SHIFT(636),
  [998] = {.entry = {.count = 1, .reusable = true}}, SHIFT(176),
  [1000] = {.entry = {.count = 1, .reusable = true}}, SHIFT(842),
  [1002] = {.entry = {.count = 1, .reusable = true}}, SHIFT(844),
  [1004] = {.entry = {.count = 1, .reusable = true}}, SHIFT(313),
  [1006] = {.entry = {.count = 1, .reusable = true}}, SHIFT(121),
  [1008] = {.entry = {.count = 1, .reusable = true}}, SHIFT(812),
  [1010] = {.entry = {.count = 1, .reusable = true}}, SHIFT(542),
  [1012] = {.entry = {.count = 1, .reusable = true}}, SHIFT(119),
  [1014] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_assignment_map_repeat1, 2, 0, 0), SHIFT_REPEAT(319),
  [1017] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_assignment_map_repeat1, 2, 0, 0),
  [1019] = {.entry = {.count = 1, .reusable = true}}, SHIFT(404),
  [1021] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_select_elements, 2, 0, 0),
  [1023] = {.entry = {.count = 1, .reusable = true}}, SHIFT(67),
  [1025] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_expression_list_repeat1, 2, 0, 0), SHIFT_REPEAT(73),
  [1028] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_expression_list_repeat1, 2, 0, 0),
  [1030] = {.entry = {.count = 1, .reusable = true}}, SHIFT(522),
  [1032] = {.entry = {.count = 1, .reusable = true}}, SHIFT(612),
  [1034] = {.entry = {.count = 1, .reusable = true}}, SHIFT(321),
  [1036] = {.entry = {.count = 1, .reusable = true}}, SHIFT(134),
  [1038] = {.entry = {.count = 1, .reusable = true}}, SHIFT(640),
  [1040] = {.entry = {.count = 1, .reusable = true}}, SHIFT(185),
  [1042] = {.entry = {.count = 1, .reusable = true}}, SHIFT(149),
  [1044] = {.entry = {.count = 1, .reusable = true}}, SHIFT(84),
  [1046] = {.entry = {.count = 1, .reusable = true}}, SHIFT(86),
  [1048] = {.entry = {.count = 1, .reusable = true}}, SHIFT(491),
  [1050] = {.entry = {.count = 1, .reusable = true}}, SHIFT(328),
  [1052] = {.entry = {.count = 1, .reusable = true}}, SHIFT(701),
  [1054] = {.entry = {.count = 1, .reusable = true}}, SHIFT(305),
  [1056] = {.entry = {.count = 1, .reusable = true}}, SHIFT(366),
  [1058] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__value_marker, 1, 0, 0),
  [1060] = {.entry = {.count = 1, .reusable = true}}, SHIFT(308),
  [1062] = {.entry = {.count = 1, .reusable = false}}, SHIFT(845),
  [1064] = {.entry = {.count = 1, .reusable = false}}, SHIFT(179),
  [1066] = {.entry = {.count = 1, .reusable = false}}, SHIFT(846),
  [1068] = {.entry = {.count = 1, .reusable = false}}, SHIFT(77),
  [1070] = {.entry = {.count = 1, .reusable = true}}, SHIFT(441),
  [1072] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_update_assignments, 2, 0, 0),
  [1074] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_function_args_repeat1, 2, 0, 0),
  [1076] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_function_args_repeat1, 2, 0, 0), SHIFT_REPEAT(314),
  [1079] = {.entry = {.count = 1, .reusable = false}}, SHIFT(848),
  [1081] = {.entry = {.count = 1, .reusable = false}}, SHIFT(521),
  [1083] = {.entry = {.count = 1, .reusable = true}}, SHIFT(359),
  [1085] = {.entry = {.count = 1, .reusable = true}}, SHIFT(346),
  [1087] = {.entry = {.count = 1, .reusable = true}}, SHIFT(105),
  [1089] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [1091] = {.entry = {.count = 1, .reusable = true}}, SHIFT(52),
  [1093] = {.entry = {.count = 1, .reusable = false}}, SHIFT(850),
  [1095] = {.entry = {.count = 1, .reusable = false}}, SHIFT(118),
  [1097] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_tuple_type_repeat1, 2, 0, 0), SHIFT_REPEAT(28),
  [1100] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_tuple_type_repeat1, 2, 0, 0),
  [1102] = {.entry = {.count = 1, .reusable = true}}, SHIFT(222),
  [1104] = {.entry = {.count = 1, .reusable = false}}, SHIFT(852),
  [1106] = {.entry = {.count = 1, .reusable = false}}, SHIFT(191),
  [1108] = {.entry = {.count = 1, .reusable = true}}, SHIFT(512),
  [1110] = {.entry = {.count = 1, .reusable = false}}, SHIFT(855),
  [1112] = {.entry = {.count = 1, .reusable = false}}, SHIFT(80),
  [1114] = {.entry = {.count = 1, .reusable = false}}, SHIFT(834),
  [1116] = {.entry = {.count = 1, .reusable = false}}, SHIFT(193),
  [1118] = {.entry = {.count = 1, .reusable = false}}, SHIFT(859),
  [1120] = {.entry = {.count = 1, .reusable = false}}, SHIFT(160),
  [1122] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [1124] = {.entry = {.count = 1, .reusable = true}}, SHIFT(635),
  [1126] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_update_assignments, 3, 0, 0),
  [1128] = {.entry = {.count = 1, .reusable = false}}, SHIFT(863),
  [1130] = {.entry = {.count = 1, .reusable = false}}, SHIFT(32),
  [1132] = {.entry = {.count = 1, .reusable = true}}, SHIFT(184),
  [1134] = {.entry = {.count = 1, .reusable = true}}, SHIFT(319),
  [1136] = {.entry = {.count = 1, .reusable = true}}, SHIFT(358),
  [1138] = {.entry = {.count = 1, .reusable = false}}, SHIFT(866),
  [1140] = {.entry = {.count = 1, .reusable = true}}, SHIFT(556),
  [1142] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_delete_column_list, 2, 0, 0),
  [1144] = {.entry = {.count = 1, .reusable = false}}, SHIFT(871),
  [1146] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_function_args, 2, 0, 0),
  [1148] = {.entry = {.count = 1, .reusable = true}}, SHIFT(396),
  [1150] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_column_definition_list, 2, 0, 0),
  [1152] = {.entry = {.count = 1, .reusable = true}}, SHIFT(66),
  [1154] = {.entry = {.count = 1, .reusable = false}}, SHIFT(875),
  [1156] = {.entry = {.count = 1, .reusable = false}}, SHIFT(741),
  [1158] = {.entry = {.count = 1, .reusable = false}}, SHIFT(882),
  [1160] = {.entry = {.count = 1, .reusable = false}}, SHIFT(885),
  [1162] = {.entry = {.count = 1, .reusable = false}}, SHIFT(888),
  [1164] = {.entry = {.count = 1, .reusable = false}}, SHIFT(898),
  [1166] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_clustering_order_repeat1, 2, 0, 0), SHIFT_REPEAT(810),
  [1169] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_clustering_order_repeat1, 2, 0, 0),
  [1171] = {.entry = {.count = 1, .reusable = false}}, SHIFT(755),
  [1173] = {.entry = {.count = 1, .reusable = false}}, SHIFT(95),
  [1175] = {.entry = {.count = 1, .reusable = false}}, SHIFT(726),
  [1177] = {.entry = {.count = 1, .reusable = false}}, SHIFT(908),
  [1179] = {.entry = {.count = 1, .reusable = true}}, SHIFT(135),
  [1181] = {.entry = {.count = 1, .reusable = true}}, SHIFT(367),
  [1183] = {.entry = {.count = 1, .reusable = true}}, SHIFT(352),
  [1185] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_partition_key_list, 2, 0, 0),
  [1187] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_init_cond_list_repeat1, 2, 0, 0), SHIFT_REPEAT(321),
  [1190] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_init_cond_list_repeat1, 2, 0, 0),
  [1192] = {.entry = {.count = 1, .reusable = true}}, SHIFT(398),
  [1194] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_delete_column_list, 1, 0, 0),
  [1196] = {.entry = {.count = 1, .reusable = true}}, SHIFT(49),
  [1198] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_column_definition_list_repeat1, 2, 0, 0), SHIFT_REPEAT(656),
  [1201] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_column_definition_list_repeat1, 2, 0, 0),
  [1203] = {.entry = {.count = 1, .reusable = true}}, SHIFT(375),
  [1205] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [1207] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_delete_column_item, 1, 0, 1),
  [1209] = {.entry = {.count = 1, .reusable = true}}, SHIFT(400),
  [1211] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_init_cond_nested_list_repeat1, 2, 0, 0), SHIFT_REPEAT(313),
  [1214] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_init_cond_nested_list_repeat1, 2, 0, 0),
  [1216] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_select_element, 1, 0, 0),
  [1218] = {.entry = {.count = 1, .reusable = true}}, SHIFT(919),
  [1220] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_clustering_key_list, 1, 0, 0),
  [1222] = {.entry = {.count = 1, .reusable = true}}, SHIFT(73),
  [1224] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_expression_list, 1, 0, 0),
  [1226] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_select_elements, 1, 0, 0),
  [1228] = {.entry = {.count = 1, .reusable = true}}, SHIFT(387),
  [1230] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_column_definition_list, 1, 0, 0),
  [1232] = {.entry = {.count = 1, .reusable = true}}, SHIFT(227),
  [1234] = {.entry = {.count = 1, .reusable = true}}, SHIFT(413),
  [1236] = {.entry = {.count = 1, .reusable = true}}, SHIFT(373),
  [1238] = {.entry = {.count = 1, .reusable = true}}, SHIFT(927),
  [1240] = {.entry = {.count = 1, .reusable = true}}, SHIFT(553),
  [1242] = {.entry = {.count = 1, .reusable = true}}, SHIFT(249),
  [1244] = {.entry = {.count = 1, .reusable = true}}, SHIFT(503),
  [1246] = {.entry = {.count = 1, .reusable = true}}, SHIFT(242),
  [1248] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_materialized_view_where_repeat1, 2, 0, 0), SHIFT_REPEAT(559),
  [1251] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_materialized_view_where_repeat1, 2, 0, 0),
  [1253] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_replication_list_repeat1, 2, 0, 0), SHIFT_REPEAT(640),
  [1256] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_replication_list_repeat1, 2, 0, 0),
  [1258] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_option_hash_repeat1, 2, 0, 0), SHIFT_REPEAT(636),
  [1261] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_option_hash_repeat1, 2, 0, 0),
  [1263] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_relation_element_repeat1, 2, 0, 33),
  [1265] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_init_cond_hash_repeat1, 2, 0, 0), SHIFT_REPEAT(542),
  [1268] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_init_cond_hash_repeat1, 2, 0, 0),
  [1270] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_begin_batch, 4, 0, 0),
  [1272] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_expression_list, 2, 0, 0),
  [1274] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_delete_column_list_repeat1, 2, 0, 0), SHIFT_REPEAT(556),
  [1277] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_delete_column_list_repeat1, 2, 0, 0),
  [1279] = {.entry = {.count = 1, .reusable = true}}, SHIFT(471),
  [1281] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_materialized_view_where, 4, 0, 0),
  [1283] = {.entry = {.count = 1, .reusable = true}}, SHIFT(189),
  [1285] = {.entry = {.count = 1, .reusable = true}}, SHIFT(466),
  [1287] = {.entry = {.count = 1, .reusable = true}}, SHIFT(368),
  [1289] = {.entry = {.count = 1, .reusable = true}}, SHIFT(164),
  [1291] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_update_assignments_repeat1, 2, 0, 0), SHIFT_REPEAT(441),
  [1294] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_update_assignments_repeat1, 2, 0, 0),
  [1296] = {.entry = {.count = 1, .reusable = true}}, SHIFT(59),
  [1298] = {.entry = {.count = 1, .reusable = false}}, SHIFT(535),
  [1300] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_partition_key_list, 1, 0, 0),
  [1302] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_select_elements_repeat1, 2, 0, 0), SHIFT_REPEAT(404),
  [1305] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_select_elements_repeat1, 2, 0, 0),
  [1307] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_clustering_key_list, 2, 0, 0),
  [1309] = {.entry = {.count = 1, .reusable = false}}, SHIFT(772),
  [1311] = {.entry = {.count = 1, .reusable = true}}, SHIFT(167),
  [1313] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_trigger_name, 1, 0, 9),
  [1315] = {.entry = {.count = 1, .reusable = true}}, SHIFT(769),
  [1317] = {.entry = {.count = 1, .reusable = true}}, SHIFT(118),
  [1319] = {.entry = {.count = 1, .reusable = true}}, SHIFT(80),
  [1321] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [1323] = {.entry = {.count = 1, .reusable = true}}, SHIFT(528),
  [1325] = {.entry = {.count = 1, .reusable = true}}, SHIFT(573),
  [1327] = {.entry = {.count = 1, .reusable = true}}, SHIFT(763),
  [1329] = {.entry = {.count = 1, .reusable = true}}, SHIFT(342),
  [1331] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_init_cond_hash_item, 3, 0, 63),
  [1333] = {.entry = {.count = 1, .reusable = true}}, SHIFT(915),
  [1335] = {.entry = {.count = 1, .reusable = true}}, SHIFT(193),
  [1337] = {.entry = {.count = 1, .reusable = true}}, SHIFT(620),
  [1339] = {.entry = {.count = 1, .reusable = true}}, SHIFT(191),
  [1341] = {.entry = {.count = 1, .reusable = true}}, SHIFT(77),
  [1343] = {.entry = {.count = 1, .reusable = true}}, SHIFT(179),
  [1345] = {.entry = {.count = 1, .reusable = true}}, SHIFT(395),
  [1347] = {.entry = {.count = 1, .reusable = true}}, SHIFT(95),
  [1349] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_expression, 1, 0, 0),
  [1351] = {.entry = {.count = 1, .reusable = true}}, SHIFT(476),
  [1353] = {.entry = {.count = 1, .reusable = true}}, SHIFT(599),
  [1355] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_column_definition, 3, 0, 1),
  [1357] = {.entry = {.count = 1, .reusable = true}}, SHIFT(833),
  [1359] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_column_not_null, 4, 0, 0),
  [1361] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_assignment_map_repeat1, 4, 0, 0),
  [1363] = {.entry = {.count = 1, .reusable = true}}, SHIFT(905),
  [1365] = {.entry = {.count = 1, .reusable = true}}, SHIFT(479),
  [1367] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_clustering_order_repeat1, 3, 0, 33),
  [1369] = {.entry = {.count = 1, .reusable = true}}, SHIFT(675),
  [1371] = {.entry = {.count = 1, .reusable = true}}, SHIFT(458),
  [1373] = {.entry = {.count = 1, .reusable = true}}, SHIFT(451),
  [1375] = {.entry = {.count = 1, .reusable = true}}, SHIFT(603),
  [1377] = {.entry = {.count = 1, .reusable = true}}, SHIFT(748),
  [1379] = {.entry = {.count = 1, .reusable = true}}, SHIFT(744),
  [1381] = {.entry = {.count = 1, .reusable = true}}, SHIFT(684),
  [1383] = {.entry = {.count = 1, .reusable = true}}, SHIFT(731),
  [1385] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_select_element, 3, 0, 12),
  [1387] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_select_element, 3, 0, 13),
  [1389] = {.entry = {.count = 1, .reusable = true}}, SHIFT(214),
  [1391] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_insert_column_spec, 3, 0, 0),
  [1393] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_option_hash_item, 3, 0, 50),
  [1395] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_replication_list_item, 3, 0, 50),
  [1397] = {.entry = {.count = 1, .reusable = true}}, SHIFT(592),
  [1399] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_primary_key_definition, 1, 0, 49),
  [1401] = {.entry = {.count = 1, .reusable = true}}, SHIFT(515),
  [1403] = {.entry = {.count = 1, .reusable = true}}, SHIFT(720),
  [1405] = {.entry = {.count = 1, .reusable = true}}, SHIFT(160),
  [1407] = {.entry = {.count = 1, .reusable = true}}, SHIFT(521),
  [1409] = {.entry = {.count = 1, .reusable = true}}, SHIFT(283),
  [1411] = {.entry = {.count = 1, .reusable = true}}, SHIFT(634),
  [1413] = {.entry = {.count = 1, .reusable = false}}, SHIFT(610),
  [1415] = {.entry = {.count = 1, .reusable = false}}, SHIFT(752),
  [1417] = {.entry = {.count = 1, .reusable = false}}, SHIFT(145),
  [1419] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_trigger_name, 3, 0, 23),
  [1421] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_primary_key_column, 2, 0, 0),
  [1423] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_assignment_element, 5, 0, 0),
  [1425] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_delete_column_item, 4, 0, 19),
  [1427] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_assignment_element, 5, 0, 44),
  [1429] = {.entry = {.count = 1, .reusable = true}}, SHIFT(204),
  [1431] = {.entry = {.count = 1, .reusable = true}}, SHIFT(566),
  [1433] = {.entry = {.count = 1, .reusable = true}}, SHIFT(725),
  [1435] = {.entry = {.count = 1, .reusable = true}}, SHIFT(148),
  [1437] = {.entry = {.count = 1, .reusable = true}}, SHIFT(641),
  [1439] = {.entry = {.count = 1, .reusable = true}}, SHIFT(408),
  [1441] = {.entry = {.count = 1, .reusable = true}}, SHIFT(551),
  [1443] = {.entry = {.count = 1, .reusable = true}}, SHIFT(926),
  [1445] = {.entry = {.count = 1, .reusable = true}}, SHIFT(917),
  [1447] = {.entry = {.count = 1, .reusable = true}}, SHIFT(736),
  [1449] = {.entry = {.count = 1, .reusable = true}}, SHIFT(737),
  [1451] = {.entry = {.count = 1, .reusable = true}}, SHIFT(738),
  [1453] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [1455] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [1457] = {.entry = {.count = 1, .reusable = true}}, SHIFT(638),
  [1459] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [1461] = {.entry = {.count = 1, .reusable = true}}, SHIFT(745),
  [1463] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [1465] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [1467] = {.entry = {.count = 1, .reusable = true}}, SHIFT(563),
  [1469] = {.entry = {.count = 1, .reusable = true}}, SHIFT(901),
  [1471] = {.entry = {.count = 1, .reusable = true}}, SHIFT(883),
  [1473] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [1475] = {.entry = {.count = 1, .reusable = true}}, SHIFT(630),
  [1477] = {.entry = {.count = 1, .reusable = true}}, SHIFT(869),
  [1479] = {.entry = {.count = 1, .reusable = true}}, SHIFT(436),
  [1481] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [1483] = {.entry = {.count = 1, .reusable = true}}, SHIFT(625),
  [1485] = {.entry = {.count = 1, .reusable = true}}, SHIFT(583),
  [1487] = {.entry = {.count = 1, .reusable = true}}, SHIFT(332),
  [1489] = {.entry = {.count = 1, .reusable = true}}, SHIFT(156),
  [1491] = {.entry = {.count = 1, .reusable = true}}, SHIFT(51),
  [1493] = {.entry = {.count = 1, .reusable = true}}, SHIFT(605),
  [1495] = {.entry = {.count = 1, .reusable = true}}, SHIFT(312),
  [1497] = {.entry = {.count = 1, .reusable = true}}, SHIFT(357),
  [1499] = {.entry = {.count = 1, .reusable = true}}, SHIFT(751),
  [1501] = {.entry = {.count = 1, .reusable = true}}, SHIFT(122),
  [1503] = {.entry = {.count = 1, .reusable = true}}, SHIFT(251),
  [1505] = {.entry = {.count = 1, .reusable = true}}, SHIFT(372),
  [1507] = {.entry = {.count = 1, .reusable = true}}, SHIFT(235),
  [1509] = {.entry = {.count = 1, .reusable = true}}, SHIFT(723),
  [1511] = {.entry = {.count = 1, .reusable = true}}, SHIFT(338),
  [1513] = {.entry = {.count = 1, .reusable = true}}, SHIFT(550),
  [1515] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_column_definition_list, 4, 0, 0),
  [1517] = {.entry = {.count = 1, .reusable = true}}, SHIFT(872),
  [1519] = {.entry = {.count = 1, .reusable = true}}, SHIFT(762),
  [1521] = {.entry = {.count = 1, .reusable = true}}, SHIFT(159),
  [1523] = {.entry = {.count = 1, .reusable = true}}, SHIFT(761),
  [1525] = {.entry = {.count = 1, .reusable = true}}, SHIFT(758),
  [1527] = {.entry = {.count = 1, .reusable = true}}, SHIFT(40),
  [1529] = {.entry = {.count = 1, .reusable = true}}, SHIFT(146),
  [1531] = {.entry = {.count = 1, .reusable = true}}, SHIFT(229),
  [1533] = {.entry = {.count = 1, .reusable = true}}, SHIFT(652),
  [1535] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_index_keys_spec, 4, 0, 46),
  [1537] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_index_entries_s_spec, 4, 0, 47),
  [1539] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_index_full_spec, 4, 0, 48),
  [1541] = {.entry = {.count = 1, .reusable = true}}, SHIFT(933),
  [1543] = {.entry = {.count = 1, .reusable = true}}, SHIFT(670),
  [1545] = {.entry = {.count = 1, .reusable = true}}, SHIFT(494),
  [1547] = {.entry = {.count = 1, .reusable = true}}, SHIFT(87),
  [1549] = {.entry = {.count = 1, .reusable = true}}, SHIFT(83),
  [1551] = {.entry = {.count = 1, .reusable = true}}, SHIFT(785),
  [1553] = {.entry = {.count = 1, .reusable = true}}, SHIFT(89),
  [1555] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [1557] = {.entry = {.count = 1, .reusable = true}}, SHIFT(78),
  [1559] = {.entry = {.count = 1, .reusable = true}}, SHIFT(281),
  [1561] = {.entry = {.count = 1, .reusable = true}}, SHIFT(789),
  [1563] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_return_mode, 4, 0, 0),
  [1565] = {.entry = {.count = 1, .reusable = true}}, SHIFT(790),
  [1567] = {.entry = {.count = 1, .reusable = true}}, SHIFT(791),
  [1569] = {.entry = {.count = 1, .reusable = true}}, SHIFT(325),
  [1571] = {.entry = {.count = 1, .reusable = true}}, SHIFT(939),
  [1573] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [1575] = {.entry = {.count = 1, .reusable = true}}, SHIFT(706),
  [1577] = {.entry = {.count = 1, .reusable = true}}, SHIFT(129),
  [1579] = {.entry = {.count = 1, .reusable = true}}, SHIFT(607),
  [1581] = {.entry = {.count = 1, .reusable = true}}, SHIFT(70),
  [1583] = {.entry = {.count = 1, .reusable = true}}, SHIFT(541),
  [1585] = {.entry = {.count = 1, .reusable = true}}, SHIFT(128),
  [1587] = {.entry = {.count = 1, .reusable = true}}, SHIFT(82),
  [1589] = {.entry = {.count = 1, .reusable = true}}, SHIFT(126),
  [1591] = {.entry = {.count = 1, .reusable = true}}, SHIFT(202),
  [1593] = {.entry = {.count = 1, .reusable = true}}, SHIFT(200),
  [1595] = {.entry = {.count = 1, .reusable = true}}, SHIFT(195),
  [1597] = {.entry = {.count = 1, .reusable = true}}, SHIFT(837),
  [1599] = {.entry = {.count = 1, .reusable = true}}, SHIFT(637),
  [1601] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_table_option_name, 1, 0, 0),
  [1603] = {.entry = {.count = 1, .reusable = true}}, SHIFT(365),
  [1605] = {.entry = {.count = 1, .reusable = true}}, SHIFT(960),
  [1607] = {.entry = {.count = 1, .reusable = true}}, SHIFT(704),
  [1609] = {.entry = {.count = 1, .reusable = true}}, SHIFT(289),
  [1611] = {.entry = {.count = 1, .reusable = true}}, SHIFT(527),
  [1613] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [1615] = {.entry = {.count = 1, .reusable = true}}, SHIFT(950),
  [1617] = {.entry = {.count = 1, .reusable = true}}, SHIFT(648),
  [1619] = {.entry = {.count = 1, .reusable = true}}, SHIFT(88),
  [1621] = {.entry = {.count = 1, .reusable = true}}, SHIFT(102),
  [1623] = {.entry = {.count = 1, .reusable = true}}, SHIFT(649),
  [1625] = {.entry = {.count = 1, .reusable = true}}, SHIFT(210),
  [1627] = {.entry = {.count = 1, .reusable = true}}, SHIFT(650),
  [1629] = {.entry = {.count = 1, .reusable = true}}, SHIFT(651),
  [1631] = {.entry = {.count = 1, .reusable = true}}, SHIFT(712),
  [1633] = {.entry = {.count = 1, .reusable = true}}, SHIFT(676),
  [1635] = {.entry = {.count = 1, .reusable = true}}, SHIFT(183),
  [1637] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_indexed_column, 4, 0, 37),
  [1639] = {.entry = {.count = 1, .reusable = true}}, SHIFT(668),
  [1641] = {.entry = {.count = 1, .reusable = true}}, SHIFT(141),
  [1643] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_primary_key_definition, 1, 0, 0),
  [1645] = {.entry = {.count = 1, .reusable = true}}, SHIFT(669),
  [1647] = {.entry = {.count = 1, .reusable = true}}, SHIFT(203),
  [1649] = {.entry = {.count = 1, .reusable = true}}, SHIFT(667),
  [1651] = {.entry = {.count = 1, .reusable = true}}, SHIFT(219),
  [1653] = {.entry = {.count = 1, .reusable = true}}, SHIFT(493),
  [1655] = {.entry = {.count = 1, .reusable = true}}, SHIFT(91),
  [1657] = {.entry = {.count = 1, .reusable = true}}, SHIFT(524),
  [1659] = {.entry = {.count = 1, .reusable = true}}, SHIFT(201),
  [1661] = {.entry = {.count = 1, .reusable = true}}, SHIFT(698),
  [1663] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [1665] = {.entry = {.count = 1, .reusable = true}}, SHIFT(663),
  [1667] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_return_mode, 5, 0, 0),
  [1669] = {.entry = {.count = 1, .reusable = true}}, SHIFT(827),
  [1671] = {.entry = {.count = 1, .reusable = true}}, SHIFT(828),
  [1673] = {.entry = {.count = 1, .reusable = true}}, SHIFT(829),
  [1675] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [1677] = {.entry = {.count = 1, .reusable = true}}, SHIFT(174),
  [1679] = {.entry = {.count = 1, .reusable = true}}, SHIFT(175),
  [1681] = {.entry = {.count = 1, .reusable = true}}, SHIFT(334),
  [1683] = {.entry = {.count = 1, .reusable = true}}, SHIFT(379),
  [1685] = {.entry = {.count = 1, .reusable = true}}, SHIFT(585),
  [1687] = {.entry = {.count = 1, .reusable = true}}, SHIFT(584),
  [1689] = {.entry = {.count = 1, .reusable = true}}, SHIFT(697),
  [1691] = {.entry = {.count = 1, .reusable = true}}, SHIFT(924),
  [1693] = {.entry = {.count = 1, .reusable = true}}, SHIFT(660),
  [1695] = {.entry = {.count = 1, .reusable = true}}, SHIFT(475),
  [1697] = {.entry = {.count = 1, .reusable = true}}, SHIFT(838),
  [1699] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [1701] = {.entry = {.count = 1, .reusable = true}}, SHIFT(664),
  [1703] = {.entry = {.count = 1, .reusable = true}}, SHIFT(693),
  [1705] = {.entry = {.count = 1, .reusable = true}}, SHIFT(393),
  [1707] = {.entry = {.count = 1, .reusable = true}}, SHIFT(386),
  [1709] = {.entry = {.count = 1, .reusable = true}}, SHIFT(462),
  [1711] = {.entry = {.count = 1, .reusable = true}}, SHIFT(662),
  [1713] = {.entry = {.count = 1, .reusable = true}}, SHIFT(61),
  [1715] = {.entry = {.count = 1, .reusable = true}}, SHIFT(749),
  [1717] = {.entry = {.count = 1, .reusable = true}}, SHIFT(724),
  [1719] = {.entry = {.count = 1, .reusable = true}}, SHIFT(291),
  [1721] = {.entry = {.count = 1, .reusable = true}}, SHIFT(29),
  [1723] = {.entry = {.count = 1, .reusable = true}}, SHIFT(849),
  [1725] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [1727] = {.entry = {.count = 1, .reusable = true}}, SHIFT(65),
  [1729] = {.entry = {.count = 1, .reusable = true}}, SHIFT(893),
  [1731] = {.entry = {.count = 1, .reusable = true}}, SHIFT(892),
  [1733] = {.entry = {.count = 1, .reusable = true}}, SHIFT(886),
  [1735] = {.entry = {.count = 1, .reusable = true}}, SHIFT(853),
  [1737] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_index_column_spec, 1, 0, 1),
  [1739] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [1741] = {.entry = {.count = 1, .reusable = true}}, SHIFT(268),
  [1743] = {.entry = {.count = 1, .reusable = true}}, SHIFT(857),
  [1745] = {.entry = {.count = 1, .reusable = true}}, SHIFT(858),
  [1747] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [1749] = {.entry = {.count = 1, .reusable = true}}, SHIFT(233),
  [1751] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_index_column_spec, 1, 0, 0),
  [1753] = {.entry = {.count = 1, .reusable = true}}, SHIFT(623),
  [1755] = {.entry = {.count = 1, .reusable = true}}, SHIFT(279),
  [1757] = {.entry = {.count = 1, .reusable = true}}, SHIFT(161),
  [1759] = {.entry = {.count = 1, .reusable = true}}, SHIFT(759),
  [1761] = {.entry = {.count = 1, .reusable = true}}, SHIFT(572),
  [1763] = {.entry = {.count = 1, .reusable = true}}, SHIFT(463),
  [1765] = {.entry = {.count = 1, .reusable = true}}, SHIFT(307),
  [1767] = {.entry = {.count = 1, .reusable = true}}, SHIFT(717),
  [1769] = {.entry = {.count = 1, .reusable = true}}, SHIFT(865),
  [1771] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [1773] = {.entry = {.count = 1, .reusable = true}}, SHIFT(864),
  [1775] = {.entry = {.count = 1, .reusable = true}}, SHIFT(632),
  [1777] = {.entry = {.count = 1, .reusable = true}}, SHIFT(631),
  [1779] = {.entry = {.count = 1, .reusable = true}}, SHIFT(628),
  [1781] = {.entry = {.count = 1, .reusable = true}}, SHIFT(627),
  [1783] = {.entry = {.count = 1, .reusable = true}}, SHIFT(570),
  [1785] = {.entry = {.count = 1, .reusable = true}}, SHIFT(523),
  [1787] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_compound_key, 3, 0, 53),
  [1789] = {.entry = {.count = 1, .reusable = true}}, SHIFT(626),
  [1791] = {.entry = {.count = 1, .reusable = true}}, SHIFT(876),
  [1793] = {.entry = {.count = 1, .reusable = true}}, SHIFT(877),
  [1795] = {.entry = {.count = 1, .reusable = true}}, SHIFT(624),
  [1797] = {.entry = {.count = 1, .reusable = true}}, SHIFT(533),
  [1799] = {.entry = {.count = 1, .reusable = true}}, SHIFT(264),
  [1801] = {.entry = {.count = 1, .reusable = true}}, SHIFT(880),
  [1803] = {.entry = {.count = 1, .reusable = true}}, SHIFT(622),
  [1805] = {.entry = {.count = 1, .reusable = true}}, SHIFT(300),
  [1807] = {.entry = {.count = 1, .reusable = true}}, SHIFT(85),
  [1809] = {.entry = {.count = 1, .reusable = true}}, SHIFT(884),
  [1811] = {.entry = {.count = 1, .reusable = true}}, SHIFT(621),
  [1813] = {.entry = {.count = 1, .reusable = true}}, SHIFT(680),
  [1815] = {.entry = {.count = 1, .reusable = true}}, SHIFT(679),
  [1817] = {.entry = {.count = 1, .reusable = true}}, SHIFT(764),
  [1819] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [1821] = {.entry = {.count = 1, .reusable = true}}, SHIFT(619),
  [1823] = {.entry = {.count = 1, .reusable = true}}, SHIFT(180),
  [1825] = {.entry = {.count = 1, .reusable = true}}, SHIFT(567),
  [1827] = {.entry = {.count = 1, .reusable = true}}, SHIFT(767),
  [1829] = {.entry = {.count = 1, .reusable = true}}, SHIFT(674),
  [1831] = {.entry = {.count = 1, .reusable = true}}, SHIFT(617),
  [1833] = {.entry = {.count = 1, .reusable = true}}, SHIFT(213),
  [1835] = {.entry = {.count = 1, .reusable = true}}, SHIFT(770),
  [1837] = {.entry = {.count = 1, .reusable = true}}, SHIFT(895),
  [1839] = {.entry = {.count = 1, .reusable = true}}, SHIFT(896),
  [1841] = {.entry = {.count = 1, .reusable = true}}, SHIFT(897),
  [1843] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [1845] = {.entry = {.count = 1, .reusable = true}}, SHIFT(220),
  [1847] = {.entry = {.count = 1, .reusable = true}}, SHIFT(564),
  [1849] = {.entry = {.count = 1, .reusable = true}}, SHIFT(778),
  [1851] = {.entry = {.count = 1, .reusable = true}}, SHIFT(181),
  [1853] = {.entry = {.count = 1, .reusable = true}}, SHIFT(560),
  [1855] = {.entry = {.count = 1, .reusable = true}}, SHIFT(780),
  [1857] = {.entry = {.count = 1, .reusable = true}}, SHIFT(672),
  [1859] = {.entry = {.count = 1, .reusable = true}}, SHIFT(487),
  [1861] = {.entry = {.count = 1, .reusable = true}}, SHIFT(784),
  [1863] = {.entry = {.count = 1, .reusable = true}}, SHIFT(786),
  [1865] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [1867] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [1869] = {.entry = {.count = 1, .reusable = true}}, SHIFT(815),
  [1871] = {.entry = {.count = 1, .reusable = true}}, SHIFT(710),
  [1873] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_composite_key, 5, 0, 0),
  [1875] = {.entry = {.count = 1, .reusable = true}}, SHIFT(258),
  [1877] = {.entry = {.count = 1, .reusable = true}}, SHIFT(911),
  [1879] = {.entry = {.count = 1, .reusable = true}}, SHIFT(912),
  [1881] = {.entry = {.count = 1, .reusable = true}}, SHIFT(788),
  [1883] = {.entry = {.count = 1, .reusable = true}}, SHIFT(339),
  [1885] = {.entry = {.count = 1, .reusable = true}}, SHIFT(608),
  [1887] = {.entry = {.count = 1, .reusable = true}}, SHIFT(178),
  [1889] = {.entry = {.count = 1, .reusable = true}}, SHIFT(798),
  [1891] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_short_index_name, 1, 0, 4),
  [1893] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_column_definition_list, 3, 0, 0),
  [1895] = {.entry = {.count = 1, .reusable = true}}, SHIFT(708),
  [1897] = {.entry = {.count = 1, .reusable = true}}, SHIFT(920),
  [1899] = {.entry = {.count = 1, .reusable = true}}, SHIFT(496),
  [1901] = {.entry = {.count = 1, .reusable = true}}, SHIFT(803),
  [1903] = {.entry = {.count = 1, .reusable = true}}, SHIFT(299),
  [1905] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [1907] = {.entry = {.count = 1, .reusable = true}}, SHIFT(265),
  [1909] = {.entry = {.count = 1, .reusable = true}}, SHIFT(925),
  [1911] = {.entry = {.count = 1, .reusable = true}}, SHIFT(298),
  [1913] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [1915] = {.entry = {.count = 1, .reusable = true}}, SHIFT(304),
  [1917] = {.entry = {.count = 1, .reusable = true}}, SHIFT(653),
  [1919] = {.entry = {.count = 1, .reusable = true}}, SHIFT(596),
  [1921] = {.entry = {.count = 1, .reusable = true}}, SHIFT(809),
  [1923] = {.entry = {.count = 1, .reusable = true}}, SHIFT(594),
  [1925] = {.entry = {.count = 1, .reusable = true}}, SHIFT(937),
  [1927] = {.entry = {.count = 1, .reusable = true}}, SHIFT(938),
  [1929] = {.entry = {.count = 1, .reusable = true}}, SHIFT(540),
  [1931] = {.entry = {.count = 1, .reusable = true}}, SHIFT(591),
  [1933] = {.entry = {.count = 1, .reusable = true}}, SHIFT(114),
  [1935] = {.entry = {.count = 1, .reusable = true}}, SHIFT(240),
  [1937] = {.entry = {.count = 1, .reusable = true}}, SHIFT(50),
  [1939] = {.entry = {.count = 1, .reusable = true}}, SHIFT(586),
  [1941] = {.entry = {.count = 1, .reusable = true}}, SHIFT(111),
  [1943] = {.entry = {.count = 1, .reusable = true}}, SHIFT(600),
  [1945] = {.entry = {.count = 1, .reusable = true}}, SHIFT(581),
  [1947] = {.entry = {.count = 1, .reusable = true}}, SHIFT(69),
  [1949] = {.entry = {.count = 1, .reusable = true}}, SHIFT(601),
  [1951] = {.entry = {.count = 1, .reusable = true}}, SHIFT(604),
  [1953] = {.entry = {.count = 1, .reusable = true}}, SHIFT(643),
  [1955] = {.entry = {.count = 1, .reusable = true}}, SHIFT(343),
  [1957] = {.entry = {.count = 1, .reusable = true}}, SHIFT(344),
  [1959] = {.entry = {.count = 1, .reusable = true}}, SHIFT(953),
  [1961] = {.entry = {.count = 1, .reusable = true}}, SHIFT(954),
  [1963] = {.entry = {.count = 1, .reusable = true}}, SHIFT(606),
  [1965] = {.entry = {.count = 1, .reusable = true}}, SHIFT(457),
  [1967] = {.entry = {.count = 1, .reusable = true}}, SHIFT(576),
  [1969] = {.entry = {.count = 1, .reusable = true}}, SHIFT(519),
  [1971] = {.entry = {.count = 1, .reusable = true}}, SHIFT(795),
  [1973] = {.entry = {.count = 1, .reusable = true}}, SHIFT(794),
  [1975] = {.entry = {.count = 1, .reusable = true}}, SHIFT(259),
  [1977] = {.entry = {.count = 1, .reusable = true}}, SHIFT(774),
  [1979] = {.entry = {.count = 1, .reusable = true}}, SHIFT(104),
  [1981] = {.entry = {.count = 1, .reusable = true}}, SHIFT(370),
  [1983] = {.entry = {.count = 1, .reusable = true}}, SHIFT(765),
  [1985] = {.entry = {.count = 1, .reusable = true}}, SHIFT(171),
  [1987] = {.entry = {.count = 1, .reusable = true}}, SHIFT(100),
  [1989] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [1991] = {.entry = {.count = 1, .reusable = true}}, SHIFT(223),
  [1993] = {.entry = {.count = 1, .reusable = true}}, SHIFT(957),
  [1995] = {.entry = {.count = 1, .reusable = true}}, SHIFT(301),
  [1997] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [1999] = {.entry = {.count = 1, .reusable = true}}, SHIFT(207),
  [2001] = {.entry = {.count = 1, .reusable = true}}, SHIFT(260),
  [2003] = {.entry = {.count = 1, .reusable = true}}, SHIFT(254),
  [2005] = {.entry = {.count = 1, .reusable = true}}, SHIFT(271),
};

#ifdef __cplusplus
extern "C" {
#endif
#ifdef TREE_SITTER_HIDE_SYMBOLS
#define TS_PUBLIC
#elif defined(_WIN32)
#define TS_PUBLIC __declspec(dllexport)
#else
#define TS_PUBLIC __attribute__((visibility("default")))
#endif

TS_PUBLIC const TSLanguage *tree_sitter_cql(void) {
  static const TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
    .state_count = STATE_COUNT,
    .large_state_count = LARGE_STATE_COUNT,
    .production_id_count = PRODUCTION_ID_COUNT,
    .field_count = FIELD_COUNT,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .parse_table = &ts_parse_table[0][0],
    .small_parse_table = ts_small_parse_table,
    .small_parse_table_map = ts_small_parse_table_map,
    .parse_actions = ts_parse_actions,
    .symbol_names = ts_symbol_names,
    .symbol_metadata = ts_symbol_metadata,
    .public_symbol_map = ts_symbol_map,
    .alias_map = ts_non_terminal_alias_map,
    .alias_sequences = &ts_alias_sequences[0][0],
    .lex_modes = ts_lex_modes,
    .lex_fn = ts_lex,
    .primary_state_ids = ts_primary_state_ids,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
