/* FUN_80062930
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80062930  body 0x80062930..0x80062b7f  size 592 B
 * body sha256 149b411ab8841f85fadd8fe264784594f374978e74e134435508c8a7ce45e1ca
 * provider record sha256 fb04589cd4e1000f41292f227e233495673e68ac4a853f3fd80194f929dc2818
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80062930(void)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  ushort *puVar4;
  undefined4 *puVar5;
  int iVar6;
  float fVar7;
  undefined8 uVar8;
  float fVar9;
  undefined8 uVar10;
  
  FUN_80043620();
  uVar10 = 0x3f892492;
  if (((_DAT_80139e18 != 0) && ((DAT_800e10ec & 0x40000000) != 0)) &&
     (iVar3 = (int)DAT_800e8cac, *(int *)(iVar3 * 0x20 + *(int *)(DAT_800df92c + 0x24) + 0x1c) != -1
     )) {
    puVar5 = (undefined4 *)&DAT_80139bf0;
    uVar8 = 0x4f000000;
    for (iVar6 = 0; iVar6 < _DAT_80139dfc; iVar6 = iVar6 + 1) {
      puVar4 = (ushort *)*puVar5;
      if (puVar4 != (ushort *)0x0) {
        iVar2 = FUN_800837ac(&DAT_800e8db4 + iVar3 * 4,*puVar4 & 0x7fff);
        if (iVar2 != 0) {
          uVar1 = puVar4[4];
          _DAT_80139e04 = (uint)uVar1;
          DAT_80111180 = (undefined1)uVar1;
          DAT_8011117c = puVar4[1] + (uVar1 & 0xff);
          _DAT_80139e08 = (uint)puVar4[5];
          DAT_80111189 = (undefined1)puVar4[5];
          fVar7 = (float)(int)((int)(short)puVar4[2] + (_DAT_80139e08 & 0xff)) * (float)uVar10;
          fVar9 = (float)uVar8;
          if (fVar7 < fVar9) {
            DAT_8011118e = (undefined2)(int)fVar7;
          }
          else {
            DAT_8011118e = (undefined2)(int)(fVar7 - fVar9);
          }
          DAT_80111174 = puVar4[1];
          DAT_8011118a = puVar4[3];
          fVar7 = (float)(int)(short)puVar4[2] * (float)uVar10;
          if (fVar7 < fVar9) {
            DAT_80111176 = (undefined2)(int)fVar7;
          }
          else {
            DAT_80111176 = (undefined2)(int)(fVar7 - fVar9);
          }
          DAT_8011117e = DAT_80111176;
          DAT_80111184 = DAT_80111174;
          DAT_80111186 = DAT_8011118e;
          DAT_8011118c = DAT_8011117c;
          DAT_80111190 = DAT_80111180;
          DAT_80111191 = DAT_80111189;
          _DAT_80139e14 = (int)puVar4 + 0x13U & 0xfffffff8;
          DAT_800df8b4 = FUN_80044fdc(DAT_800df8b4,&DAT_80111170,1);
        }
      }
      puVar5 = puVar5 + 1;
    }
  }
  return;
}
