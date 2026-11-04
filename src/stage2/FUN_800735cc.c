/* FUN_800735cc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800735cc  body 0x800735cc..0x8007360f  size 68 B
 * body sha256 5ec24e2881efd4cc3feb312302af8c28c5efc55eb3f53a209705b798812a293c
 * provider record sha256 2d98ec7efc07cf3fee68bae85940eb346a4be8735c95ce0f800d1e8eb98668db
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_800735cc(int param_1)

{
  FUN_80052bd0(*(undefined2 *)(*(int *)(param_1 + 0x1c) + 2),
               *(undefined2 *)(*(int *)(param_1 + 0x1c) + 4));
  *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 6;
  return 1;
}
