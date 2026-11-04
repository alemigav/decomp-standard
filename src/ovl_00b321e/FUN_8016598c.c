/* FUN_8016598c
 * image   ovl_00b321e (ovl), base 0x80161cf0
 * address 0x8016598c  body 0x8016598c..0x80165bcf  size 580 B
 * body sha256 bbc106179abb96a6eb0dcf94188457e61f5015d921f738c49e09c3c7fd942486
 * provider record sha256 342fc31dfd820a6f24016ca7c6b587a84639ab9c4c32401c35c1caf64e0bbacf
 * callees 6 direct (6 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8016598c(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  switch(*(undefined1 *)((int)param_1 + 5)) {
  case 0:
    *(undefined1 *)((int)param_1 + 5) = 1;
    param_1[0x7a] = 0x1000f00;
    *(byte *)(param_1 + 0x97) = *(byte *)(param_1 + 0x97) | 1;
    func_0x80052bd0(10,0);
    func_0x80052c6c(0x1e,0x96,0);
  case 1:
    iVar3 = func_0x80089d54(param_1,param_2,param_3,0x100);
    if (iVar3 != 0) {
      *(undefined1 *)((int)param_1 + 5) = 2;
      param_1[0x7a] = 0x2000f00;
    }
    break;
  case 2:
    func_0x80089d54(param_1,param_2,param_3,0x100);
    uVar1 = func_0x80033604();
    if ((uVar1 & 7) == 0) {
      uVar1 = func_0x80033604();
      FUN_80166270(param_1,(&DAT_80166848)[uVar1 & 3],2);
      uVar1 = func_0x80033604();
      uVar2 = func_0x80033604();
      func_0x80052bd0((uVar1 & 3) + 3,uVar2 & 3);
      uVar1 = func_0x80033604();
      uVar2 = func_0x80033604();
      func_0x80052c6c((uVar1 & 3) + 2,0xfa,uVar2 & 3);
      uVar1 = func_0x80033604();
      uVar2 = func_0x80033604();
      func_0x80052bd0((uVar1 & 3) + 3,(uVar2 & 3) + 3);
      uVar1 = func_0x80033604();
      uVar2 = func_0x80033604();
      func_0x80052c6c((uVar1 & 3) + 2,0xfa,(uVar2 & 3) + 3);
    }
    break;
  case 3:
    *(undefined1 *)((int)param_1 + 5) = 4;
    param_1[0x7a] = 0x3000f00;
    func_0x80052c6c(3,0x78,0);
    func_0x80052c6c(10,0x78,0);
  case 4:
    iVar3 = func_0x80089d54(param_1,param_2,param_3,0x100);
    if (iVar3 != 0) {
      param_1[1] = 0x1000000;
      *(byte *)(param_1 + 0x97) = *(byte *)(param_1 + 0x97) & 0xfe;
      *(byte *)((int)param_1 + 0x26f) = *(byte *)((int)param_1 + 0x26f) & 0x7f;
      *param_1 = *param_1 & 0xffffffbd;
    }
  }
  if (*(char *)((int)param_1 + 6) != '\0') {
    *(undefined1 *)((int)param_1 + 6) = 0;
    func_0x80077adc(0x4020001,param_1 + 10);
  }
  return;
}
