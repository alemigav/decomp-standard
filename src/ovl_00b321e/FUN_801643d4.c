/* FUN_801643d4
 * image   ovl_00b321e (ovl), base 0x80161cf0
 * address 0x801643d4  body 0x801643d4..0x80164543  size 368 B
 * body sha256 f1652616a86d4f56317dabaef5269519e56d137ce8ee43147d2063c3fbb4f10c
 * provider record sha256 e5a6f0f2d4bb33ab11a49eb2b6c69ef3cc8255910cfc55e53cd72d8b05286811
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801643d4(int param_1,undefined4 param_2,undefined4 param_3)

{
  if (((&DAT_80166793)[*(byte *)(param_1 + 5)] == '\0') || (*(char *)(param_1 + 0x2c5) != '\0')) {
    FUN_80166270(param_1,0,(&DAT_8016677f)[*(byte *)(param_1 + 5)]);
  }
  else {
    FUN_801663a4(param_1,(&DAT_8016677f)[*(byte *)(param_1 + 5)]);
  }
  if (*(char *)(param_1 + 0x2d7) == '\0') {
    func_0x80077d18(3,param_1);
  }
  *(undefined1 *)(param_1 + 0x2d7) = 0;
  FUN_80164544(param_1);
  *(undefined1 *)(param_1 + 0x2d6) = *(undefined1 *)(param_1 + 5);
  *(uint *)(param_1 + 4) =
       (uint)*(byte *)(param_1 + 0x2c0) * 0x10000 + (uint)*(byte *)(param_1 + 0x2c1) * 0x100 +
       (uint)*(byte *)(param_1 + 0x2c2) + 0x1000000;
  *(undefined2 *)(param_1 + 0x1e0) = *(undefined2 *)(param_1 + 0x2d0);
  *(undefined2 *)(param_1 + 0x1e2) = *(undefined2 *)(param_1 + 0x2d2);
  *(undefined2 *)(param_1 + 0x1e4) = *(undefined2 *)(param_1 + 0x2d4);
  (*(code *)(&PTR_FUN_80166670)[*(byte *)(param_1 + 5)])(param_1,param_2,param_3);
  *(undefined1 *)(param_1 + 0x2c0) = *(undefined1 *)(param_1 + 5);
  *(undefined1 *)(param_1 + 0x2c1) = *(undefined1 *)(param_1 + 6);
  *(undefined1 *)(param_1 + 0x2c2) = *(undefined1 *)(param_1 + 7);
  *(undefined2 *)(param_1 + 0x2d0) = *(undefined2 *)(param_1 + 0x1e0);
  *(undefined2 *)(param_1 + 0x2d2) = *(undefined2 *)(param_1 + 0x1e2);
  *(undefined2 *)(param_1 + 0x2d4) = *(undefined2 *)(param_1 + 0x1e4);
  return;
}
