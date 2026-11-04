/* FUN_8005360c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8005360c  body 0x8005360c..0x800537a3  size 104 B
 * body sha256 d958d401826960cb299c3ebfc9a478484468f1593b2fbf96d85b4a018af7e19a
 * provider record sha256 7866593fe116c0ce4bc7219674c32f291adfd93cc824913e09a2094631dd4121
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_8005360c(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  switch(DAT_800e860a) {
  case 1:
    FUN_80077adc(0x2060000,0);
LAB_8005365c:
    DAT_800e860b = 0;
    DAT_800e860a = 5;
    iVar1 = FUN_80053844(0x30,0x8e,0xf7,0x57);
    uVar2 = 1;
    if (iVar1 == 0) {
      FUN_80053260(1,0xf7,0x57,0x80);
LAB_80053784:
      DAT_800e860a = 0;
      uVar2 = 0;
    }
    return uVar2;
  case 2:
    FUN_80077adc(0x2070000,0);
  case 6:
    FUN_80053260(0,0,0,0x80);
    uVar2 = 0x30;
    uVar3 = 0x8e;
    uVar4 = 0xf7;
    uVar5 = 0x57;
    DAT_800e860b = 1;
    DAT_800e860a = 6;
LAB_80053770:
    iVar1 = FUN_80053844(uVar2,uVar3,uVar4,uVar5);
    if (iVar1 != 0) {
      return 1;
    }
    goto LAB_80053784;
  case 3:
    FUN_80077adc(0x2060000,0);
  case 7:
    uVar2 = 0x10;
    uVar3 = 0x15;
    uVar4 = 0xf0;
    uVar5 = 0x78;
    DAT_800e860a = 7;
    DAT_800e860b = 0;
    goto LAB_80053770;
  case 4:
    FUN_80077adc(0x2070000,0);
  case 8:
    uVar2 = 0x10;
    uVar3 = 0x15;
    uVar4 = 0xf0;
    uVar5 = 0x78;
    DAT_800e860b = 1;
    DAT_800e860a = 8;
    goto LAB_80053770;
  case 5:
    goto LAB_8005365c;
  default:
    goto LAB_80053784;
  }
}
