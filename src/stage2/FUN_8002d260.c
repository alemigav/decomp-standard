/* FUN_8002d260
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8002d260  body 0x8002d260..0x8002d32f  size 208 B
 * body sha256 cde34d0f35e7e488179e35d9e76c8b4af3c796e56ac83bf8d0730fc97ef3ec09
 * provider record sha256 bfd87711533317233445f17be26479715b7695a59d1c09156e8921d05e691de9
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_8002d260(int param_1)

{
  int iVar1;
  
  if (((((*(int *)(param_1 + 0x58) == 0) && (*(int *)(param_1 + 0x100) == 0)) &&
       (*(int *)(param_1 + 0x24) == 3)) &&
      (((*(int *)(param_1 + 0x20) == 3 && (*(int *)(param_1 + 0x28) == 2)) &&
       ((*(int *)(param_1 + 100) == 3 &&
        ((iVar1 = *(int *)(param_1 + 0xb0), *(int *)(iVar1 + 8) == 2 &&
         (*(int *)(iVar1 + 0x58) == 1)))))))) &&
     ((*(int *)(iVar1 + 0xa8) == 1 &&
      (((((*(int *)(iVar1 + 0xc) < 3 && (*(int *)(iVar1 + 0x5c) == 1)) &&
         (*(int *)(iVar1 + 0xac) == 1)) &&
        ((*(int *)(iVar1 + 0x24) == *(int *)(param_1 + 0x10c) &&
         (*(int *)(iVar1 + 0x74) == *(int *)(iVar1 + 0x24))))) &&
       (*(int *)(iVar1 + 0xc4) == *(int *)(iVar1 + 0x74))))))) {
    return 1;
  }
  return 0;
}
