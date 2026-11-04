/* FUN_8005f39c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8005f39c  body 0x8005f39c..0x8005f4cb  size 304 B
 * body sha256 0265e0bc789b6473b6bb0a46634b23be8d066f335ae4fc15b6e8079205241573
 * provider record sha256 a20bf5a71daebb41493084f46e090442c8a74b25b4812a3b261bc3236de3e5f9
 * callees 5 direct (5 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8005f39c(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined2 local_10;
  undefined2 local_e;
  undefined2 local_c;
  
  if (*(char *)(param_1 + 7) == '\0') {
    *(undefined1 *)(param_1 + 7) = 1;
    *(undefined4 *)(param_1 + 0x1e8) = 0x10000700;
  }
  iVar1 = FUN_80089d54(param_1,param_2,param_3,0x200);
  if (iVar1 != 0) {
    *(undefined2 *)(param_1 + 6) = 0x100;
  }
  if ((**(uint **)(param_1 + 0x214) & 0x100000) != 0) {
    FUN_80077adc(**(uint **)(param_1 + 0x214) & 0xf0000 | 0x1000001,param_1 + 0x28);
  }
  if (((**(uint **)(param_1 + 0x214) & 0x200000) != 0) && ((*(ushort *)(param_1 + 0x1f0) & 1) != 0))
  {
    if ((*(ushort *)(param_1 + 0x1aa) & 0xfff) == 0xd) {
      local_10 = 100;
      local_e = 0xdc;
      local_c = 0;
      FUN_80037780(0x2070800,(int)*(short *)(param_1 + 0x66),*(int *)(param_1 + 0x234) + 0x1060,
                   &local_10);
    }
    else {
      FUN_8005bea0(param_1);
    }
    *(ushort *)(param_1 + 0x1f0) = *(ushort *)(param_1 + 0x1f0) & 0xfffe;
  }
  if ((**(uint **)(param_1 + 0x214) & 0x400000) != 0) {
    FUN_8008d090();
    *(ushort *)(param_1 + 0x1f0) = *(ushort *)(param_1 + 0x1f0) | 1;
  }
  return;
}
