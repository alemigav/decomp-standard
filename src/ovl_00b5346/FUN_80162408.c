/* FUN_80162408
 * image   ovl_00b5346 (ovl), base 0x80161cf0
 * address 0x80162408  body 0x80162408..0x8016253f  size 312 B
 * body sha256 3d63a1e89c8ebbe3ae475b79f2636dda79fdf3283b65e9a79e99492b767e6c5e
 * provider record sha256 ba64905954cd3d83c7b1a24decb45448f6773c85ef51f4535b0e741e72bdad78
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80162408(int param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  short sVar2;
  undefined2 local_20;
  undefined2 local_1e;
  undefined2 local_1c;
  undefined2 local_18;
  undefined2 local_16;
  undefined2 local_14;
  
  bVar1 = *(byte *)(param_1 + 7);
  if (bVar1 != 1) {
    if (1 < bVar1) {
      if (bVar1 == 2) {
        *(undefined1 *)(param_1 + 7) = 3;
        local_20 = 0;
        local_1e = 0;
        local_1c = 0;
        local_18 = 0;
        local_16 = 0;
        local_14 = 0;
        func_0x80037c50(0x2b001000,(int)*(short *)(param_1 + 0x66),*(int *)(param_1 + 0x234) + 0x328
                        ,&local_20,&local_18);
        *(undefined4 *)(param_1 + 0x1e8) = 0x3f00;
        func_0x80077d18(0,param_1);
      }
      else if (bVar1 != 3) {
        return;
      }
      func_0x80089d54(param_1,param_2,param_3,0x40);
      if (*(char *)(param_1 + 0x1ea) == '\0') {
        *(undefined2 *)(param_1 + 6) = 0;
        return;
      }
      return;
    }
    if (bVar1 != 0) {
      return;
    }
    *(undefined4 *)(param_1 + 0x1e8) = 0x1003f00;
    *(undefined1 *)(param_1 + 7) = 1;
    *(undefined2 *)(param_1 + 500) = 0x1e;
  }
  func_0x80089d54(param_1,param_2,param_3,0x40);
  sVar2 = *(short *)(param_1 + 500);
  *(short *)(param_1 + 500) = sVar2 + -1;
  if (sVar2 == 1) {
    *(undefined1 *)(param_1 + 7) = 2;
  }
  return;
}
