/* FUN_80165688
 * image   ovl_00a733e (ovl), base 0x80161cf0
 * address 0x80165688  body 0x80165688..0x8016578b  size 260 B
 * body sha256 57a013df35e12616cbcbfefde3e066b874c90631ec84511b7c4a2d4175ba1bec
 * provider record sha256 b0a2c8cc43ee92910b6a95e8944d60f6b7216f0f1fdcb21e9aec6188e4ae861e
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80165688(int param_1)

{
  undefined1 uVar1;
  uint uVar2;
  undefined4 uVar3;
  
  if (*(char *)(param_1 + 4) == '\x02') {
    *(undefined1 *)(param_1 + 0x2b5) = 0xf;
    uVar2 = func_0x80033604();
    FUN_80167374(param_1,(&DAT_80167db8)[uVar2 & 3],4);
    uVar2 = func_0x80033604();
    uVar1 = (&DAT_80167db8)[uVar2 & 3];
    uVar3 = 4;
  }
  else {
    *(undefined1 *)(param_1 + 0x2b5) = 0x2d;
    uVar2 = func_0x80033604();
    FUN_80167374(param_1,(&DAT_80167db8)[uVar2 & 3],4);
    uVar2 = func_0x80033604();
    FUN_80167374(param_1,(&DAT_80167db8)[uVar2 & 3],4);
    uVar2 = func_0x80033604();
    uVar1 = (&DAT_80167db8)[uVar2 & 3];
    uVar3 = 8;
  }
  FUN_80167374(param_1,uVar1,uVar3);
  return;
}
