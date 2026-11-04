/* inflate
 * image   boot (boot), base 0x80000480
 * address 0x800045dc  body 0x800045dc..0x8000472b  size 336 B
 * body sha256 64675cc955364f10b7b49e6bbdffbf9d23577be198dc2068db83190abc975f94
 * provider record sha256 7e49ed0c2c8b17b8629d97a761839eb2c7fd24b8659b55504bdbe4b775376aa7
 * callees 6 direct (6 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 inflate(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  *(undefined4 *)(param_1 + 0x44) = param_2;
  *(undefined4 *)(param_1 + 0x50) = param_3;
  *(undefined4 *)(param_1 + 0x10) = 0x8000;
  *(undefined4 *)(param_1 + 0x40) = 0;
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 0x38) = 0;
  *(undefined4 *)(param_1 + 0x3c) = param_4;
  *(undefined4 *)(param_1 + 0x48) = param_4;
  *(undefined4 *)(param_1 + 0xc) = param_3;
  FUN_8000319c(param_1,0x80011860,0x38);
  do {
    if (_DAT_80132110 != 0 && _DAT_80112a18 != 0) {
      func_0x8004cd88(1);
      _DAT_80112a18 = 0;
    }
    if (*(int *)(param_1 + 0x38) != 0) goto LAB_800046dc;
    iVar1 = FUN_8000472c(param_1);
    if (iVar1 == 0) break;
    uVar2 = FUN_800031c4(param_1,0);
    *(undefined4 *)(param_1 + 0x40) = uVar2;
    FUN_800048b0(param_1);
  } while (*(int *)(param_1 + 0x40) == 0);
  do {
    if (*(int *)(param_1 + 0x38) != 0) {
LAB_800046dc:
      FUN_80002fe8(param_1);
      if ((*(int *)(param_1 + 0x38) == 0) && (*(uint *)(param_1 + 0x40) < 2)) {
        *(undefined4 *)(param_1 + 0x40) = 0;
      }
      if (*(int *)(param_1 + 0x40) != 0) {
        trap(0);
      }
      return *(undefined4 *)(param_1 + 0x14);
    }
    uVar2 = FUN_800031c4(param_1,4);
    *(undefined4 *)(param_1 + 0x40) = uVar2;
    iVar1 = FUN_800048b0(param_1);
    if ((iVar1 == 0) || (*(int *)(param_1 + 0x40) != 0)) goto LAB_800046dc;
  } while( true );
}
