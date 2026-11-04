/* FUN_80026610
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80026610  body 0x80026610..0x800267a3  size 404 B
 * body sha256 5ccf27bc1254b7cedf99dbeb2437bc12fbd00eb79fb1b711d66d6d6094ed664b
 * provider record sha256 8cb654b00b8af32749f5d47f8565a3ecc87bf867d3c2dbdba209b1c76bb25f84
 * callees 10 direct (10 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80026610(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  FUN_800759d8();
  iVar6 = 0;
  FUN_80042a24();
  FUN_800823e0(0,0,0x400,0x200);
  FUN_800274e4(2,1);
  iVar5 = 0x10;
  iVar4 = 0;
  do {
    iVar3 = 0;
    iVar2 = 0xc;
    iVar1 = iVar4;
    do {
      *(undefined2 *)((int)&DAT_800e9198 + iVar1) = 0;
      *(undefined2 *)((int)&DAT_800e919a + iVar1) = 0;
      *(undefined2 *)((int)&DAT_800e919c + iVar1) = 0x140;
      *(undefined2 *)((int)&DAT_800e919e + iVar1) = 0xf0;
      FUN_8004789c(&DAT_800e9174 + iVar2 + iVar5,0,0,0);
      iVar2 = iVar2 + 0x10;
      iVar3 = iVar3 + 1;
      iVar1 = iVar1 + 0x10;
    } while (iVar3 < 2);
    iVar5 = iVar5 + 0x2c;
    iVar6 = iVar6 + 1;
    iVar4 = iVar4 + 0x2c;
  } while (iVar6 < 4);
  FUN_80031ab0();
  FUN_8004cd88(1);
  FUN_800479c8(DAT_800c52dc + 0xf400,&DAT_8010b2bc,0x14d3,0);
  DAT_800e9241 = '\0';
  FUN_8004cd54(1,FUN_80027a80);
  while (DAT_800e9241 == '\0') {
    FUN_8004cd88(1);
  }
  DAT_800e10ec = DAT_800e10ec | 2;
  overlay_slot_reader_b(1);
  return;
}
